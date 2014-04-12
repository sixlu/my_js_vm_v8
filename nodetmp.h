#ifndef   V8_NODETMP_H
#define   V8_NODETMP_H

#include "common.h"
/*
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <string>
*/
//#include "namenodemap.h"
//#include "embedObject.h"
//#include "document.h"

//using namespace v8;
//using namespace std;

//class Node;


//typedef Node* NodePtr;

class NodeTmp {//: public embedObject{



public:
   NodeTmp(){};
   NodeTmp(void* node,xmlElementType nodetype);
   //Node(string &text);
   virtual ~NodeTmp();

protected:
   void* _node;
   xmlElementType _nodetype;



public:
  static  string _try;

};

#endif
