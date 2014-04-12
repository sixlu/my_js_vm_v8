#ifndef CONFIG_H
#define CONFIG_H

#include "common.h"
#include <string>
#include <map>

class Config{

public:
  static void load();
  static void fillRequestHeader(map<string,string> &request_headers);

public:
  static map<string,string> _request_headers_defaults;
};

#endif
