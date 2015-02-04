#ifndef QTFUNCTION_H
#define QTFUNCTION_H
#include<string>
#include<map>
class qtfunction
{
public:
    static void *load_dll(const std::string & fn);
};
#endif
