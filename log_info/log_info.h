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
    bool set_file(const std::string &);
    void close_file();
    void write_info(const std::string &);
    void write_info_t(const std::string &);
    void set_timer(wtimer * p){timer=p;}

protected:
	std::ofstream outlog;
    wtimer * timer;
};

#endif

