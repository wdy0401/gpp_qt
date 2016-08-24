#ifndef WTIMER
#define WTIMER

#include<stdio.h>
#include<windows.h>

class wtimer
{
public:
    double nowtic(){return _nowtic;}
    char * nowtime(){GetLocalTime(&sys);sprintf(a,"%02d:%02d:%02d:%03d",sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds); return a;}
    void settic(double nt){_nowtic =nt;}
private:
	double _nowtic;
	SYSTEMTIME sys;
	char a[20];
};

#endif
