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
    ExperimClass(const ExperimClass & that);
    ExperimClass&operator=(const ExperimClass & that);
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

ExperimClass::ExperimClass(const ExperimClass &that)
    : itsValue(that.itsValue)
{
    std::cout << "Copy constructor with value: \"" << itsValue << "\"" << std::endl;
}

ExperimClass&
ExperimClass::operator=(const ExperimClass &other)
{
    std::cout << "Assign constructor with value from: \"" << itsValue << "\" "
              << "to: \"" << other.itsValue << "\""
              << std::endl;

    if(this != &other)
    {
        this->itsValue = other.itsValue;
    }
    return *this;
}


int main(int argc, char * argv[])
{
    constexpr size_t buff_size = 10;
    util_lib::BalancingBuffer<ExperimClass, buff_size> balancing_buffer;

    std::cout << std::endl << "Processing" << std::endl;
    ExperimClass obj("Some");
    balancing_buffer.set(obj, 5);
    auto elem = balancing_buffer.get(4);

    std::cout << std::endl << "Exiting" << std::endl;
    return EXIT_SUCCESS;
}
