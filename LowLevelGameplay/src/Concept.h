#pragma once
#include <concepts>
#include <Component.h>

template<class T>
concept isComponent = std::derived_from<T, LLGP::Component> == true;