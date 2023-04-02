#include <iostream>

template<typename T, typename... Ts>
struct tuple
{
    tuple(T const& t, Ts const&... ts) : value(t), rest(ts...) {}
    constexpr int size() const {return 1+rest.size();}
    T value;
    tuple<Ts...> rest;
};
template<typename T>
struct tuple<T>
{
    tuple(T const& t) : value(t) {}
    constexpr int size() const {return 1;}
    T value;
};

template <size_t N, typename T, typename... Ts>
struct nth_type : nth_type<N-1,Ts...>
{
    static_assert(N < sizeof...(Ts)+1,"index out of bounds");
};

template <typename T, typename... Ts>
struct nth_type <0,T,Ts...>
{
    using value_type = T;
};

template<size_t N>
struct getter
{
    template<typename... Ts>
    static typename nth_type<N,Ts...>::value_type& get(tuple<Ts...>& t)
    {
        return getter<N-1>::get(t.rest);
    }
};

template<>
struct getter<0>
{
    template<typename T, typename... Ts>
    static T& get(tuple<T, Ts...>& t)
    {
        return t.value;
    }
};

template<size_t N, typename... Ts>
typename nth_type<N, Ts...>::value_type & get(tuple<Ts...>& t)
{
    return getter<N>::get(t);
}

int main()
{
    tuple<int> one(42);
    tuple<int,double> two(42,42.0);
    tuple<int,double, char> three(32,54.2,'a');
    std::cout<<one.value<<std::endl;
    std::cout<<two.value<<" "<<two.rest.value<<std::endl;
    std::cout<<three.value<<" "<<three.rest.value<<" "<<three.rest.rest.value<<std::endl;
    std::cout<<get<0>(one)<<std::endl;
    std::cout<<get<0>(two)<<" "<<get<1>(two)<<std::endl;
    std::cout<<get<0>(three)<<" "<<get<1>(three)<<" "<<get<2>(three)<<std::endl;
}