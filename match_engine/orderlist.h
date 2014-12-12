#ifndef ORDERLIST
#define ORDERLIST

#include<map>
#include<list>
#include"order.h"

//ctp功能包装
//发单 撤单 改单
//平仓

class fillpolicy;

class orderlist
{

public:
	
	friend class fillpolicy;
	
	orderlist();
	std::string neworder(std::string symbol,std::string buysell,double price,long size);//strategy call// new an order
	void changeorder(std::string ordername);//strategy call// change size price etc

	void fillorder(std::string ordername);//fp call //when order filled
	void statuschange(std::string ordername,std::string atatus_info);//fp call //when changeorder's feed back

private:
	std::map <std::string,order *> _pend_order;
	std::map <std::string,order *> _run_order;
	std::map <std::string,order *> _done_order;
	long _ordercount;
};

#endif
