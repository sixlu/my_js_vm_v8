#ifndef  V8_DOCUMENT_H
#define  V8_DOCUMENT_H

#include "common.h"
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <vector>

#include "node.h"
#include "anchor.h"
#include "body.h"
#include "form.h"
#include "image.h"
#include "htmlElement.h"
#include "attr.h"
#include "link.h"

using namespace std;


class Document;

typedef  Document*  DocumentPtr;



class Document : public Node{

public:
   #define PATHEXPRT_LEN 200 
   typedef enum{
       UNINITIALIZED,//- Has not started loading yet
       LOADING,// - Is loading
       INTERACTIVE,// - Has loaded enough and the user can interact with it
       COMPLETE// - Fully loaded
   }READYSTATE;
   typedef enum{
      PARSE_SUCCESS,
      PARSE_FAILURE 
   }PARSERESULT;

private:
      Document();
      Document(xmlDocPtr doc);
      Document(string &html_str,string &referrer,string &url,string &lastmodified,string &encoding,string &cookie);
public:
      virtual ~Document();
public:
      static DocumentPtr New(string &html_str,string &referrer,string &url,string &lastmodified,string &encoding,string &cookie); 
      //static Handle<V8::Array> Case(vector<HTMLElementPtr> &html_nodes);      
public:
      PARSERESULT parseHtml();
      vector<xmlNodePtr> getElementsByName(string &name);
      xmlNodePtr getElementById(string &id); 
      vector<xmlNodePtr> getElementsByTagName(string &tagname);

      vector<xmlNodePtr> getElementsByXPathExpr(string &xpath_expr);
public:
      vector<AnchorPtr> getanchors();
      BodyPtr getbody();
      string getcookie();
      string getdomain();
      vector<FormPtr> getforms();
      vector<ImagePtr> getimages();
      string getlastModified();
      vector<LinkPtr> getlinks();
      READYSTATE getreadyState();
      string getreferrer();
      string gettitle();
      void settitle(string &title);
      string getURL();

      template<class T,class TPtr> 
      static vector<TPtr> Case(vector<xmlNodePtr> xml_nodes){
           vector<TPtr> results;
           vector<xmlNodePtr>::iterator itr = xml_nodes.begin();
           while(itr!=xml_nodes.end()){
              xmlNodePtr xmlnode = (*itr);
              TPtr node = NULL;
              if(xmlnode->_private!=NULL){
                 node = (TPtr)xmlnode->_private;
              }else{
                 node = new T(xmlnode);
                 xmlnode->_private = node;
              }
              results.push_back(node);
              itr++;
           }
           return results;

      }
      
      template<class T,class TPtr>
      static  TPtr Case(xmlNodePtr xml_node){

          TPtr node = NULL;
          if(xml_node->_private!=NULL){
            
             node = (TPtr)xml_node->_private;
          }else{
             node = new T(xml_node);
             xml_node->_private=node;
          }
          return node;
      }
     
      template<class T,class TPtr>
      static  Handle<v8::Array> Case(vector<TPtr> html_nodes){

          Local<v8::Array> javascript_nodes = v8::Array::New(html_nodes.size());
          int i=0;
          while(i<html_nodes.size()){
             javascript_nodes->Set(i,html_nodes[i]->newInstance<TPtr>());
             i++;
          }   

          return javascript_nodes;
  
      }


public:
      v8::Handle<v8::ObjectTemplate> embed();
private:
      vector<AnchorPtr> _anchors; 	//Returns a collection of all the anchors in the document 	Yes
      BodyPtr _body;// 	Returns the body element of the document 	Yes
      string _cookie;// 	Returns all name/value pairs of cookies in the document 	Yes
      string _domain;// 	Returns the domain name of the server that loaded the document 	Yes
      vector<FormPtr> _forms;// 	Returns a collection of all the forms in the document 	Yes
      vector<ImagePtr> _images;// 	Returns a collection of all the images in the document 	Yes
      string _lastModified;// 	Returns the date and time the document was last modified 	No
      vector<LinkPtr> _links;// 	Returns a collection of all the links in the document 	Yes
      READYSTATE _readyState; //	Returns the (loading) status of the document 	No
      string _referrer;// 	Returns the URL of the document that loaded the current document 	Yes
      string _title;// 	Sets or returns the title of the document 	Yes
      string _URL;// 	Returns the full URL of the document
private:
      htmlDocPtr _doc;
      xmlXPathContextPtr _xpathCtx;

public:
        static Handle<Value> GetProperty(Local<String> property,const AccessorInfo &info);
        static void SetProperty(Local<String> property, Local<Value> value,const AccessorInfo& info);

public:
        static v8::Handle<v8::Value> close(const v8::Arguments& args);
        static v8::Handle<v8::Value> getElementsByName(const v8::Arguments& args);
        static v8::Handle<v8::Value> open(const v8::Arguments& args);
        static v8::Handle<v8::Value> write(const v8::Arguments& args);
        static v8::Handle<v8::Value> writeln(const v8::Arguments& args);
        static v8::Handle<v8::Value> createAttribute(const v8::Arguments& args);
        static v8::Handle<v8::Value> createComment(const v8::Arguments& args);
        static v8::Handle<v8::Value> createElement(const v8::Arguments& args);
        static v8::Handle<v8::Value> createTextNode(const v8::Arguments& args);
        static v8::Handle<v8::Value> getElementById(const v8::Arguments& args);
        static v8::Handle<v8::Value> getElementsByTagName(const v8::Arguments& args);



public:

DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(anchors)//Returns a collection of all the anchors in the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(applets)//Returns a collection of all the applets in the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(body)//Returns the body element of the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(cookie)//Returns all name/value pairs of cookies in the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(documentMode)//Returns the mode used by the browser to render the document 	No
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(domain)//Returns the domain name of the server that loaded the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(forms)//Returns a collection of all the forms in the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(images)//Returns a collection of all the images in the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(lastModified)//Returns the date and time the document was last modified 	No
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(links)//Returns a collection of all the links in the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(readyState)//Returns the (loading) status of the document 	No
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(referrer)//Returns the URL of the document that loaded the current document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(title)//Sets or returns the title of the document 	Yes
DECLARE_STATIC_JAVASCRIPT_ATTRI_NAME(URL)//Returns the full URL of the document




DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(close)// 	Closes the output stream previously opened with document.open() 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getElementsByName)// 	Accesses all elements with a specified name 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(open)// 	Opens an output stream to collect the output from document.write() or document.writeln() 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(write)// 	Writes HTML expressions or JavaScript code to a document 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(writeln)// 	Same as write(), but adds a newline character after each statement 	Yes
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(createAttribute)// 	Creates an attribute node
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(createComment)// 	Creates a Comment node with the specified text 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(createElement)// 	Creates an Element node 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(createTextNode)// 	Creates a Text node 	1
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getElementById)// 	Returns the element that has the ID attribute with the specified value 	2
DECLARE_STATIC_JAVASCRIPT_FUNCTION_NAME(getElementsByTagName)// 	Returns a NodeList containing all elements with the specified tagname 	1

};


#endif
