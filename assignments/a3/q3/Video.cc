#include "Video.h"
#include "util.h"
// Sets key, title, duration, channel, and resolution information.
// If key.length() < 1 outputs to stderr: "key has length < 1".
// If title.length() < 1 outputs to stderr: "title has length < 1".
// If duration < 1 outputs to stderr: "duration < 1".
// If channel.length() < 1 outputs to stderr: "channel has length < 1".
// If resolution < 1 outputs to stderr: "resolution < 1".
// (Checks are made in order listed.)
Video::Video( const std::string & key, const std::string & title, int duration,
        const std::string & channel, int resolution ): DigitalMedia{key, title, duration}{
          if(channel.length() < 1){ 
            std::cerr << "channel has length < 1" << std::endl;
            return;
          }
          this -> channel = channel;
          if(resolution < 1){ 
            std::cerr << "resolution < 1" << std::endl;
            return;
          }
          this -> resolution = resolution;
        }
Video::~Video(){}
void Video::print( std::ostream & out ) const{
  DigitalMedia::print(out);
  out << "\"" << this->channel << "\"" << ", "
  << this -> getDuration()  << ", " 
  << this -> resolution  << "p) " ;
}

const std::string & Video::getChannel() const{
  return this -> channel;
}
int Video::getResolution() const{
  return this -> resolution;
}

// Returns modified output stream. Outputs (key, "title", "channel", duration, resolutionp).
// (Explicitly surrounds strings that might have whitespace within with double-quotation marks;
// the resolution is followed by the letter p, e.g. 1080p.)
std::ostream & operator<<( std::ostream & out, const Video & v ){
  v.print(out);
  return out;
}

// Returns modified input stream. Contents of v over-written with information read in if valid,
// where format is "key\ntitle\nduration\nchannel\nresolution\n". 
// If fails to obtain any of the elements, outputs to stderr the message "failed to read in XXX",
// where XXX is replaced by one of: key, title, duration, channel or resolution, or if duration
// or resolution cannot be successfully converted to a positive int. In that case v is left
// unchanged and the failbit of the stream is set.
std::istream & operator>>( std::istream & in, Video & v ){
  std::string key, title, channel;
  int duration, resolution;

  if(!UTIL_H::getString(in, key)){
    std::cerr << "failed to read in key" << std::endl;
    in.setstate(std::ios::failbit);
    return in;
  }
  if(!UTIL_H::getString(in, title)){
    std::cerr << "failed to read in title" << std::endl;
    in.setstate(std::ios::failbit);
    return in;
  }
  if(!UTIL_H::getInteger(in, duration)){
    std::cerr << "failed to read in duration" << std::endl;
    in.setstate(std::ios::failbit);
    return in;
  }
  if(!UTIL_H::getString(in, channel)){
    std::cerr << "failed to read in channel" << std::endl;
    in.setstate(std::ios::failbit);
    return in;
  }
  if(!UTIL_H::getInteger(in, resolution)){
    std::cerr << "failed to read in resolution" << std::endl;
    in.setstate(std::ios::failbit);
    return in;
  }
  v = Video{key, title, duration, channel, resolution};
  return in;
}