#ifndef  V8_ICHROME_H
#define  V8_ICHROME_H

#include "common.h"

#include "window.h"
#include "navigator.h"
#include "document.h"





class IChrome{

public:
   IChrome(string &url);

private:
   WindowPtr _window;
   NavigatorPtr _navigator;
   DocumentPtr _doc;

};

#endif
