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
void log_info::closefile()
{
	outlog.close();
}


void log_info::writeinfo(const std::string &outputstring)
{
    outlog<<outputstring;
}

void log_info::writeinfo_t(const std::string &outputstring)
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

