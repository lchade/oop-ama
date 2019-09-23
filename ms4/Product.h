/***********************************************************************
// OOP244 Final Project Milestone 3
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-19
// File: Product.h
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include "iProduct.h"
#include "ErrorState.h"

namespace ama {

    class Product : public iProduct {
        const char m_type;
        char m_sku[max_length_sku + 1];
        char m_unit[max_length_unit + 1];
        char m_desc[max_length_label + 1];
        char* m_name;
        int m_qty_onhand;
        int m_qty_needed;
        double m_price;
        bool m_tax;
        ErrorState m_err;
        // add a private function
        double afterTax() const;
    // add to class the following protected functions
    protected:
        void message(const char* pText);
        bool isClear() const;
    // add to class the following public functions and override pure virtual functions
    public:
        Product(const char type = 'N');
        Product(const char* sku, const char* name, const char* unit, double price = 0, int qty_n = 0, int qty_h = 0, bool tax = true);
        Product(const Product& src);
        Product& operator=(const Product& src);
        int operator+=(int cnt);
        bool operator==(const char* sku) const;
        bool operator>(const char* sku) const;
        bool operator>(const iProduct& other) const;
        int qtyAvailable() const;
        int qtyNeeded() const;
        const char* name() const;
        double total_cost() const;
        bool isEmpty() const;
        std::istream& read(std::istream& in, bool interactive);
        std::ostream& write(std::ostream& out, int writeMode) const;
        ~Product();
    };
}
#endif