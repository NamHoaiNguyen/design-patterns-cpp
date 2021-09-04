#include "../include/singleton.h"

#include <cstring>
#include <iostream> 
#include <mutex>
#include <thread>


int main()
{
    /*If Two strings are the same, it is okay*/
    std::thread test1(createString, "String to test");
    std::thread test2(createString, "Must be the same");
    test1.join();
    test2.join();
 
    return 0;
}
