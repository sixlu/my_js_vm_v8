
#ifndef V8_UTILS_h
#define V8_UTILS_h

#include "common.h"
#include <string>
#include <vector>

using namespace std;


namespace IChrome{
class Utils{
public:
  static int split(string &str,string &delimiter,vector<string> &tokens); 
  static int str_regx_match(string &str,string &regx,vector<string> &matchs);
};

};

#endif
