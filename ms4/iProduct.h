/***********************************************************************
// OOP244 Final Project Milestone 4
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-26
// File: iProduct.h
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef AMA_IPRODUCT_H
#define AMA_IPRODUCT_H
#include <iostream>

namespace ama {
    // predefine the constant variables
    const int max_length_label = 30;
    const int max_length_sku = 7;
    const int max_length_name = 75;
    const int max_length_unit = 10;
    const int write_condensed = 0;
    const int write_table = 1;
    const int write_human = 2;
    const double tax_rate = 0.13;

    class iProduct {
    // add pure virtual functions in the interface
    public:
        virtual std::ostream& write(std::ostream& os, int writeMode) const = 0;
        virtual std::istream& read(std::istream& is, bool interractive) = 0;
        virtual bool operator==(const char* sku) const = 0;
        virtual double total_cost() const = 0;
        virtual int qtyNeeded() const = 0;
        virtual int qtyAvailable() const = 0;
        virtual const char* name() const = 0;
        virtual int operator+=(int qty) = 0;
        virtual bool operator>(const iProduct& other) const = 0;
        virtual ~iProduct(){};
    };
}




#endif