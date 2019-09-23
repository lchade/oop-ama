/***********************************************************************
// OOP244 Final Project Milestone 2
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-14
// File: ErrorState.cpp
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cstring>
#include "ErrorState.h"
using namespace std;

namespace ama {
    // no/one argument constructor receives the address that holds error message
    ErrorState::ErrorState(const char* errorMessage) {
        // if the address is nullptr or points to an empty string,
        // put the object in the safe empty state
        if (errorMessage == nullptr || strlen(errorMessage) == 0) {
            m_errorMessage = nullptr;
        } else {
        // if the address points to a non-empty message,
        // allocate the memory for that message and copy the message into the memory
            m_errorMessage = new char [strlen(errorMessage) + 1];
            strcpy(m_errorMessage, errorMessage);
        }
    }
    
    // implement the destructor
    ErrorState::~ErrorState() {
        delete [] m_errorMessage;
        m_errorMessage = nullptr;
    }
    
    // this function returns true if the current instance is storing a valid message
    ErrorState::operator bool() const {
        return (m_errorMessage != nullptr);
    }

    // a function that stores the current object as a copy the text received in the parameter
    // and return the current object
    // this function handles the parameter in the same way as the constructor
    ErrorState& ErrorState::operator=(const char* pText) {
            delete [] m_errorMessage;
            m_errorMessage = nullptr;
        if (pText == nullptr || strlen(pText) == 0) {
            m_errorMessage = nullptr;
        } else {
            m_errorMessage = new char [strlen(pText) + 1];
            strcpy(m_errorMessage, pText);
        }
        return *this;
    }
    
    // a function that stores a copy the text received in the parameter
    // this function handles the parameter in the same way as the constructor
    void ErrorState::message(const char* pText) {
        *this = pText;
    }
    
    // a query that returns the address of the message stored in the current object
    const char* ErrorState::message() const {
        return m_errorMessage;
    }

    // a helper function that prints the text stored in an ErrorState object to a stream
    std::ostream& operator<<(std::ostream& os, const ErrorState& err) {
        // if the object is in safe empty state, this does nothing
        if (err) {
            os << err.message();
        }
        return os;
    }
}
