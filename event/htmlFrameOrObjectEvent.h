#ifndef HTMLFRAMEOROBJECT_H
#define HTMLFRAMEOROBJECT_H

#include "event.h"

class HtmlFrameOrObjectEvent:public Event{

public:
  static hash_map<string,string> _type;
  static hash_map<string,string>& listEventType();
private:
  static void initEventType();

};


#endif

