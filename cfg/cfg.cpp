#include"cfg.h"

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

cfg::cfg()
{
	_cfgfile="c:\\cfg\\simu.cfg";
	_sep="=";
	_pfile=nullptr;
	_cl=nullptr;
}
cfg::~cfg()
{
	delete _pfile;
}
string cfg::get_para(const std::string & param)
{
    string ret="";
    if(_kvpair.find(param)!=_kvpair.end())
    {
        ret=_kvpair[param];
	}
    return ret;
}
void cfg::setcfgfile(const std::string & cfgfile)
{
    if(cfgfile=="")
    {
        return;
    }
	_cfgfile=cfgfile;
	clearcfg();
	loadfile();
	merge();
}
void cfg::addcfgfile(const std::string & cfgfile)
{
    if(cfgfile.size()==0)
    {
        return;
    }
    _cfgfile=cfgfile;
	loadfile();
	merge();
}
void cfg::setsep(const std::string & sep)
{
	_sep=sep;
}
void cfg::clearcfg()
{
	_kvpair.clear();
}
void cfg::loadfile()
{
	_pfile=new ifstream;
	_pfile->open(_cfgfile.c_str());
	if(! _pfile->is_open()) //检测文件存在性
	{
		delete _pfile;
		_pfile=nullptr;
		cerr << "********************************************\n*\n*\n*\n";
		cerr << "Cannot openfile " << _cfgfile.c_str() << endl;
		cerr << "Please set cfgfile and restart"<<endl;
		cerr << "Press any key to continue"<<endl;
		cerr << "\n*\n*\n*\n********************************************"<<endl;
		getchar();
		return;
	}
	string tmpstring;
	string key,value;
	while(getline(*_pfile,tmpstring))
	{
        if(tmpstring.size()<=1 || tmpstring[0]=='#')//排除空行和#开头的注释行
		{
			continue;
		}
        if(tmpstring.substr(0,7)=="__END__" && tmpstring.size()==7)
        {
            cout<<"break"<<tmpstring<<endl;
            break;
        }
        if(tmpstring.find(_sep)==string::npos)
		{
            cerr << "ERROR : CFG_FILE \nFile name:\t" << _cfgfile <<"\n" <<"line: "<<tmpstring<<endl;
			continue;
		}
		unsigned int fp=tmpstring.find_first_of(_sep);
		key=tmpstring.substr(0,fp);
		value=tmpstring.substr(fp+1,tmpstring.size());
		_kvpair[key]=value;
	}
    _pfile->close();
	delete _pfile;
	_pfile=nullptr;
}
void cfg::init_cl(int n,char **p)
{
	_cl=new cmd_line(n,p);
	load_cl();
}
void cfg::load_cl()
{
	if(_cl==nullptr)
	{
		return;
	}
	for(auto iter=_cl->_para_map.begin();iter!=_cl->_para_map.end();iter++)
	{
		_kvpair[iter->first]=iter->second;
	}
}
void cfg::merge()
{
	load_cl();
}
