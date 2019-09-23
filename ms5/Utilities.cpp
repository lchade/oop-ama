/***********************************************************************
// OOP244 Final Project Milestone 5
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-29
// File: Utilities.cpp
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utilities.h"
using namespace std;

namespace ama {
    // add the total cost of the product (first parameter) and returns the result
    double& operator+=(double& total, const iProduct& prod) {
        total += prod.total_cost();
        return total;
    }

    // write into the first parameter in human readable format
    ostream& operator<<(ostream& out, const iProduct& prod) {
        prod.write(out, write_human);
        return out;
    }

    // read from the first parameter a product in interactive mode
    istream& operator>>(istream& in, iProduct& prod) {
        prod.read(in, true);
        return in;
    }

    // dynamically create an object with type 'N' and 'n' and return its address
    iProduct* createInstance(char tag) {
        iProduct* p = nullptr;
        if (tag == 'N' || tag == 'n') {
            p = new Product();
        } else if (tag == 'P' || tag == 'p') {
            p = new Perishable();
        }
        return p;
    }
}