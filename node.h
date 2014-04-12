#ifndef   V8_NODE_H
#define   V8_NODE_H

#include "common.h"
/*
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <string>
*/
#include "namenodemap.h"
#include "embedObject.h"
#include "event/eventTarget.h"
#include "event/event.h"

//using namespace v8;
//using namespace std;

class Node;


typedef Node* NodePtr;

//class Node : public embedObject{
class Node : public EventTarget{


//typedef emun{NOTYPE_NODE,ELEMENT_NODE,ATTRIBUTE_NODE,TEXT_NODE,CDATA_SECTION_NODE,ENTITY_REFERENCE_NODE,ENTITY_NODE,PROCESSING_INSTRUCTION_NODE,COMMENT_NODE,DOCUMENT_NODE,DOCUMENT_TYPE_NODE,DOCUMENT_FRAGMENT_NODE,NOTATION_NODE} NODETYPE;
typedef enum{NOT_SAME_DOCUMENT=1,AFTER_POSITION=2,BEFORE_POSITION=4,FIRST_INSIDE_POSITION=8,
             SECOND_INSIDE_POSITION=10,NO_RELATION_SHIP_OR_TOWATTR_ON_SAME_ELEMENT=20} DOCUMENTPOSITION;

public:
   Node():EventTarget(EventTarget::_supportAllEvent){};
   Node(void* node,xmlElementType nodetype);
   Node(void* node,xmlElementType nodetype,unsigned short int supportEventType);
   //Node(string &text);
   virtual ~Node();

protected:
   virtual bool dispatchEventToParent(void * eptr);
   virtual void defaultAction();

public:
   NameNodeMapPtr getAttributes();
   vector<NodePtr> getChildNodes();
   NodePtr getFirstChild();
   NodePtr getLastChild();
   string   getLocalName();
   string   getNamespaceURI();  
   NodePtr getNextSibling();
   string   getNodeName();
   xmlElementType getNodeType();
   string   getNodeValue();
   void   setNodeValue(const char *value);
   //NodePtr getOwnerDocument();
   NodePtr  getParentNode();
   string   getPrefix();
   NodePtr  getPreviousSibling();
   string   getTextContent();
   void   setTextContent(const char*value);


   void addNextSibling(NodePtr node);


public:
   void appendChild(NodePtr child);
   NodePtr cloneNode(bool clone_descendants);
   //DOCUMENTPOSITION compareDocumentPosition(NodePtr seconeNode);
   bool hasAttributes();
   bool hasChildNodes();
   NodePtr insertBefore(NodePtr newNode,NodePtr childNode);
   bool isDefaultNamespace(const char *namespaceuri);
   bool isEqualNode(NodePtr node);
   bool isSameNode(NodePtr node);
   NodePtr removeChild(NodePtr node);
   NodePtr replaceChild(NodePtr newnode,NodePtr oldnode);

public:
   void *getXmlNodePtr(){return _node;};
   xmlElementType getNodetype(){return _nodetype;};
protected:
   void* _node;
   xmlElementType _nodetype;



public:
   v8::Handle<v8::ObjectTemplate> embed();

//below code is wrap c++ code for javascript,so javascript can invoke them.
public:
   static Handle<Value> GetAttribute(Local<String> property,const AccessorInfo &info);
   static void SetAttribute(Local<String> property, Local<Value> value,const AccessorInfo& info);


   static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
   static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(tagName)//Returns the tag name of the element      1

DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(attributes)//Returns a collection of a node's attributes 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(baseURI)//Returns the absolute base URI of a node 	3
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(childNodes)//Returns a NodeList of child nodes for a node 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(firstChild)//Returns the first child of a node 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(lastChild)//Returns the last child of a node 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(localName)//Returns the local part of the name of a node 	2
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(namespaceURI)//Returns the namespace URI of a node 	2
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(nextSibling)//Returns the next node at the same node tree level 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(nodeName)//Returns the name of a node, depending on its type 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(nodeType)//Returns the type of a node 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(nodeValue)//Sets or returns the value of a node, depending on its type 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(ownerDocument)//Returns the root element (document object) for a node 	2
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(parentNode)//Returns the parent node of a node 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(prefix)//Sets or returns the namespace prefix of a node 	2
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(previousSibling)//Returns the previous node at the same node tree level 	1
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(textContent)//Sets or returns the textual content of a node and its descendants 	3


DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(appendChild)//) 	Adds a new child node, to the specified node, as the last child node 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(cloneNode)//) 	Clones a node 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(compareDocumentPosition)//) 	Compares the document position of two nodes 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getFeature)//feature,version) 	Returns a DOM object which implements the specialized APIs of the specified feature and version 	3
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getUserData)//key) 	Returns the object associated to a key on a this node. The object must first have been set to this node by calling setUserData with the same key 	3
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(hasAttributes)//) 	Returns true if a node has any attributes, otherwise it returns false 	2
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(hasChildNodes)//) 	Returns true if a node has any child nodes, otherwise it returns false 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(insertBefore)//) 	Inserts a new child node before a specified, existing, child node 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(isDefaultNamespace)//) 	Returns true if the specified namespaceURI is the default, otherwise false 	3
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(isEqualNode)//) 	Checks if two nodes are equal 	3
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(isSameNode)//) 	Checks if two nodes are the same node 	3
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(isSupported)//) 	Returns true if a specified feature is supported on a node, otherwise false 	2
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(lookupNamespaceURI)//) 	Returns the namespace URI matching a specified prefix 	3
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(lookupPrefix)//) 	Returns the prefix matching a specified namespace URI 	3
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(normalize)//) 	Joins adjacent text nodes and removes empty text nodes 	2
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(removeChild)//) 	Removes a child node 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(replaceChild)//) 	Replaces a child node 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(setUserData)//key,data,handler) 	Associates an object to a key on a node 	3 
public:
  static  string _try;
public:
  static  v8::Handle<v8::Value> appendChild(const v8::Arguments& args);
  static  v8::Handle<v8::Value> cloneNode(const v8::Arguments& args);
  static  v8::Handle<v8::Value> compareDocumentPosition(const v8::Arguments& args);
  static  v8::Handle<v8::Value> getFeature(const v8::Arguments& args);
  static  v8::Handle<v8::Value> getUserData(const v8::Arguments& args);
  static  v8::Handle<v8::Value> hasAttributes(const v8::Arguments& args);
  static  v8::Handle<v8::Value> hasChildNodes(const v8::Arguments& args);
  static  v8::Handle<v8::Value> insertBefore(const v8::Arguments& args);
  static  v8::Handle<v8::Value> isDefaultNamespace(const v8::Arguments& args);
  static  v8::Handle<v8::Value> isEqualNode(const v8::Arguments& args);
  static  v8::Handle<v8::Value> isSameNode(const v8::Arguments& args);
  static  v8::Handle<v8::Value> isSupported(const v8::Arguments& args);
  static  v8::Handle<v8::Value> lookupNamespaceURI(const v8::Arguments& args);
  static  v8::Handle<v8::Value> lookupPrefix(const v8::Arguments& args);
  static  v8::Handle<v8::Value> normalize(const v8::Arguments& args);
  static  v8::Handle<v8::Value> removeChild(const v8::Arguments& args);
  static  v8::Handle<v8::Value> replaceChild(const v8::Arguments& args);
  static  v8::Handle<v8::Value> setUserData(const v8::Arguments& args);


};

#endif
