#include"qtfunction.h"
#include<QCoreApplication>
#include<QPluginLoader>
#include<QDateTime>
#include<QFileInfo>
#include<QDebug>
#include<QString>
#include<map>

using namespace std;

void * qtfunction::load_dll(const std::string & fn)
{
    static std::map<std::string , void *> dll_map;
    if(dll_map.find(fn.c_str())!=dll_map.end())
    {
        return dll_map[fn.c_str()];
    }

    QString filename=fn.c_str();
    if(filename.endsWith(".dll")==false)
    {
        filename=filename+".dll";
    }
    QFileInfo file=QFile(filename);
    QPluginLoader pluginLoader;
    if(file.isFile()==true)
    {
        qDebug()<<"Load_dll " << filename;
    }
    else
    {
        filename=filename.left(filename.size()-4);
        filename=QCoreApplication::applicationDirPath()+"/"+filename+".dll";
        file.setFile(filename);
        if(file.isFile())
        {
            qDebug()<<"Load_dll " << filename;
        }
        else
        {
            qDebug()<<"Cannot load dll " << filename;
            return nullptr;
        }
    }
    pluginLoader.setFileName(filename);
    pluginLoader.load();
	void * ptr=pluginLoader.instance();
    dll_map[fn.c_str()]=ptr;
    return ptr;
}
