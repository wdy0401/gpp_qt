#ifndef LOGS_H
#define LOGS_H

#include<map>
#include<string>
#include<iostream>
#include"../wtimer/wtimer.h"
#include"log_info.h"


#include<QObject>

class logs : public QObject
{
    Q_OBJECT
public:
    ~logs();
    void init();    
    void set_dir(const std::string & d){dir=d;}
    void set_timer(wtimer * p){timer=p;}
public slots:
    void fill(const std::string & ordername,const std::string & symbol,const std::string & buysell,double price, long size);
    void tactic_info(const std::string & info);

private:
    void write_info(const std::string & info, const std::string & type,bool tm);
    wtimer * timer;
    std::string dir;
    std::map<std::string , log_info *> infomap;
};

#endif

