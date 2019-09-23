/***********************************************************************
// OOP244 Final Project Milestone 3
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-19
// File: Utilities.h
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef AMA_UTILITIES_H
#define AMA_UTILITIES_H
#include <iostream>
#include "Product.h"

namespace ama {
    // prototypes of helper functions
    double& operator+=(double& total, const Product& prod);
    std::ostream& operator<<(std::ostream& out, const Product& prod);
    std::istream& operator>>(std::istream& in, Product& prod);
}

#endif