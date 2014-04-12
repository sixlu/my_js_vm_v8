
#include <stdlib.h>
#include <utils.h>

int IChrome::Utils::split(string &str,string &delimiter,vector<string> &tokens){
     
     if(str.size() && delimiter.size()){
        int token_index =0;
        int begin_search_index=0;
        while((token_index=str.find(delimiter,begin_search_index))!=string::npos){
            tokens.push_back(str.substr(begin_search_index,(token_index-begin_search_index)));
            begin_search_index = token_index+1;
        }

        if(begin_search_index< str.size()){
             tokens.push_back(str.substr(begin_search_index));

        }
             

        return 0;
     }else
        return -1;
}

int IChrome::Utils::str_regx_match(string &str,string &regx,vector<string> &matchs){
  
     if (str.size() && regx.size()){

	     regex_t reg;
	     regmatch_t pm[1000];
	     int ret=0;
	     char ebuf[128];
	     const size_t nmatch = 100;
	     int z;
	     z = regcomp(&reg, regx.c_str(), REG_EXTENDED|REG_ICASE);
	     if (z != 0)
	     {
		 regerror(z, &reg, ebuf, sizeof(ebuf));
		 //http_log(LOG_DEBUG, "Match error:%s\n",ebuf);
		 //cout<<ebuf<<": pattern "<<PATTERN<<endl;
		 printf("[%s]Match[%s] error:%s\n",str.c_str(),regx.c_str(),ebuf);
	      }

	      z = regexec(&reg, str.c_str() , nmatch, pm, 0);
	      if (z == REG_NOMATCH)
	      {
		 //cout<<"No Match!"<<endl;
		 //http_log(LOG_DEBUG, "No Match.\n",ebuf);
		 printf("[%s]No Match[%s]\n",str.c_str(),regx.c_str());
	      }
	      else if (z != 0)
	      {
		 regerror(z, &reg, ebuf, sizeof(ebuf));
		 //cout<<ebuf<<": regcom - "<<PATTERN<<endl;
		 //http_log(LOG_DEBUG, "Match error:%s\n",ebuf);
		 printf("[%s]Match[%s] error:%s\n",str.c_str(),regx.c_str(),ebuf);
	      }
	      else if (z == 0)
	      {
                 regmatch_t *cur_pm=pm;
                 while(cur_pm->rm_so!=-1){
                    int matchstr_len = cur_pm->rm_eo - cur_pm->rm_so+1; 
                    string match_str= str.substr(cur_pm->rm_eo,matchstr_len);
                    matchs.push_back(match_str); 
                    cur_pm++;
                 }
		 ret=1;
	      }
	      regfree(&reg);
	      return ret;

     }else
       return -1;
  
}
