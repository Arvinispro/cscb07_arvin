#ifndef DIGITAL_MEDIA_H
#define DIGITAL_MEDIA_H
#include <string>
#include <iostream>

class DigitalMedia {
    // *** fill in
public:
    // Sets key, title and duration information.
    // If key.length() < 1 outputs to stderr: "key has length < 1".
    // If title.length() < 1 outputs to stderr: "title has length < 1".
    // If duration < 1 outputs to stderr: "duration < 1".
    // (Checks are made in order listed.)
    DigitalMedia( const std::string & key, const std::string & title, int duration );
    virtual ~DigitalMedia();

    // Concrete subclasses use this to invoke their output operator so that Library
    // container can successfully print its contents using the iterator.
    virtual void print( std::ostream & out ) const = 0;

    const std::string & getKey() const;
    const std::string & getTitle() const;
    int getDuration() const;
};

#endif
