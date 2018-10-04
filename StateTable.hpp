#ifndef UTILS_STATETABLE_HPP
#define UTILS_STATETABLE_HPP

#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <typeinfo>
#include <map>


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


    template<typename ...Cells>
    struct TableHead
    {
    };

    template<typename Cell>
    struct TableHead<Cell>
    {
        static constexpr auto idx_name = Cell::itsIdx;
        using data_type = typename Cell::data_type;
    };


    template<typename Head, typename ...Types>
    struct TableHead<Head, Types...>
    {
        using idx_name_type = decltype(Head::itsIdx);
    };


    template <typename ...Args>
    class StateTable
    {
    private:
        using RecordType = std::tuple<typename TableHead<Args>::data_type...>;
        using IdxNameType = typename TableHead<Args...>::idx_name_type;

        struct

        class Record
        {
        private:
//            & itsCellIdxMap;
            RecordType itsDataRow;

        public:

            Record()
                    : itsDataRow()
            {
            };

            ~Record() = default;

            const RecordType & get_row() const
            {
                return itsDataRow;
            }

            template <typename I, typename V>
            Record &
            put_value(const I & i, const V & v)
            {


                return *this;
            }

        };

        std::map<IdxNameType, int> itsCellIdxMap;

        std::vector<Record> itsRecords;

    public:

        StateTable()
            : itsRecords()
        {
            int idx = 0;
            for (const auto & a : { TableHead<Args>::idx_name... }){
                itsCellIdxMap[idx] = a;
                idx++;
            }

        }

        void print_records() const
        {
            std::cout << "Print records:" << std::endl;

            for (const auto & elem : itsRecords){
                std::cout << elem.get_row() << std::endl;
            }

        }

        Record & insert()
        {
            itsRecords.emplace_back();
            return itsRecords.back();
        }

        ~StateTable() = default;

    };


}


#endif //UTILS_STATETABLE_HPP
