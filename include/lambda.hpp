#ifndef LAMBDA_LAMBDA_HPP
#define LAMBDA_LAMBDA_HPP

#include "lambda_internal.hpp"

namespace lambda {

    template<typename T> using lambda = internal::Lambda<T>;
    template<typename T> using Lambda = internal::Lambda<T>;

}

#endif // LAMBDA_LAMBDA_HPP

