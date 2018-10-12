#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <thread>

#include "TableOne.hpp"

class A
{
private:
    int64_t a;
    int64_t b;
    int64_t c;
    int64_t d;
    int64_t e;
};

class B
{
private:
    A a;
    A b;
    A c;
    A d;
    A e;
};

int main(int argc, char * argv[])
{
    std::cout << "Begin" << std::endl;
    std::list<B> lst;

    for (int i = 0; i < 2000000; ++i){
        lst.push_back({});

//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }


    return EXIT_SUCCESS;
}
