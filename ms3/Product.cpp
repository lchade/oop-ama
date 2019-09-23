/***********************************************************************
// OOP244 Final Project Milestone 3
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
#include "Product.h"
using namespace std;

namespace ama {
    // this function receives the address of an error message string
    void Product::message(const char* pText) {
        m_err.message(pText);
    }

    // this query returns true if the ErrorState attribute contains no error message
    bool Product::isClear() const {
        return !m_err;
    }

    // 0/1 argument constructor stores the character received and sets a safe empty state
    Product::Product(const char type) : m_type(type) {
        m_sku[0] = '\0';
        m_unit[0] = '\0';
        m_name = nullptr;
        m_qty_onhand = 0;
        m_qty_needed = 0;
        m_price = 0;
        m_tax = false;
    }

    // custom constructor containing 7 parameters
    Product::Product(const char* sku, const char* name, const char* unit, double price, int qty_n, int qty_h, bool tax) : m_type('N') {    
        if (name != nullptr) {
            // if the name parameter is valid, store all parameters in attributes
            strncpy(m_sku, sku, max_length_sku);
            m_sku[max_length_sku] = '\0';
            
            strncpy(m_unit, unit, max_length_unit);
            m_unit[max_length_unit] = '\0';
            
            m_name = nullptr;
            m_name = new char [strlen(name) + 1];
            strcpy(m_name, name);

            m_price = price;
            m_qty_onhand = qty_h;
            m_qty_needed = qty_n;
            m_tax = tax;
        } else {
            *this = Product();
        }
    }

    // the copy constructor
    Product::Product(const Product& src) : m_type(src.m_type) {
        m_name = nullptr;
        *this = src;
    }

    // the copy assignment operator
    Product& Product::operator=(const Product& src) {
        if (this != &src) {
            strcpy(m_sku, src.m_sku);
            strcpy(m_unit, src.m_unit);
            m_price = src.m_price;
            m_qty_needed = src.m_qty_needed;
            m_qty_onhand = src.m_qty_onhand;
            m_tax = src.m_tax;

            delete [] m_name;
            if (src.m_name != nullptr) {
                m_name = new char[strlen(src.m_name) + 1];
                strcpy(m_name, src.m_name);
            } else {
                m_name = nullptr;
            }
        }
        return *this;
    }

    // receive an integral number of units to be added to the available quantity
    // attributes and returns the updated number of units on hand
    int Product::operator+=(int cnt) {
        if (cnt > 0) {
            m_qty_onhand += cnt;
        }
        return m_qty_onhand;
    }

    // this query returns true if the curring sku string is the same as the parameter
    bool Product::operator==(const char* sku) const {      
        return (strcmp(m_sku, sku) == 0);
    }

    // this query returns true if the current sku is greater than the string stored
    // at the received address
    bool Product::operator>(const char* sku) const {
        return (strcmp(m_sku, sku) > 0);
    }

    // this query returns true if the name of the current object is greater than the name of
    // the Product received as parameter
    bool Product::operator>(const Product& rhs) const {
        return (strcmp(m_name, rhs.m_name) > 0);
    }

    // this query returns the value of the number of the units of product available
    int Product::qtyAvailable() const {
        return m_qty_onhand;
    }

    // returns the value of the attribute storing how many units of product are needed.
    int Product::qtyNeeded() const {
        return m_qty_needed;
    }

    // returns the total cost of all available units of product, including tax
    double Product::total_cost() const {
        double total_w_tax = this->afterTax()*m_qty_onhand;
        double total_wo_tax= this->afterTax()*m_qty_onhand;
        return m_tax ? total_w_tax : total_wo_tax;
    }

    // returns true if the object is in the empty state
    bool Product::isEmpty() const {
        bool strEmpty = m_sku[0] == '\0' && m_unit[0] == '\0' && m_name == nullptr;
        bool numEmpty = m_qty_onhand == 0 && m_qty_needed == 0 && m_price == 0;
        return (strEmpty && numEmpty && !m_tax);
    }
    
    // if interactive, prompt the user asking for values and read and store the data
    std::istream& Product::read(std::istream& in, bool interactive) {
        char SKU[max_length_sku + 1];
        char NAME[max_length_name + 1];
        char UNIT[max_length_unit + 1];
        char taxYN;
        bool TAX;
        double PRICE;
        int QTY_AVAILABLE;
        int QTY_NEEDED;
        ErrorState err;
        
        if (interactive) { 
            // read string information
            cout << right << setw(max_length_label) << "Sku: ";
            in >> SKU;
            cout << setw(max_length_label) << "Name (no spaces): ";
            in >> NAME;
            cout << setw(max_length_label) << "Unit: ";
            in >> UNIT;
            
            // read tax verification
            cout << setw(max_length_label) << "Taxed? (y/n): ";
            in >> taxYN;
            
            if (taxYN == 'y' || taxYN == 'Y') {
                TAX = true;
            } else if (taxYN == 'n' || taxYN == 'N') {
                TAX = false;
            } else {
                in.setstate(ios::failbit);
                err = "Only (Y)es or (N)o are acceptable!";
            }

            // read price
            if (!in.fail()) {
                cout << setw(max_length_label) << "Price: ";
                in >> PRICE;
                if (in.fail()) err = "Invalid Price Entry!";
            }

            // read available qty
            if (!in.fail()) {
                cout << setw(max_length_label) << "Quantity on hand: ";
                in >> QTY_AVAILABLE;
                if (in.fail()) err = "Invalid Quantity Available Entry!";
            }

            // read needed qty
            if (!in.fail()) {
                cout << setw(max_length_label) << "Quantity needed: ";
                in >> QTY_NEEDED;
                if (in.fail()) err = "Invalid Quantity Needed Entry!";
            }

            if (!in.fail()) {
                *this = Product(SKU, NAME, UNIT, PRICE, QTY_NEEDED, QTY_AVAILABLE, TAX);
            } else {
                m_err = err.message();
            }
        } else {
            // read, extract and store the data from cstring 
            in.getline(SKU, max_length_sku, ',');
            in.getline(NAME, max_length_name, ',');
            in.getline(UNIT, max_length_unit, ',');
            char sep;
            in >> PRICE >> sep >> TAX >> sep >> QTY_AVAILABLE >> sep >> QTY_NEEDED;

            *this = Product(SKU, NAME, UNIT, PRICE, QTY_NEEDED, QTY_AVAILABLE, TAX);
        }
        return in;
    }

    // writes the content of the current instance in the stream received as the first parameter
    std::ostream& Product::write(std::ostream& out, int writeMode) const {
        if (!isClear()) {
            out << m_err;
        } else if (!isEmpty()) {
            char namestr[17];
            char ynstr[4];
            if (writeMode == write_table) {
                out << " " << setw(max_length_sku) << m_sku << " | ";
                if (strlen(m_name) > 16) {
                    strncpy(namestr, m_name, 13);
                    namestr[13] = '\0';
                    strcat(namestr, "...");
                } else {
                    strcpy(namestr, m_name);
                }
                out << setw(16) << left << namestr << " | " << setw(10) << m_unit << " | ";
                out << fixed << setw(7) << right << setprecision(2) << m_price << " | ";
                if (m_tax == true) {
                    strcpy (ynstr, "yes");
                } else {
                    strcpy (ynstr, "no");
                }
                out << setw(3) << right << ynstr << " | " << setw(6) << m_qty_onhand << " | ";
                out << setw(6) << m_qty_needed << " |" << setprecision(6);
            }

            if (writeMode == write_human) {
                cout << fixed << right << setw(max_length_label) << "Sku: "<< m_sku << endl;
                cout << setw(max_length_label) << "Name: " << m_name << endl;
                cout << setw(max_length_label) << "Price: " << setprecision(2) << m_price << endl;
                cout << setw(max_length_label) << "Price after Tax: " << this->afterTax() << endl;
                cout << setw(max_length_label) << "Quantity Available: " << m_qty_onhand << " " << m_unit << endl;
                cout << setw(max_length_label) << "Quantity Needed: " << m_qty_needed << " " << m_unit << endl;
            }

            if (writeMode == write_condensed) {
                cout << m_type << "," << m_sku << "," << m_name << "," << m_unit << "," ;
                cout << fixed << setprecision(2) << m_price << "," << m_tax << "," << m_qty_onhand << "," << m_qty_needed;
                cout << setprecision(6);
            }
        } 
        return out;
    }

    // private function: return price after tax
    double Product::afterTax() const {
        return m_tax ? m_price * (1 + tax_rate) : m_price;
    }

    // destructor
    Product::~Product() {
        delete [] m_name;
        m_name = nullptr;
    };
}