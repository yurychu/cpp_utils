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
    : itsValue("EmptyDefaultValue")
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
    constexpr size_t buff_size = 2;
    util_lib::BalancingBuffer<ExperimClass, buff_size> balancing_buffer;

    std::cout << std::endl << "Processing" << std::endl;

    ExperimClass obj1("Some-5");
    balancing_buffer.set_force(obj1, 5);
    ExperimClass obj2("Some-6");
    balancing_buffer.set_force(obj2, 6);
    ExperimClass obj3("Some-7");
    balancing_buffer.set_force(obj3, 7);
    ExperimClass obj4("Some-8");
    balancing_buffer.set_force(obj4, 8);
    ExperimClass obj5("Some-9");
    balancing_buffer.set_force(obj5, 9);
    ExperimClass obj6("Some-10");
    balancing_buffer.set_force(obj6, 10);

    auto elem = balancing_buffer.get_if_exist(8);
    auto elem2 = balancing_buffer.get_if_exist(39);

    std::cout << std::endl << "Exiting" << std::endl;
    return EXIT_SUCCESS;
}
