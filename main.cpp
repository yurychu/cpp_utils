#include <iostream>
#include <string>

#include "CircularBalancingBuffer.hpp"


class ExperimClass
{
private:
    std::string itsValue;
public:
    ExperimClass();
    explicit ExperimClass(std::string value);
    ~ExperimClass();
};

ExperimClass::ExperimClass()
{
    std::cout << "Constructed default object: \"" << itsValue << "\"" << std::endl;
}

ExperimClass::ExperimClass(std::string value)
        :itsValue(std::move(value))
{
    std::cout << "Constructed object with value: \"" << itsValue << "\"" << std::endl;
}

ExperimClass::~ExperimClass()
{
    std::cout << "Destructed object with value: \"" << itsValue << "\"" << std::endl;
}

int main(int argc, char * argv[])
{
    util_lib::BalancingBuffer<ExperimClass, 30> balancing_buffer;

    ExperimClass obj("Some");
    balancing_buffer.set(obj);
    auto elem = balancing_buffer.get(3);

    return EXIT_SUCCESS;
}
