/***********************************************************************
// OOP244 Final Project Milestone 1
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-7
// File: Date.h
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>

namespace ama {
    // predifine constants as integers
    // predifine year range
    const int min_year = 2019;
    const int max_year = 2028;
    
    // predifine error status as integers
    const int no_error = 0;
    const int error_year = 1;
    const int error_mon = 2;
    const int error_day = 3;
    const int error_invalid_operation = 4;
    const int error_input = 5;

    // initialize class members
    class Date {

        // iniitalize private instant variables and member functions    
        int m_year, m_month, m_day, m_status;
        int mdays(int year, int mon) const;
        void status(int newStatus);
    // initialize public member functions
    public:
        Date();
        Date(int year, int month, int day);
        int status() const;
        void clearError();
        bool isGood() const;
        Date& operator+=(int days);
        Date& operator++();
        Date operator++(int);
        Date operator+(int days) const;
        bool operator==(const Date& rhs) const;
        bool operator!=(const Date& rhs) const;
        bool operator<(const Date& rhs) const;
        bool operator>(const Date& rhs) const;
        bool operator<=(const Date& rhs) const;
        bool operator>=(const Date& rhs) const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
    };
    // initialize helper functions
    std::ostream& operator<<(std::ostream& os, const Date& d);
    std::istream& operator>>(std::istream& is, Date& d);
}

#endif

