#ifndef CIRCULAR_BALANCING_BUFFER_EPERIMCLASS_HPP
#define CIRCULAR_BALANCING_BUFFER_EPERIMCLASS_HPP

#include <string>
#include <iostream>


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



#endif //CIRCULAR_BALANCING_BUFFER_EPERIMCLASS_HPP
