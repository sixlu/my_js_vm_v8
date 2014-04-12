

#include <v8.h>
#include <string>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <vector>
#include <unistd.h>
using namespace v8;
using namespace std;

static int x=0;
static Handle<ObjectTemplate> point_templ;// = v8::Undefined();
//static Local<Function> g_jscallbackfunc;
static string onload_function_javascript_string = "function(){print('ddd');}";

const char* ToCString(const v8::String::Utf8Value& value) {
  return *value ? *value : "<string conversion failed>";
}
class Timer;
typedef Timer* TimerPtr;
class Timer{


public:
   Timer(){};
   Timer(long long int timeout,bool isInterval);


   bool isTimeout();
   bool isInterval(){return _isInterval;};

   virtual  void deal()=0;

public:
   static void handle(long long int min_interval);
   static long long int getCurrentMilliSecond();
  
private:
   long long int _beginTime;
   long long int _timeout;
   bool _isInterval;

public:
   static vector<TimerPtr> _timers;
};

class JsTimer;
typedef JsTimer* JsTimerPtr;
class JsTimer:public Timer{

private:
   JsTimer(){};
   JsTimer(long long int timeout,bool isInterval,Local<v8::Function> &func);
public:
   
   virtual  void deal();

public:
   static JsTimerPtr New(long long int timeout,bool isInterval,Local<v8::Function> &func);
private:
  
   Local<v8::Function> _func;
};


vector<TimerPtr> Timer::_timers;

Timer::Timer(long long int timeout,bool isInterval){
    _beginTime=Timer::getCurrentMilliSecond();
    _timeout=timeout;
    _isInterval=isInterval;

}




bool Timer::isTimeout(){
   long long int cur_millisecond = Timer::getCurrentMilliSecond();
   //printf("cur_millisecond[%lld],_beginTime[%lld],_timeout[%lld]\n",cur_millisecond,_beginTime,_timeout);
   if (cur_millisecond-_beginTime>=_timeout){
      _beginTime = cur_millisecond;
      return true;
   }else
      return false;

}

long long int Timer::getCurrentMilliSecond(){

   struct timeval cur_tv;
   struct timezone timezone;


   gettimeofday(&cur_tv,NULL);
   long long int cur_millisecond= cur_tv.tv_sec*1000+ cur_tv.tv_usec/1000;
   return cur_millisecond;
}

void Timer::handle(long long int min_interval){
 
   fd_set rfds;
   struct timeval tv; 
   int retval;
  
   /* Watch stdin (fd 0) to see when it has input. */
   FD_ZERO(&rfds);
   FD_SET(0, &rfds);

   /* Wait up to five seconds. */
   while(1 ){

     tv.tv_sec = 0;
     tv.tv_usec = min_interval*1000;
     retval = select(0, NULL, NULL, NULL, &tv);
     long long int cur_millisecond= Timer::getCurrentMilliSecond();
     printf("beating [%lld],Timer::_timers.size()=%ld\n",cur_millisecond,Timer::_timers.size());
     vector<TimerPtr>::iterator itr = Timer::_timers.begin();
     while(itr!=Timer::_timers.end()){
       if((*itr)->isTimeout()){
          (*itr)->deal();
          if (!(*itr)->isInterval()){
              itr=Timer::_timers.erase(itr);
              continue;
          }
       }
       itr++;   
     }
     printf("static x=%d\n",x); 
   } 



}

JsTimer::JsTimer(long long int timeout,bool isInterval,Local<v8::Function> &func):Timer(timeout,isInterval){

    _func=Local<v8::Function>::Cast(func->Clone());
    //_func=func;
}


void JsTimer::deal(){
   printf("JsTimer::deal\n");    
   _func=Local<v8::Function>::Cast(_func->Clone());
   Local<Context> context= v8::Context::GetCurrent();
   _func->Call(context->Global(), 0, NULL);

}


JsTimerPtr JsTimer::New(long long int timeout,bool isInterval,Local<v8::Function> &func){

    JsTimerPtr jstimer= new JsTimer(timeout,isInterval,func);
    Timer::_timers.push_back(jstimer);
    return jstimer;

}



 


class Point {
   public:
    Point(int x, int y,int width,int height,const char *name) : x_(x), y_(y) {
        name_=name;
    }
    int x_, y_;
    string name_;
  
    static v8::Handle<v8::Value> setName(const v8::Arguments& args){
       Local<Object> self = args.Holder();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       Point* p =(Point*) wrap->Value();
       if(p){
           v8::String::Utf8Value str(args[0]);
           p->name_=ToCString(str);
       }
    }

    static v8::Handle<v8::Value> getName(const v8::Arguments& args){
       Local<Object> self = args.Holder();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       Point* p =(Point*) wrap->Value();
       if(p){
           return v8::String::New(p->name_.c_str());
       }
       
    }
 
    static v8::Handle<v8::Value> joinName(const v8::Arguments& args){
       Local<Object> self = args.Holder();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       Point* p =(Point*) wrap->Value();
       if(p){

           Local<Object> otherpoint = args[0]->ToObject() ;
           Local<External> wrap_otherpoint = Local<External>::Cast(otherpoint->GetInternalField(0));
           Point* otherpoint_ptr = (Point*)wrap_otherpoint->Value();

           string joinname=p->name_ + otherpoint_ptr->name_;
           return v8::String::New(joinname.c_str());
       }
       
    }

    static v8::Handle<v8::Value> setTimeout(const v8::Arguments& args) {
    
       Local<Object> self = args.Holder();
       Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
       Point* p =(Point*) wrap->Value();
       if(p&& args.Length()>=2){
                   
           //Local<Object> temp = args[0]->ToObject()->Clone();
           Local<Function> jscallbackfunc = Local<v8::Function>::Cast(args[0]);
           int timeout= args[1]->Int32Value();           
           JsTimer::New(timeout,true,jscallbackfunc);
           
           //Local<Function> jscallbackfunc = Local<v8::Function>::Cast(args[0]);
           //g_jscallbackfunc = Local<v8::Function>::Cast(jscallbackfunc->Clone());
           /*g_jscallbackfunc =  Local<v8::Function>::Cast(args[0]); */
       }
       
  
    }
    
};


// Convert a JavaScript string to a std::string.  To not bother too
// much with string encodings we just use ascii.
string ObjectToString(Local<Value> value) {
  String::Utf8Value utf8_value(value);
  return string(*utf8_value);
}

static Handle<Value> MapGet(Local<String> name, const AccessorInfo& info){
   
     string c_name = ObjectToString(name);
     printf("MapGet %s\n",c_name.c_str());
     return Integer::New(x);

}
static Handle<Value> MapSet(Local<String> name,
                              Local<Value> value,
                              const AccessorInfo& info){
     string c_name = ObjectToString(name);
     printf("MapSet %s\n",c_name.c_str());
     x = value->Int32Value();
}

static Handle<Integer> MapSearch(Local<String> property,
                                              const AccessorInfo& info){

     string c_name = ObjectToString(property);
     printf("MapSearch %s\n",c_name.c_str());
}


Handle<Value> GetPointX(Local<String> property,
                          const AccessorInfo &info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    void* ptr = wrap->Value();
    int value = static_cast<Point*>(ptr)->x_;
    return Integer::New(value);
}
  
void SetPointX(Local<String> property, Local<Value> value,
                 const AccessorInfo& info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    void* ptr = wrap->Value();
    static_cast<Point*>(ptr)->x_ = value->Int32Value();
}


void initPointTemplate(){
 
    point_templ = ObjectTemplate::New();
    point_templ->SetInternalFieldCount(1);
    point_templ->SetAccessor(String::New("x"), GetPointX, SetPointX);
    point_templ->Set(String::New("setName"),v8::FunctionTemplate::New(Point::setName));
    point_templ->Set(String::New("getName"),v8::FunctionTemplate::New(Point::getName));
    point_templ->Set(String::New("joinName"),v8::FunctionTemplate::New(Point::joinName));
    point_templ->Set(String::New("setTimeout"),v8::FunctionTemplate::New(Point::setTimeout));
    //point_templ.SetAccessor(String::New("y"), GetPointY, SetPointY);
    //point_templ->Set(v8::String::New("navigator"), navigator_templ);
    //point_templ->SetNamedPropertyHandler(MapGet, MapSet,MapSearch);

    //cavnas_templ  = ObjectTemplate::New();
    

}



v8::Handle<v8::Value> jsPoint(const v8::Arguments& args) {
    //if (point_templ == v8::Undefined())
    //   initPointTemplate();
    Point* p = new Point(1,2,100,200,"luyang");
    Local<Object> obj = point_templ->NewInstance();
    obj->SetInternalField(0, External::New(p));
    return obj;
}

v8::Handle<v8::Value> produce_function(const v8::Arguments& args) {
  
     Handle<String> source = String::New(onload_function_javascript_string.c_str()); 
     //Handle<Script> script = Script::Compile(source); 
     //return script->Id();
     Function* function =  Function::Cast((*source));
     return Handle<Function>(function);
}

// Reads a file into a v8 string.
Handle<String> ReadFile(const string& name) {
  FILE* file = fopen(name.c_str(), "rb");
  if (file == NULL) return Handle<String>();

  fseek(file, 0, SEEK_END);
  int size = ftell(file);
  rewind(file);

  char* chars = new char[size + 1];
  chars[size] = '\0';
  for (int i = 0; i < size;) {
    int read = static_cast<int>(fread(&chars[i], 1, size - i, file));
    i += read;
  }
  fclose(file);
  Handle<String> result = String::New(chars, size);
  delete[] chars;
  return result;
}

v8::Handle<v8::Value> Print(const v8::Arguments& args) {
  bool first = true;
  for (int i = 0; i < args.Length(); i++) {
    /*v8::HandleScope handle_scope(args.GetIsolate());
    if (first) {
      first = false;
    } else {
      printf(" ");
    }
    */
    v8::String::Utf8Value str(args[i]);
    const char* cstr = ToCString(str);
    printf("%s", cstr);
  }
  /*
  printf("\n");
  fflush(stdout);
  */
  return v8::Undefined();

}





Handle<Value> XGetter(Local<String> property, 
                        const AccessorInfo& info) {
    return Integer::New(x);
  }


void XSetter(Local<String> property, Local<Value> value,
               const AccessorInfo& info) {
    x = value->Int32Value();
}

v8::Handle<v8::Value> getPoints(const v8::Arguments& args) {
    int count=10;
    Local<Array> points = v8::Array::New(count);
    int i=0;
    while(i<count){
      Point* p = new Point(100+i,2,100,200,"luyang");
      Local<Object> obj = point_templ->NewInstance();
      obj->SetInternalField(0, External::New(p));
      points->Set(i, obj);
      i++;
    }
    return points;
}



Persistent<Context> createContext(){
  
  Handle<ObjectTemplate> global_templ = ObjectTemplate::New();
  Handle<ObjectTemplate> navigator_templ = ObjectTemplate::New();
  
  navigator_templ->SetAccessor(String::New("x"), XGetter, XSetter);
  global_templ->Set(v8::String::New("navigator"), navigator_templ);

  global_templ->Set(v8::String::New("print"), v8::FunctionTemplate::New(Print));
  global_templ->Set(v8::String::New("jsPoint"), v8::FunctionTemplate::New(jsPoint));
  global_templ->Set(v8::String::New("produce_function"), v8::FunctionTemplate::New(produce_function));
  global_templ->Set(v8::String::New("getPoints"), v8::FunctionTemplate::New(getPoints));
  Persistent<Context> context = Context::New(NULL, global_templ);
  return context;
}


int main(int argc,char** argv){
 
   // Create a stack-allocated handle scope.
  HandleScope handle_scope;

  initPointTemplate();  
  Persistent<Context> context=createContext();
  
  Context::Scope context_scope(context);

  Handle<String> source = ReadFile(argv[1]);//String::New(argv[1]);

  // Compile the source code.
  Handle<Script> script = Script::Compile(source);

  // Run the script to get the result.
  Handle<Value> result = script->Run();
  
  Timer::handle(50);
  /*
  //Local<Context> cur_context= v8::Context::GetCurrent();
  //g_jscallbackfunc->Call(cur_context->Global(), 0, NULL);
  Local<Context> t_context= v8::Context::GetCurrent();

  while(1){
    g_jscallbackfunc=Local<v8::Function>::Cast(g_jscallbackfunc->Clone());
    g_jscallbackfunc->Call(t_context->Global(), 0, NULL);
    sleep(2);
  }
  */
  // Dispose the persistent context.
  context.Dispose();

  // Convert the result to an ASCII string and print it.
  //String::AsciiValue ascii(result);
  //printf("%s\n", *ascii);



  return 0;

}
