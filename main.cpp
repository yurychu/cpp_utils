#include <iostream>
#include <string>

#include "StateTable.hpp"


template <typename T>
void print(T & cell)
{
    typename T::itsType a(33.4);
    std::cout << a << std::endl;
}

int main(int argc, char * argv[])
{


    using cell_one = st::Cell<'i', int>;
    using cell_two = st::Cell<'u', float>;

    std::cout << cell_one::itsIdx << std::endl;

    st::RecordDescription<
            int,
            float,
            char
    > description;

//    typename st::Cell::itsType;

    return EXIT_SUCCESS;
}
