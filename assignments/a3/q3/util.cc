#include "util.h"
#include <iostream>
#include <string>

// *** add any other includes you need

bool getString( std::istream & in, std::string & s ) {
    getline( in, s );

    // *** If getline fails to obtain the necessary argument, or the string
    // *** obtained is empty, return false (leaving s unchanged).

    return true;
} // getString

bool getInteger( std::istream & in, int & i ) {
    std::string s;
    getline( in, s );

    // *** If getline fails to obtain the necessary argument, or the string cannot
    // *** be converted to an integer, or the value is < 1, return false (leaving
    // *** i unchanged).

    i = std::stoi(s);
    return true;
} // getInteger
