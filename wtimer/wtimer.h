#ifndef WTIMER
#define WTIMER

//�����������������趨ʱ��
//��ʽ1 20151224.09 15 00 500
//��ʽ2 ��������Ϊ0 Ҳ���Ǿ�Ϊ0 1֮���С��

class wtimer
{
public:
    double nowtic(){return _nowtic;}
    void settic(double nt){_nowtic =nt;}
private:
	double _nowtic;
};

#endif
