#include "../console.h"
int main(int argc, char const *argv[])
{
    console.log("");
    console.warn("");
    console.error("");
    console.clear();
    console.time(); // without arguments
    console.timeEnd(); // without arguments

    console.time("tagname"); // with arguments (tagname)
    console.timeEnd("tagname"); // with arguments (tagname)
    return 0;
}
