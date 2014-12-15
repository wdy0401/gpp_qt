#include"orderlist.h"
#include<iostream>
#include<QMessageBox>
#include"../wfunction/wfunction.h"
#include"../../only_qt_ctp/mainwindow.h"
#include"../../libs/ctp/ThostFtdcTraderApi.h"

extern MainWindow * mw;

using namespace std;

void orderlist::init()
{
	_ordercount=0;
}
void orderlist::show_warning(const string & warninfo)
{
    cerr << "Warning from ol" << endl;
    cerr << warninfo <<endl;
}
