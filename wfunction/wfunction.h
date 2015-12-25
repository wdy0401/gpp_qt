#ifndef WFUNCTION
#define WFUNCTION
#include<list>
#include<string>
class wfunction
{
public:
	static std::string itos(long);
	static std::string ftos(double);
    static std::list<std::string> splitstring(const std::string & );
    static std::list<std::string> splitstring(const std::string & ,const std::string &);
	static char * gbk2utf8(const char*);
	static char * utf82gbk(const char*);
    static std::string get_now_second();
    static int wmkdir(const std::string &);
    static std::string replacechar(const std::string & oldstr,const std::string & from,const std::string & to);

    //CTP
    static std::string joinquote(const std::string &);
	static char * ctp_time_char_convert(char *,int );
};
#endif
