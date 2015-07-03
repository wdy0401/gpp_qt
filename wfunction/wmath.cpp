#include"wmath.h"

using namespace std;

double wmath::mean(list<double> * nowlist)
{
    if(nowlist->size()==0)
    {
        return 0;
    }
    double total=0;
    for(list<double>::iterator iter=nowlist->begin() ; iter!=nowlist->end() ; iter++)
    {
        total+=*iter;
    }
    return total/nowlist->size();

}
double wmath::stdev(list<double> * nowlist)
{
    if(nowlist->size()==0 || nowlist->size()==1)
    {
        return 0;
    }
    double m=mean(nowlist);
    double total=0;
    for(list<double>::iterator iter=nowlist->begin() ; iter!=nowlist->end() ; iter++)
    {
        total+=pow((m-*iter),2);
    }
    return sqrt(total/(nowlist->size()-1));
}
