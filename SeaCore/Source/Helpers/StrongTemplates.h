#pragma once
//https://www.fluentcpp.com/2018/01/09/strong-templates/

template<typename T>
struct Base {};

template<typename T>
struct Derived {};

template<typename, typename>
struct strong_is_base_of {};

template<typename BaseClass, typename DerivedClass>
struct strong_is_base_of<Base<BaseClass>, Derived<DerivedClass>> : std::is_base_of<BaseClass, DerivedClass> {};

template<typename, typename>
constexpr bool strong_is_base_of_v{};

template<typename BaseClass, typename DerivedClass>
constexpr bool strong_is_base_of_v<Base<BaseClass>, Derived<DerivedClass>> = std::is_base_of_v<BaseClass, DerivedClass>;

//USAGE
//static_assert(strong_is_base_of_v<Base<A>, Derived<B>>, "A is a base of B");