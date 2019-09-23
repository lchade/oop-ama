/***********************************************************************
// OOP244 Final Project Milestone 2
// -----------------------------------------------------------
// No.: 143381184
// Name: Chade Li
// Date: 2019-3-14
// File: ErrorState.h
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>

namespace ama {
    // initialize class members
    class ErrorState {
        // iniitalize private instant variables and member functions    
        char* m_errorMessage;
    // initialize public member functions
    public:
        explicit ErrorState(const char* errorMessage = nullptr);
        
        // this class should not allow copy of any ErrorState object
        // or copy assignment
        ErrorState(const ErrorState& other) = delete;
        ErrorState& operator=(const ErrorState& other) = delete;
        
        ~ErrorState();
        operator bool() const;
        ErrorState& operator=(const char* pText);
        void message(const char* pText);
        const char* message() const;
    };
    // initialize helper functions
    std::ostream& operator<<(std::ostream& os, const ErrorState& err);
}

#endif
