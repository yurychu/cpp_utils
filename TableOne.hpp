#ifndef UTILS_TABLEONE_HPP
#define UTILS_TABLEONE_HPP


#include <string>

namespace to {

    class RubberTable
    {
    private:
        std::string itsWrapOrder;

    public:

        RubberTable() = default;
        ~RubberTable() = default;

        void set_wrap_order(const std::string & order)
        {
            itsWrapOrder = order;
        }



    };




}




#endif //UTILS_TABLEONE_HPP
