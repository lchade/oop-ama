/***********************************************************************
// OOP244 Final Project Milestone 5
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-28
// File: Perishable.h
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

#include "Product.h"
#include "Date.h"

namespace ama {

    class Perishable : public Product {
        Date m_expiry;
    public:
        Perishable();
        // override functions from the base class
        std::istream& read(std::istream& in, bool interactive);
        std::ostream& write(std::ostream& out, int writeMode) const;      
    };
}

#endif