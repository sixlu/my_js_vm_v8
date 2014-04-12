#include "htmlFormEvent.h"

hash_map<string,string> HtmlFormEvent::_type;




hash_map<string,string>& HtmlFormEvent::listEventType(){

   if(HtmlFormEvent::_type.size()==0){
        HtmlFormEvent::initEventType();
   }   
   
   return HtmlFormEvent::_type;

}

void HtmlFormEvent::initEventType(){
   HtmlFormEvent::_type["select"]="onselect";
   HtmlFormEvent::_type["change"]="onchange";
   HtmlFormEvent::_type["submit"]="onsubmit";
   HtmlFormEvent::_type["reset"]="onreset";
   HtmlFormEvent::_type["focus"]="onfocus";
   HtmlFormEvent::_type["blur"]="onblur";

   Event::_eventAttributeToType["onselect"]="select";
   Event::_eventAttributeToType["onchange"]="change";
   Event::_eventAttributeToType["onsubmit"]="submit";
   Event::_eventAttributeToType["onreset"]="reset";
   Event::_eventAttributeToType["onfocus"]="focus";
   Event::_eventAttributeToType["onblur"]="blur";


}
