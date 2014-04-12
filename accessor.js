/*
navigator.x=10;
navigator.x++;
print(navigator.x);
var k=new print("dsafdsaf");
*/
var point1= new jsPoint();
point1.setName("firstluyang");
var point2= new jsPoint();
point2.setName("secondluyang");
print("point1.getName()="+point1.getName()+"\n");
print("point2.getName()="+point2.getName()+"\n");
var joinname=point1.joinName(point2);
print("point1.joinName(point2)="+joinname+"\n");
var points= getPoints();
var i=0;
while(i<10){
 print("point["+i+"]="+points[i].x+"\n");
 i++;
}
//Function.prototype.bind.toString();
//var k= Function.prototype.bind.toString().indexOf("native code") ? 1:0 ;
//print("k="+k+"\n");
print("point1.x="+point1.x+"\n");
function temp_function(){
   point1.x=point1.x+1;  
}

temp_function();

print("point1.x="+point1.x+"\n");
/*
point1.setTimeout(function(){
                     navigator.x=navigator.x+1;
                     print("navigator.x="+navigator.x+"\n");
                  },70);
*/
//var dealTimeOutFunction=function(){
//                     navigator.x=navigator.x+1;
//                     print("navigator.x="+navigator.x+"\n");
//                  };
//var dealTimeOutFunction = eval("function (){navigator.x=navigator.x+1;print(\"navigator.x=\"+navigator.x+\"\n\");}");
var dealTimeOutFunction = produce_function();

//point1.setTimeout(function(){dealTimeOutFunction()},70);
point1.setTimeout(dealTimeOutFunction,70);

/*
point2.x=999;
print("point1.x="+point1.x+"\n");
print("point2.x="+point2.x+"\n");
//print(point2.x.kk);
//point2.kk=10;
print(point2.kk);
print(navigator.x);
*/

