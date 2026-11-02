#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <string>

// Attempts to read in a string until newline is reached. Returns false if fails to obtain
// a non-empty string; otherwise returns true and parameter s is modified.
bool getString( std::istream & in, std::string & s );

// Attempts to read in an integer from input stream in. Returns false if fails to obtain an integer,
// or value cannot be converted to an integer or value < 1; otherwise returns true and parameter 
// i is modified.
bool getInteger( std::istream & in, int & i );

#endif
