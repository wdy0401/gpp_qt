#include"log_info.h"
#include"../wtimer/wtimer.h"

extern wtimer tm;	

using namespace std;

bool log_info::setfile(const std::string &filename)
{
	outlog.open(filename.c_str());

    if(! outlog.is_open())
	{
		cerr << "Cannot openfile " << filename.c_str() << endl;
		//getchar();
        return false;
	}
    return true;
}
void log_info::closefile()
{
	outlog.close();
}


void log_info::writeinfo(const std::string &outputstring)
{
	outlog<<tm.nowtic()<<": ";
	outlog<<outputstring;
}

