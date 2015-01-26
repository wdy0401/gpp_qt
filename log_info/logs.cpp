#include"logs.h"
#include"../gpp_qt/wfunction/wfunction.h"
#include<QDebug>

using namespace std;

logs::~logs()
{
    infomap["info"]->close_file();
    infomap["trade"]->close_file();
}
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

void logs::write_info(const std::string & info, const std::string & type,bool tm)
{
    if(infomap.find(type)==infomap.end())
    {
        qDebug()<<"ERROR: logs :type not find \ttype:"<<QString::fromStdString(type)<<endl;
        return;
    }
    if(tm==true)
    {
        infomap[type]->write_info_t(info);
    }
    else
    {
        infomap[type]->write_info(info);
    }
}
void logs::fill(const std::string & ordername,const std::string & symbol,const std::string & buysell,double price, long size)
{
    string info=ordername+ "\t" + symbol+ "\t" + buysell+ "\t" + wfunction::ftos(price)+ "\t" + wfunction::itos(size)+"\n";
    write_info(info,"trade",1);
}

void logs::tactic_info(const std::string & info)
{
    write_info(info,"info",1);
}
