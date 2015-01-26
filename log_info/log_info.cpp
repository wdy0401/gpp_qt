#include"log_info.h"


using namespace std;

bool log_info::set_file(const std::string &filename)
{
	outlog.open(filename.c_str());

    if(! outlog.is_open())
	{
        cerr << "Cannot openfile " << filename.c_str() << endl;
        return false;
	}
    return true;
}
void log_info::init()
{
    timer=nullptr;
}
void log_info::close_file()
{
	outlog.close();
}


void log_info::write_info(const std::string &outputstring)
{
    outlog<<outputstring;
}

void log_info::write_info_t(const std::string &outputstring)
{
    if(timer!=nullptr)
    {
        outlog<<timer->nowtic()<<": ";
    }
    else
    {
        outlog<<"Timer not set:";
    }
    outlog<<outputstring;
}

