#include"logs.h"
#include<QDebug>

using namespace std;

void logs::init()
{
    log_info * tp1=new log_info;
    tp1->set_file(this->dir+"/info.txt");
    tp1->set_timer(timer);
    infomap["info"]=tp1;

    log_info * tp2=new log_info;
    tp2->set_file(this->dir+"/trade.txt");
    tp2->set_timer(timer);
    infomap["trade"]=tp2;
 }

void logs::writeinfo(const std::string & info, const std::string & type,bool tm)
{
    if(infomap.find(type)==infomap.end())
    {
        qDebug()<<"ERROR: logs :type not find \ttype:"<<QString::fromStdString(type)<<endl;
        return;
    }
    if(tm==true)
    {
        infomap[type]->writeinfo_t(info);
    }
    else
    {
        infomap[type]->writeinfo(info);
    }
}
