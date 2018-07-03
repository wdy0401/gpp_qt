#ifndef WFUNCTION
#define WFUNCTION
#include<list>
#include<deque>
#include<string>
class wfunction
{
public:
	static std::string itos(long);
	static std::string ftos(double);
	//对于splitstring 返回时list还是vector的问题
	//如果使用list 对于长度比较大的字符串会比较合适 因为list不需要连续空间
	//如果使用vector 对于使用此函数的用户会比较方便 便于查找第几个
	//如果使用模板 则无法只包含头文件即可使用 
	//三者看下来 使用vector比较合适  
	//鉴于尚无修改之必要  待到有需要时再做修改 届时需要同时修改相关文件 find grep 
	//用deque可以解决此问题 人不学不知理
	//用此命令查找需要修改的代码 find . -name "*.cpp" | xargs -i  grep "deque<string>" {}| grep splitstring |wc -l
	// replace all list with deque 
	//find . -name "*.cpp" | xargs -i  perl -p -i -e 's/#include<list>/#include<list>\n#include<deque>/;s/list<string>/deque<string>/;s/std::list<std::string>/std::deque<std::string>/;s/std::list<string>/std::deque<string>/;' {}
	//受限于window 一定会有个bak或者之类指定扩展名的文件出现


    static std::deque<std::string> splitstring(const std::string & );
    static std::deque<std::string> splitstring(const std::string & ,const std::string &);
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
