#ifndef HTMLFORMEVENT_H
#define HTMLFORMEVENT_H

#include "event.h"

class HtmlFormEvent:public Event{


public:
  static hash_map<string,string> _type;
  static hash_map<string,string>& listEventType();
private:
  static void initEventType();


};


#endif

