#include"bars_manage.h"
#include"bars.h"
#include<iostream>
#include<list>
#include<deque>
#include<string>
#include"../wfunction/wfunction.h"

using namespace std;

void bars_manage::addbarlist(const std::string & barlist)
{	
	deque<string> contracts=wfunction::splitstring(barlist);
	for(deque<string>::iterator iter=contracts.begin();iter!=contracts.end();iter++)
	{
		newbars(iter->c_str());
	}
}
void bars_manage::newbars(const std::string & barname)
{
	_nowbars=new bars();
	_nowbars->setbarname(barname);
	_barsmap[barname]=_nowbars;
}void bars_manage::newbars(const std::string & barname,long length)
{
	newbars(barname);
	_nowbars->setlength(length);
}
void bars_manage::setlength(const std::string & barname,long length)
{
	if(isbarsexist(barname))
	{
        _nowbars->setlength(length);
	}
}
void bars_manage::updatebar(const std::string & barname,double value)
{
	if(isbarsexist(barname))
	{
        _barsmap[barname]->updatebar(value);
	}
}
void bars_manage::updatebar(const std::string & barname,double value,long volume)
{
	if(isbarsexist(barname))
	{
        _barsmap[barname]->updatebar(value,volume);
	}
}
bar * bars_manage::mergebar(const std::string & barname,long number)
{
	if(isbarsexist(barname))
	{
        return _barsmap[barname]->mergebar(number);
	}
	else
	{
		return nullptr;
	}
}
bool bars_manage::isbarsexist(const std::string & barname)
{
	if(_barsmap.find(barname)==_barsmap.end())
	{
		cerr<<"ERROR no bars found.   bars name="<<barname<<endl;
		return false;
	}
	else
	{
		_nowbars=_barsmap.find(barname)->second;
		return true;
	}
}
bars * bars_manage::getbars(const std::string & barname)
{
    if(_barsmap.find(barname)==_barsmap.end())
    {
        return nullptr;
    }
    else
    {
        return _barsmap[barname];
    }
}
