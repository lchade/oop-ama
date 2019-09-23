/***********************************************************************
// OOP244 Final Project Milestone 3
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-19
// File: Utilities.cpp
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utilities.h"
using namespace std;

namespace ama {
    // add the total cost of the product (first parameter) and returns the result
    double& operator+=(double& total, const Product& prod) {
        total += prod.total_cost();
        return total;
    }

    // write into the first parameter in human readable format
    ostream& operator<<(ostream& out, const Product& prod) {
        prod.write(out, write_human);
        return out;
    }

    // read from the first parameter a product in interactive mode
    istream& operator>>(istream& in, Product& prod) {
        prod.read(in, true);
        return in;
    }
}

