#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

using namespace std;

class console
{
private:
    class info_time
    {
    public:
        chrono::system_clock::time_point time_stamp;
        string tag;

        info_time(chrono::system_clock::time_point _time_stamp, string _tagname)
        {
            time_stamp = _time_stamp;
            tag = _tagname;
        };
    };
    vector<info_time> Time_Arr;

public:
    console() { this->Time_Arr = {}; };
    ~console() { this->Time_Arr.clear(); };
    void log(string arg);
    void write(string arg);
    void error(string arg);
    void warn(string arg);
    void clear();
    void time(string tag);
    void time();
    void timeEnd(string tag);
    void timeEnd();
} console;

void console::log(string arg)
{
    cout << arg << endl;
}

void console::write(string arg)
{
    cout << arg;
}

void console::error(string arg)
{
    cerr << ANSI_COLOR_RED << arg << ANSI_COLOR_RESET << endl;
}

void console::warn(string arg)
{
    clog << ANSI_COLOR_YELLOW << arg << ANSI_COLOR_RESET << endl;
}

void console::clear()
{
    auto commandExecuted = system("clear");
    if (commandExecuted != 0)
    {
        system("cls");
    }
}

void console::time(string tag)
{
    bool isOnTheVector = false;
    for (auto &infoTime : Time_Arr)
    {
        if (infoTime.tag == tag)
        {
            isOnTheVector = true;
            break;
        }
    }
    if (isOnTheVector == true)
    {
        throw "the tag name is already counting";
    }
    info_time time = info_time(chrono::system_clock::now(), tag);
    Time_Arr.push_back(time);
}

void console::time()
{
    bool isOnTheVector;
    for (auto &infoTime : Time_Arr)
    {
        if (infoTime.tag == "default")
        {
            isOnTheVector = true;
            break;
        }
    }
    if (isOnTheVector == true)
    {
        throw "the tag name (default) is already counting";
    }
    info_time time = info_time(chrono::system_clock::now(), "default");
    Time_Arr.push_back(time);
}

void console::timeEnd(string tag)
{
    bool isOnTheVector = false;
    size_t index = 0;
    for (size_t i = 0; i < Time_Arr.size(); i++)
    {
        if (Time_Arr[i].tag == tag)
        {
            isOnTheVector = true;
            index = i;
            break;
        }
    }
    if (isOnTheVector == false)
    {
        throw "the tag name not exist";
    }
    cout << Time_Arr[index].tag << ": " << ((chrono::system_clock::now() - Time_Arr[index].time_stamp).count() / 1000000) << " ms" << endl;
}

void console::timeEnd()
{
    bool isOnTheVector = false;
    size_t index = 0;
    for (size_t i = 0; i < Time_Arr.size(); i++)
    {
        if (Time_Arr[i].tag == "default")
        {
            isOnTheVector = true;
            index = i;
            break;
        }
    }
    if (isOnTheVector == false)
    {
        throw "the tag name not exist";
    }
    cout << Time_Arr[index].tag << ": " << ((chrono::system_clock::now() - Time_Arr[index].time_stamp).count() / 1000000) << " ms" << endl;
}
