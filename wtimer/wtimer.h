#ifndef WTIMER
#define WTIMER

//根据数据输入数据设定时间
//方式1 20151224.09 15 00 500
//方式2 将日期设为0 也就是均为0 1之间的小数

class wtimer
{
public:
    double nowtic(){return _nowtic;}
    void settic(double nt){_nowtic =nt;}
private:
	double _nowtic;
};

#endif
