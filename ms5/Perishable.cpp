/***********************************************************************
// OOP244 Final Project Milestone 5
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-19
// File: Product.cpp
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"
#include "ErrorState.h"
using namespace std;

namespace ama {
    Perishable::Perishable() : Product('P') {
    }

    // an override of write() function from Product class
    ostream& Perishable::write(ostream& out, int writeMode) const {
        Product::write(out, writeMode);
        if (isClear() && !isEmpty()) {
            if (writeMode == write_human) {
                out << right << setw(max_length_label) << "Expiry Date: ";
                out << left << m_expiry << endl;
            } else if (writeMode == write_table) {
                out << " " << m_expiry << " |";
            } else if (writeMode == write_condensed) {
                out << "," << m_expiry;
            }
        }
        return out;
    }

    // this function calls its base class version
    // extract data from the stream for all attributes except expiry date
    istream& Perishable::read(istream& in, bool interactive) {
        if (interactive) {
        // interactive mode
            Product::read(in, true);
            cout << right << setw(max_length_label) << "Expiry date (YYYY/MM/DD): " << left;
            Date temp;
            temp.read(in);
            if (temp.status() == error_year) {
                in.setstate(ios::failbit);
                message("Invalid Year in Date Entry");
            } else if (temp.status() == error_mon) {
                in.setstate(ios::failbit);
                message("Invalid Month in Date Entry");
            } else if (temp.status() == error_day) {
                in.setstate(ios::failbit);
                message("Invalid Day in Date Entry");
            } else if (in.fail()) {
                in.setstate(ios::failbit);
                message("Invalid Date Entry");
            } else {
                m_expiry = temp;
            }
        } else {
        // non-interactive mode
            Product::read(in, false);
            m_expiry.read(in);
            in.ignore();
        }
        return in;
    }
}
