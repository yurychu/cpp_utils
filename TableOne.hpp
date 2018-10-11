#ifndef UTILS_TABLEONE_HPP
#define UTILS_TABLEONE_HPP

#include <initializer_list>
#include <string>

namespace to {


    class Cell
    {
    private:
        u_char itsTypeId;

    public:

        Cell()
        {
        }

        ~Cell() = default;


    };

    using ValueType = int64_t;


    class InjectElement
    {
    private:
        std::string itsName;
        ValueType itsValue;

    public:

        InjectElement(std::string name, ValueType value)
            : itsName(std::move(name)),
              itsValue(value)
        {

        }
        ~InjectElement() = default;

        std::string get_name() const { return itsName; }
        ValueType get_value () const { return itsValue; }

    };

//
//    class HeadCell
//    {
//    private:
//        static size_t inst_counter;
//        size_t itsIdx;
//
//    public:
//        HeadCell()
//                : itsIdx(++inst_counter)
//        {
//        }
//
//
//    };

//    HeadCell::inst_counter = 0;

    class Table
    {
    private:

    public:

        Table()
        {

        }

        ~Table() = default;

        void insert(const std::initializer_list<InjectElement> & l)
        {
            for (const auto & el : l){
                auto name = el.get_name();
                auto value = el.get_value();
            }
        }


    };




}




#endif //UTILS_TABLEONE_HPP
