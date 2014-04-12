#ifndef  v8_NAMENODEMAP_H
#define  v8_NAMENODEMAP_H

#include "common.h"
#include <string>
#include <vector>

#include "embedObject.h"
//#include "node.h"

using namespace v8;
using namespace std;

class NameNodeMap;

typedef NameNodeMap * NameNodeMapPtr;


class NameNodeMap:public embedObject{

public:
   NameNodeMap();
   virtual ~NameNodeMap();

public:
   v8::Handle<v8::ObjectTemplate> embed();

public:
  static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
  static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

  static    v8::Handle<v8::Value> getNamedItem(const v8::Arguments& args); 
  static    v8::Handle<v8::Value> getNamedItemNS(const v8::Arguments& args); 
  static    v8::Handle<v8::Value> item(const v8::Arguments& args); 
  static    v8::Handle<v8::Value> removeNamedItem(const v8::Arguments& args); 
  static    v8::Handle<v8::Value> removeNamedItemNS(const v8::Arguments& args); 
  static    v8::Handle<v8::Value> setNamedItem(const v8::Arguments& args); 
  static    v8::Handle<v8::Value> setNamedItemNS(const v8::Arguments& args); 

public:
   void addItem(void* node);
   void* getNameItem(string &name);
   void* getItemByIndex(int index);
   void setItem(void* node);
   int  count(){_nodes.size();};
private:
   vector<void*> _nodes;

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(length)// 	Returns the number of nodes in the list



DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getNamedItem)//) 	Returns the specified node )//by name) 	5 	1 	9 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getNamedItemNS)//) 	Returns the specified node )//by name and namespace) 	  	  	9 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(item)//) 	Returns the node at the specified index 	5 	1 	9 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(removeNamedItem)//) 	Removes the specified node )//by name) 	6 	1 	9 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(removeNamedItemNS)//) 	Removes the specified node )//by name and namespace) 	  	  	9 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setNamedItem)//) 	Sets the specified node )//by name) 	  	  	9 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setNamedItemNS)//) 	Sets the specified node )//by name and namespace) 	  	  	9 	Yes


};



#endif
