/***********************************************************************
// OOP244 Final Project Milestone 1
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-7
// File: Date.cpp
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <iomanip>
#include "Date.h"
using namespace std;

namespace ama {
    // default constructor
    Date::Date() {
        m_year = 0; m_month = 0; m_day = 0; 
        status(no_error);
    }

    // custom constructor with three arguments to store valid date
    Date::Date(int year, int month, int day) {
        if (year > max_year || year < min_year) {
            *this = Date();
            status(error_year);
        } else if (month > 12 || month < 1) {
            *this = Date();
            status(error_mon);
        } else if (day > mdays(year, month) || day < 1) {
            *this = Date();
            status(error_day);
        } else {
            m_year = year;
            m_month = month;
            m_day = day;
            status(no_error);
        }
    }

    // set the status of the date object to the value of the parameter
    void Date::status(int newStatus) {
        m_status = newStatus;
    }

    // return the number of days in a given month of a given year
    int Date::mdays(int year, int mon) const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    // return an integer representing the status of the current obejct
    int Date::status() const {
        return m_status;
    }

    // reset the status of an object to no_error
    void Date::clearError() {
        this->status(no_error);
    }

    // verify an object sotres a valid date and is not in error mode
    bool Date::isGood() const {
        return (status() == no_error && m_day != 0 && m_month != 0 && m_year != 0);
    }

    // implement a modifier that adds the number of dyas to the stored date
    Date& Date::operator+=(int days) {
        // if current object is in error mode or the safe empty state
        // it does not update the sotred date and changes the status to operation error mode
        if (m_status != no_error || *this == Date()) {
            status(error_invalid_operation);
        // if the date is not valid after addition, set the operation error status
        } else if (m_day + days > mdays(m_year, m_month) || m_day + days < 1) {
            status(error_invalid_operation);
        } else {
            m_day += days;
        }
        return *this;
    }

    // implement a modifier that adds one day to the stored date (prefix)
    Date& Date::operator++() {
        if (m_status != no_error || *this == Date() || m_day + 1 > mdays(m_year, m_month)) {
            status(error_invalid_operation);
        } else {
            ++m_day;
        }
        return *this; // return the updated current instance
    }

    // implement a modifier that adds one day to the stored date (postfix)
    Date Date::operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }

    // inplement a query that adds the number of days to the store date
    // and store the result as a new object
    Date Date::operator+(int days) const {
        // create a temp object as a copy
        Date temp = *this;
        // if current object is in error mode or the safe empty state
        // it does not update the sotred date and changes the status to operation error mode
        if (m_status != no_error || *this == Date()) {
            temp.status(error_invalid_operation);
        // if the date is not valid after addition, set the operation error status to temp
        } else if (m_day + days > mdays(m_year, m_month) || m_day + days < 1) {
            temp.status(error_invalid_operation);
        } else {
            temp.m_day = m_day + days;
        }
        return temp;
    }

    // implement a query that verifies two objects store the same date
    bool Date::operator==(const Date& rhs) const {
        return (m_year==rhs.m_year && m_month==rhs.m_month && m_day==rhs.m_day);
    }

    // implement a query that verifies two objects store two different dates
    bool Date::operator!=(const Date& rhs) const {
        return !(*this==rhs);
    }

    // implement a query that verifies the current object is before the one stored in rhs
    bool Date::operator<(const Date& rhs) const {
        bool less = false;
        if (m_year < rhs.m_year) {
            less = true;
        } else if (m_year == rhs.m_year && m_month < rhs.m_month) {
            less = true;
        } else if (m_year == rhs.m_year && m_month == rhs.m_month && m_day < rhs.m_day) {
            less = true;
        } 
        return less;
    }
    
    // implement a query that verifies the current object is after the one stored in rhs
    bool Date::operator>(const Date& rhs) const {
        return !(*this == rhs || *this < rhs);
    }

    // implement a query that verifies the current object is before or equal to the one stored in rhs
    bool Date::operator<=(const Date& rhs) const {
        return (*this == rhs || *this < rhs);
    }

    // implement a query that verifies the current object is after or equal to the one stored in rhs
    bool Date::operator>=(const Date& rhs) const {
        return (*this == rhs || *this > rhs);
    }

    // implement a modifier that reads from an input stream a date in a given format
    istream& Date::read(istream& is) { 
        char cut;

        int year, month, day;
        is >> year >> cut >> month >> cut >> day;

        if (is.fail()) {
            *this = Date();
            status(error_input);
        } else {
            *this = Date(year, month, day);
        }

        return is;
    }

    // implement a query that writes to std::ostream object in a given format
    ostream& Date::write(ostream& os) const {
        char cut = '/';

        os << setfill('0') << setw(4) << right << m_year << cut
        << setw(2) << m_month << cut
        << setw(2) << m_day << setfill(' ') << left;
        
        return os;
    }

    // implement two free helper functions
    // this function prints the date to the first parameter
    ostream& operator<<(ostream& os, const Date& d) {
        d.write(os);
        return os;
    }
    // this function reads the date from the first parameter
    istream& operator>>(istream& is, Date& d) {
        d.read(is);
        return is;
    }

}