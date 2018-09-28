#ifndef UTILS_STATETABLE_HPP
#define UTILS_STATETABLE_HPP


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




    class Description
    {
    private:

    public:
        Description() = default;
        ~Description() = default;

    };


    class StateTable
    {
    private:
    public:
        StateTable() = default;
        ~StateTable() = default;

    };


}


#endif //UTILS_STATETABLE_HPP
