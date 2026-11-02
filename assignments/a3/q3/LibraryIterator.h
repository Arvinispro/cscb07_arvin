#ifndef LIBRARY_ITERATOR_H
#define LIBRARY_ITERATOR_H
#include "Library.h"

class LibraryIterator {
    friend class Library;
    // *** fill in

    explicit LibraryIterator( /*** fill in ***/ );  // Private constructor

public:
    DigitalMedia * operator*() const;
    LibraryIterator operator++();
    bool operator==( const LibraryIterator& other ) const;
    bool operator!=( const LibraryIterator& other ) const;    
};

#endif
