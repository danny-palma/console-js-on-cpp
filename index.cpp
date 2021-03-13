#include <csignal>
#include <vector>
#include "./console.h"

using namespace std;
string car;
vector<string> arr;

void onExit(int sig)
{
    console.log("\n=================================");
    console.log("the inputs are: ");
    for (size_t i = 0; i < arr.size(); i++)
    {
        console.log(arr[i].c_str());
    }
    console.timeEnd("Execution time");
    exit(SIGINT);
}

int main(int argc, char const *argv[])
{
    console.time("Execution time");
    signal(SIGINT, onExit);
    console.log("Hello world :D");
    while (arr.size() < 1000)
    {
        console.write("Write a command: ");
        getline(cin, car, '\n');
        if (car == "clear")
        {
            console.clear();
        }
        else if (car == "error")
        {
            console.error("test Error");
        }
        else if (car == "warn")
        {
            console.warn("test warn");
        }
        else if (car == "")
        {
        }
        else if (car == "exit")
        {
            raise(SIGINT);
        }
        else
        {
            arr.push_back(car);
        }
    }
    raise(SIGINT);
    return 0;
}
