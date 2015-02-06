#ifndef QTFUNCTION_H
#define QTFUNCTION_H
#include<string>
#include<map>
class qtfunction
{
public:
    //return qpluginloader instance search default dir and exe dir
    //instance CANNOT be use as class pointer
    static void *load_dll(const std::string & fn);
};
#endif
