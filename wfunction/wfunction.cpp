#include"wfunction.h"
#include<map>
#include<list>
#include<string>
#include<iostream>
#include<sstream>
#include<Windows.h>
#include"time.h"
#include"stdio.h"
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#elif _LINUX
#include <stdarg.h>
#include <sys/stat.h>
#endif

#ifdef _WIN32
#define ACCESS _access
#define MKDIR(a) _mkdir((a))
#elif _LINUX
#define ACCESS access
#define MKDIR(a) mkdir((a),0755)
#endif

using namespace std;

string wfunction::itos(long i)
{
    ostringstream os;
    os<<i;
    string result;
    istringstream is(os.str());
	is>>result;
	return result; 
}

string wfunction::ftos(double f)
{
    ostringstream os;
	os<<f; 
    string result;
    istringstream is(os.str());
	is>>result;
	return result; 
}

list<string> wfunction::splitstring(std::string tp)
{
	return splitstring(tp,",");
}

list<string> wfunction::splitstring(std::string tp,const std::string & splitchar)
{
	list<string> ret;
	while(tp.size())
	{		
		int index=tp.find_first_of(splitchar);

		string tmpstring=tp.substr(0,index);
		ret.push_back(tmpstring);

		if(index==-1)
		{
			break;
		}
		tp=tp.substr(index+1);
	}
	return ret;
}

char * wfunction::utf82gbk(const char * strUtf8)
{
       int len=MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)strUtf8, -1, NULL,0); 
       unsigned short * wszGBK = new unsigned short[len+1];       
       memset(wszGBK, 0, len * 2 + 2); 
       MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)strUtf8, -1, (LPWSTR)wszGBK, len);
       len = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wszGBK, -1, NULL, 0, NULL, NULL);
       char *szGBK=new char[len + 1]; 
       memset(szGBK, 0, len + 1); 
       WideCharToMultiByte (CP_ACP, 0, (LPCWSTR)wszGBK, -1, (LPSTR)szGBK, len, NULL,NULL);
       return szGBK; 
}

char * wfunction::gbk2utf8(const char * strGBK)
{ 
       int len=MultiByteToWideChar(CP_ACP,0,(LPCSTR)strGBK, -1, NULL,0); 
       unsigned short * wszUtf8 = new unsigned short[len+1]; 
       memset(wszUtf8, 0, len * 2 + 2); 
       MultiByteToWideChar(CP_ACP, 0, (LPCSTR)strGBK, -1, (LPWSTR)wszUtf8, len);
       len = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wszUtf8, -1, NULL, 0, NULL, NULL);
       char *szUtf8=new char[len + 1]; 
       memset(szUtf8, 0, len + 1); 
       WideCharToMultiByte (CP_UTF8, 0, (LPCWSTR)wszUtf8, -1, (LPSTR)szUtf8, len, NULL,NULL);
       return szUtf8; 
}

char * wfunction::ctp_time_char_convert(char * ori,int length)
{
	char * ret = new char[length];
	memset(ret,'\0',length);
	int j=0;
	for(int i=0;i>=0;i++)
	{
		if (ori[i]==':')
		{
			continue;
		}
		if (ori[i]=='\0')
		{
			break;
		}
		ret[j]=ori[i];
		j++;
		
	}
	return ret;
}
string  wfunction::joinquote(const std::string & tojoin)
{
    string ret="";
    static map<string,string> stringmap;
    list <string> ls=splitstring(tojoin,"\t");
    if(ls.size()!=3)
    {
        cerr<<"ERROR : wfunction::joinquote\t\tstring=tojoin"<<endl;
        return ret;
    }
    list<string>::iterator iter=ls.begin();
    stringmap["0"]=iter->c_str();
    iter++;
    stringmap[iter->c_str()]=(++iter)->c_str();

    for (map<string,string>::iterator iter=stringmap.begin();iter!=stringmap.end();iter++)
    {
        if(iter->first=="0")
        {
            ret+=iter->second.c_str();
            ret+="\t";
            continue;
        }
        ret+=iter->first.c_str();
        ret+="\t";
        ret+=iter->second.c_str();
        ret+="\t";
    }
    return ret;
}
string wfunction::get_now_second()
{
    struct tm*ptr;
    time_t lt;
    char str[80];
    lt=time(NULL);
    ptr=localtime(&lt);
    strftime(str,sizeof(str),"%Y%m%d_%H_%M_%S",ptr);
    return str;
}
int wfunction::wmkdir(const string & dir)
{
    char * pDir=const_cast<char*>(dir.c_str());
    int i = 0;
    int iRet;
    int iLen;
    char* pszDir;

    if(NULL == pDir)
    {
        return 0;
    }

    pszDir = strdup(pDir);
    iLen = strlen(pszDir);

    for (i = 0;i < iLen;i ++)
    {
        if (pszDir[i] == '\\' || pszDir[i] == '/')
        {
            pszDir[i] = '\0';
            iRet = ACCESS(pszDir,0);
            if (iRet != 0)
            {
                iRet = MKDIR(pszDir);
                if (iRet != 0)
                {
                    return -1;
                }
            }
            pszDir[i] = '/';
        }
    }

    iRet = MKDIR(pszDir);
    free(pszDir);
    return iRet;
}
string wfunction::replacechar(const string & oldstr,const string & from,const string & to)
{
    string str=oldstr;
    int pos = str.find(from);

    while(pos != string::npos)
    {
        str = str.replace(pos, from.length(), to);
        pos = str.find(from);
    }

    return str;
}
