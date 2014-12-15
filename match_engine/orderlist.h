#ifndef ORDERLIST
#define ORDERLIST

#include<map>
#include<list>
#include<QObject>
#include"order.h"
#include"../../libs/ctp/ThostFtdcTraderApi.h"
class fillpolicy;

class orderlist :public QObject
{
    Q_OBJECT
    friend class fillpolicy;
public:
    void init();
    std::string new_order(const std::string symbol,const std::string buysell, const std::string & openclose ,double price,long size);//strategy call// new an order
    void cancel_order(const std::string & ordername);
    void change_order(const std::string & ordername,const std::string & change_cancel,double changeto);//strategy call// change size price etc
    //还可加入查询order状态的函数

public slots:
    void show_warning(const std::string &);

signals:

private:
    std::map <std::string, std::list<long>> _ordername_iRequestID;
    std::map <long, std::string> _iRequestID_ordername;
    std::map <long, CThostFtdcOrderField *> _iRequestID_porder;
    std::map <long, CThostFtdcTradeField *> _iRequestID_porder_trade;


    std::map <std::string,order *> _pend_order;
	std::map <std::string,order *> _run_order;
	std::map <std::string,order *> _done_order;
	long _ordercount;

    TThostFtdcFrontIDType           FRONT_ID;
    TThostFtdcSessionIDType         SESSION_ID;

};

#endif
