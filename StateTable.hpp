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
                std::get<1>(itsDataRow) = v;

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


    template<typename T>
    std::ostream& print(std::ostream& where, const T& what)
    {
        return where << what;
    }

    template<typename T, typename... Types>
    std::ostream& print(std::ostream& where, const T& what, const Types& ... other)
    {
        return print(where << what << ' ', other...);
    }

    template<int ...>
    struct seq
    {

    };

    template<int N, int... S>
    struct make_range : make_range<N-1, N-1, S...>
    {

    };

    template<int ...S>
    struct make_range<0, S...>
    {
        using result = seq<S...>;
    };

    template<typename... Types, int... range>
    std::ostream& operator_shl_impl(
            std::ostream& out,
            const std::tuple<Types...> & what,
            const seq<range...> /* a dummy argument */ )
    {
        return print(out, std::get<range>(what)...);
    }

    template<typename... Types>
    std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& what)
    {
        using range = typename make_range<sizeof...(Types)>::result;
        return operator_shl_impl(out, what, range());
    }


    int some_main(int argc, char * argv[])
    {
        st::StateTable <
                st::HeadCell<'i', int>,
                st::HeadCell<'u', float>,
                st::HeadCell<'s', int>,
                st::HeadCell<'v', int>
        > table;

        table.print_records();

        table.insert().put_value('i', 2).put_value('u', 77.777);

        table.print_records();

        return EXIT_SUCCESS;
    }



}




#endif //UTILS_STATETABLE_HPP
