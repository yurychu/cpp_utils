#include <iostream>
#include <string>

#include "StateTable.hpp"


int main(int argc, char * argv[])
{
    st::StateTable state_table;

    st::Description description;

    state_table.create_from_description(description);

    state_table.print();

    return EXIT_SUCCESS;
}
