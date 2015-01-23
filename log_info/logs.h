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
    void init();    
    void set_dir(const std::string & d){dir=d;}
    void set_timer(wtimer * p){timer=p;}
public slots:
    void writeinfo(const std::string & info, const std::string & type,bool tm);

private:
    wtimer * timer;
    std::string dir;
    std::map<std::string , log_info *> infomap;
};

#endif

