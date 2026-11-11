#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include <iostream>
#include "DigitalMedia.h"

class Video: public DigitalMedia {
    // *** fill in
    std::string channel;
    int resolution;
public:
    // Sets key, title, duration, channel, and resolution information.
    // If key.length() < 1 outputs to stderr: "key has length < 1".
    // If title.length() < 1 outputs to stderr: "title has length < 1".
    // If duration < 1 outputs to stderr: "duration < 1".
    // If channel.length() < 1 outputs to stderr: "channel has length < 1".
    // If resolution < 1 outputs to stderr: "resolution < 1".
    // (Checks are made in order listed.)
    Video( const std::string & key, const std::string & title, int duration,
           const std::string & channel, int resolution );
    virtual ~Video();
    virtual void print( std::ostream & out ) const override;

    const std::string & getChannel() const;
    int getResolution() const;
};

// Returns modified output stream. Outputs (key, "title", "channel", duration, resolutionp).
// (Explicitly surrounds strings that might have whitespace within with double-quotation marks;
// the resolution is followed by the letter p, e.g. 1080p.)
std::ostream & operator<<( std::ostream & out, const Video & v );

// Returns modified input stream. Contents of v over-written with information read in if valid,
// where format is "key\ntitle\nduration\nchannel\nresolution\n". 
// If fails to obtain any of the elements, outputs to stderr the message "failed to read in XXX",
// where XXX is replaced by one of: key, title, duration, channel or resolution, or if duration
// or resolution cannot be successfully converted to a positive int. In that case v is left
// unchanged and the failbit of the stream is set.
std::istream & operator>>( std::istream & in, Video & v );

#endif
