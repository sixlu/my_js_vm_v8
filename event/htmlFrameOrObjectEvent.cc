#include "htmlFrameOrObjectEvent.h"

hash_map<string,string> HtmlFrameOrObjectEvent::_type;




hash_map<string,string>& HtmlFrameOrObjectEvent::listEventType(){

   if(HtmlFrameOrObjectEvent::_type.size()==0){
        HtmlFrameOrObjectEvent::initEventType();
   }   
   
   return HtmlFrameOrObjectEvent::_type;

}

void HtmlFrameOrObjectEvent::initEventType(){

   HtmlFrameOrObjectEvent::_type["load"]="onload";
   HtmlFrameOrObjectEvent::_type["unload"]="onunload";
   HtmlFrameOrObjectEvent::_type["abort"]="onabort";
   HtmlFrameOrObjectEvent::_type["error"]="onerror";
   HtmlFrameOrObjectEvent::_type["resize"]="onresize";
   HtmlFrameOrObjectEvent::_type["scroll"]="onscroll";

   Event::_eventAttributeToType["onload"]="load";
   Event::_eventAttributeToType["onunload"]="unload";
   Event::_eventAttributeToType["onabort"]="abort";
   Event::_eventAttributeToType["onerror"]="error";
   Event::_eventAttributeToType["onresize"]="resize";
   Event::_eventAttributeToType["onscroll"]="scroll";

}
