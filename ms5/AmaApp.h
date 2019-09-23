/***********************************************************************
// OOP244 Final Project Milestone 5
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-29
// File: AmaApp.h
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H

#include <iostream>
#include "Product.h"
#include "Perishable.h"
#include "Utilities.h"

namespace ama {
    class AmaApp {
    private:
        char m_filename[256];
        iProduct* m_products[100];
        int m_noOfProducts;
    // private member functions
        void pause() const;
        int menu() const;
        void loadProductRecords();
        void saveProductRecords() const;
        void listProducts() const;
        iProduct* find(const char* sku) const;
        void addQty(iProduct* product);
        void addProduct(char tag);
    // public member functions
    public:
        AmaApp(const char* filename);
        ~AmaApp();
        int run();
    };
}

#endif
