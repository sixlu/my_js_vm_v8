#ifndef   V8_NODELIST_H
#define   V8_NODELIST_H

#include "common.h"

#include "embedObject.h"

class NodeList: public embedObject{

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(length)// 	Returns the number of nodes in the collection


DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(item)//() 	Returns the node at the specified index in a node list

public:
   v8::Handle<v8::Value> item(const v8::Arguments& args);

}


#endif
