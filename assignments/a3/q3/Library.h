#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <iostream>
class DigitalMedia;

class LibraryIterator;   // defined in LibraryIterator.h (it needs Library::Node)

class Library {
    friend class LibraryIterator;

    // *** fill in
    struct Node{
        DigitalMedia *media;
        Node *next;
    };
    Node *head;
public:
    Library();                       // Creates empty library.
    ~Library();                      // Destroys all items in library.
    LibraryIterator begin() const;   // Iterator set to beginning of library contents.
    LibraryIterator end() const;     // Iterator set past end of library contents.

    // Stores item, indexed by key. If key already exists outputs to stderr
    // "key KKKK already exists in library" and item not stored (and is deleted).
    void add( DigitalMedia* m );    

    // Remove item and delete media if find key value else does nothing.
    void remove( const std::string& key );  

    // Returns pointer to item, or nullptr if not there.
    DigitalMedia * find( const std::string& key ) const; 
};

// Returns modified output stream. Stream contains the header "Library:\n" and the library
// contents, ordered by key. Each object is output using the appropriate output operator
// for the underlying object type, one per line and starting with a tab character.
std::ostream & operator<<( std::ostream& out, const Library& library );

// Returns modified input stream. Contents of library modified with information read in, 
// where the character 's' on a line specifies a Song is to be read next, while 'v'
// indicates that a Video is to be read in next. Reading continues until EOF is reached or an
// error occurs. If the item that follows cannot be read, nothing is added for it, reading
// stops, and the failbit of the stream is set. Outputs "invalid media type" to stderr followed
// by what type was read if doesn't get either 's' or 'v' (and then stops reading as well).
std::istream & operator>>( std::istream& in, Library& library );

#endif
