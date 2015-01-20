#ifndef LOGS_H
#define LOGS_H

#include<map>
#include<string>
#include<iostream>
#include"../wtimer/wtimer.h"
#include"log_info.h"


#include<QObject>

class log_info : public QObject
{
    Q_OBJECT
public:
    void init();    
    bool set_dir(const std::string &);
    void set_timer(wtimer * p){timer=p;}
signals:
    void writeinfo(const std::string & info, const std::string & type,bool tm);

    bool setfile(const std::string &);
    void closefile();
    void writeinfo(const std::string &);
    void writeinfo_t(const std::string &);

protected:
	std::ofstream outlog;
    wtimer * timer;
};

#endif

