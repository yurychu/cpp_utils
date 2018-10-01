#ifndef UTILS_STATETABLE_HPP
#define UTILS_STATETABLE_HPP


#include <vector>
#include <string>
#include <iostream>
#include <tuple>


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
    struct Cell
    {
        static constexpr auto itsIdx = name_idx;
        using data_type = DataType;
    };


    template <typename ... Args>
    class RecordDescription
    {
    private:
        std::vector<char> itsIdxes;

    public:

        RecordDescription()
        {
            std::cout << __PRETTY_FUNCTION__ << std::endl;

            auto a = {Args...};

            std::vector<char> arr{};
//            std::cout << sizeof ... (Args) << std::endl;
        }


        ~RecordDescription() = default;

    };


    class Record
    {
    private:
    public:

    };


    template <typename ... Args>
    class StateTable
    {
    private:
        std::vector<st::Record> itsRecords;

    public:
        StateTable() = default;
        ~StateTable() = default;

    };


}


#endif //UTILS_STATETABLE_HPP
