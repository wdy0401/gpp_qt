#ifndef LOG_INFO
#define LOG_INFO

#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include"../wtimer/wtimer.h"

class log_info
{
public:
    void init();
	bool setfile(const std::string &);
    void closefile();
    void writeinfo(const std::string &);
    void writeinfo_t(const std::string &);
    void set_timer(wtimer * p){timer=p;}

protected:
	std::ofstream outlog;
    wtimer * timer;
};

#endif

