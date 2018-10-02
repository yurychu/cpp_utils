#include <iostream>
#include <string>

#include "StateTable.hpp"


int main(int argc, char * argv[])
{
    using cell_one = st::Cell<'i', int>;
    using cell_two = st::Cell<'u', float>;

    std::cout << cell_one::itsIdx << std::endl;

    st::RecordDescription <
            int, float
    > description;

//    typename st::Cell::itsType;

    return EXIT_SUCCESS;
}

//template<class F, template<class...> class... T>
//struct eval {
//    F const& fun;
//    eval(F const& f) : fun(f) {}
//    auto operator()(T<int, double> const&... t) {
//        return fun(t...);
//    }
//};
//
//using PID = std::pair<int, double>;
//using TID = std::tuple<int, double>;
//
//int f(PID const&, TID const&) { return 22; }
//
//int main() {
//    eval<decltype(f), std::pair, std::tuple> x(f);
//    auto xret = x(std::make_pair(23, 34.7), std::make_tuple(11, 47.11));
//    std::cout << xret << '\n';
//}

template<typename T>
std::ostream& print(std::ostream& where, const T& what) {
    return where << what;
}

template<typename T, typename... Types>
std::ostream& print(std::ostream& where, const T& what, const Types& ... other) {
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
