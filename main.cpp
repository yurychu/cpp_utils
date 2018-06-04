#include <iostream>
#include <string>

#include <CustomConfParser.hpp>


int main(int argc, char * argv[])
{
    util_lib::make_parse("custom_config_template.some_ex");

    return EXIT_SUCCESS;
}
