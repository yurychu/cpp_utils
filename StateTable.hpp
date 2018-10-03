#ifndef UTILS_STATETABLE_HPP
#define UTILS_STATETABLE_HPP


#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <typeinfo>



namespace st {

    template <class Derived>
    struct base
    {
        void interface()
        {
            // ...
            static_cast<Derived*>(this)->implementation();
            // ...
        }
    };

    struct derived : base<derived>
    {
        void implementation()
        {
            // ...
        }
    };


    template <char name_idx, typename DataType>
    struct HeadCell
    {
        static constexpr auto itsIdx = name_idx;
        using data_type = DataType;

    };


    template<typename Cell, typename ...Tail>
    struct TableHead : TableHead<Tail...>
    {
        typename Cell::data_type data;

        TableHead(typename Cell::data_type cell, Tail... tail)
                : TableHead<Tail...>(tail...),
                  data()
        {

        }

    };

    template<typename Cell>
    struct TableHead<Cell::data_type>
    {
        typename Cell::data_type data;

        TableHead(typename Cell::data_type cell)
                : data(cell)
        {

        }

    };

    template<int index, typename Cell, typename ...Tail>
    struct get_data_cell_impl {
        static auto value(const TableHead<Cell, Tail...> * t) -> decltype(get_data_cell_impl<index - 1, Tail...>::value(t)) {
            return get_data_cell_impl<index-1, Tail...>::value(t);
        }
    };

    template<typename Cell, typename ...Tail>
    struct get_data_cell_impl<0, Cell, Tail...>
    {
        static Cell value(const TableHead<Cell, Tail...> * t) {
            return t->data;
        }
    };

    template<int index, typename Cell, typename... Tail>
    auto get_data_cell(const TableHead<Cell, Tail...> & t) -> decltype(get_data_cell_impl<index, Cell, Tail...>::value(&t))  // typename Type<index, Cell, Tail...>::value
    {
        return get_data_cell_impl<index, Cell, Tail...>::value(&t);
    }


    template <typename ...Args>
    class StateTable
    {
    private:
        using RecordProto = TableHead<Args...>;

//        std::vector <RecordProto> itsDatas;

    public:
        StateTable()
        {
            RecordProto a(3, 5.5f);

//            get_data_cell<0>(a);
        }

        ~StateTable() = default;

    };


}


#endif //UTILS_STATETABLE_HPP
