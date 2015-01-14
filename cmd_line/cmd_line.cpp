#include "cmd_line.h"
#include <iostream>

using namespace std;
cmd_line::cmd_line(int n,char **p)
{
    string lastp="";
    bool last_is_=false;
    for(int i=1;i<n;i++)
    {
		cout << n << " " << i << " " << p[i] << endl;
		string nowp=p[i];
        if(nowp[0]=='-')
        {
			fix_char(nowp);
			_para_map[nowp] = "";
            last_is_=true;
            lastp=nowp;
        }
        else
        {
            if(last_is_==true)
            {
                _para_map[lastp]=nowp;
                last_is_=false;
                lastp=nowp;
            }
            else
            {
                _para_map[nowp]="";
                last_is_=false;
                lastp=nowp;
            }
        }
    }
}

std::string cmd_line::get_para(const std::string & str)
{
    string ret="";
    if(_para_map.find(str)!=_para_map.end())
    {
        ret=_para_map[str];
    }
    return ret;
}
bool cmd_line::has_para(const string & str)
{
    if(_para_map.find(str)!=_para_map.end())
    {
        return true;
    }
    return false;
}
void cmd_line::fix_char(string &p)
{
    while(p[0]=='-')
    {
        p.erase(0,1);
//		cout << "p" << p << endl;
    }
}
