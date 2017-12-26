#ifndef CFG
#define CFG

#include<iostream>
#include<fstream>
#include<string>
#include<map>

#include"../cmd_line/cmd_line.h"

//在参数数量增加时或参数数据结构复杂时 需要用xml来处理 
//xml有待实现 boost里有没有？

class cfg
{
public:
	cfg();
	~cfg();
    std::string get_para(const std::string &);
	void setcfgfile(const std::string &);
	void addcfgfile(const std::string &);
	void loadfile();
	
	void setsep(const std::string &);
	
	void clearcfg();
	
	void init_cl(int n, char **p);
	void load_cl();
	void merge();
    std::map<std::string,std::string> get_copy(){return _kvpair;}
private:
	std::map<std::string,std::string> _kvpair;
	std::string _cfgfile;
	std::string _sep;
	std::ifstream * _pfile;
    cmd_line * _cl;
};

#endif
/*************
load cl

load cfgfile
load cl
**************/
