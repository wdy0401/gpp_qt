#ifndef CMD_LINE_H
#define CMD_LINE_H
#include<map>
#include<string>
class cmd_line
{
public:
	cmd_line(int n, char **p);
    std::string get_para(const std::string &);
    void fix_char(std::string &p);
	bool has_para(const std::string & str);

private:
    std::map <std::string,std::string> _para_map;
};

#endif // CMD_LINE_H
