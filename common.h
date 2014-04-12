#ifndef  V8_COMMON_H
#define  V8_COMMON_H

#include <v8.h>
#include <libxml/HTMLparser.h>
#include <libxml/HTMLtree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>


#include <string.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <regex.h>

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <list>
#include <ext/hash_map>
#include <deque>


using namespace std;
using namespace v8;

using namespace __gnu_cxx;

/** BEGIN FIX **/
#ifndef HASH_FIX
#define HASH_FIX
namespace  __gnu_cxx    
{    
        template<> struct hash< std::string >    
        {    
                size_t operator()( const std::string& x ) const    
                {    
                        return hash< const char* >()( x.c_str() );    
                }    
        };    
} 
#endif 

/** END FIX **/


/*

class embedObject;
class Timer;
class JsTimer;
class Anchor;
class Area;
class Attr;
class Base;
class Body;
class Button;
class Node;
class Document;
class DomJsParser;
class Element;
class Form;
class Frame;
class Frameset;
class HTMLElement;
class IChrome;
class Image;
class Input;
class JsTimer;
class Link;
class Meta;
class NameNodeMap;
class Navigator;
class HtmlObject;
class Option;
class Select;
class Style;
class Table;
class Td;
class Textarea;
class Timer;
class Tr;
class Window;

typedef embedObject* embedObjectPtr;
typedef Timer* TimerPtr;
typedef JsTimer* JsTimerPtr;
typedef Anchor* AnchorPtr;
typedef Area* AreaPtr;
typedef Attr* AttrPtr;
typedef Base* BasePtr;
typedef Body* BodyPtr;
typedef Button* ButtonPtr;
typedef Node* NodePtr;
typedef Document* DocumentPtr;
typedef DomJsParser* DomJsParserPtr;
typedef Element* ElementPtr;
typedef Form* FormPtr;
typedef Frame* FramePtr;
typedef Frameset* FramesetPtr;
typedef HTMLElement* HTMLElementPtr;
typedef IChrome* IChromePtr;
typedef Image* ImagePtr;
typedef Input* InputPtr;
typedef JsTimer* JsTimerPtr;
typedef Link* LinkPtr;
typedef Meta* MetaPtr;
typedef NameNodeMap* NameNodeMapPtr;
typedef Navigator* NavigatorPtr;
typedef HtmlObject* HtmlObjectPtr;
typedef Option* OptionPtr;
typedef Select* SelectPtr;
typedef Style* StylePtr;
typedef Table* TablePtr;
typedef Td* TdPtr;
typedef Textarea* TextareaPtr;
typedef Timer* TimerPtr;
typedef Tr* TrPtr;
typedef Window* WindowPtr;

#include "embedObject.h"
#include "node.h"
#include "element.h"
#include "htmlElement.h"

*/

#endif 
