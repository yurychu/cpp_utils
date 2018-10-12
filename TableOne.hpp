#ifndef UTILS_TABLEONE_HPP
#define UTILS_TABLEONE_HPP

#include <initializer_list>
#include <map>
#include <string>

namespace to {

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


    class HeadCell
    {
    private:
        static size_t inst_counter;
        size_t itsIdx;

    public:
        HeadCell()
                : itsIdx(++inst_counter)
        {
        }

        size_t get_idx() const
        {
            return itsIdx;
        }


    };

    size_t HeadCell::inst_counter = 0;


    class Cell
    {
    private:
        size_t itsCellIdx;
        ValueType itsValue;

    public:

        Cell(size_t cell_idx, ValueType value)
            : itsCellIdx(cell_idx),
              itsValue(value)
        {
        }

        ~Cell() = default;

        size_t get_cell_idx() const
        {
            return itsCellIdx;
        }

        ValueType get_value() const
        {
            return itsValue;
        }


    };


    class Table
    {
    private:
        size_t itsInserts;
        std::map<std::string, HeadCell> itsHeads;

    public:

        Table()
            : itsHeads(),
              itsInserts(0)
        {
        }

        ~Table() = default;

        void insert(const std::initializer_list<InjectElement> & l)
        {
            const auto cur_ins = ++itsInserts;
            for (const auto & el : l){
                auto name = el.get_name();
                auto value = el.get_value();

                auto cell_head = itsHeads[name];
                std::cout << cell_head.get_idx()<< std::endl;
            }
        }


    };




}




#endif //UTILS_TABLEONE_HPP
