#include "song.h"

// Sets key, title, duration, artist, album, and genre information.
// If key.length() < 1 outputs to stderr: "key has length < 1".
// If title.length() < 1 outputs to stderr: "title has length < 1".
// If duration < 1 outputs to stderr: "duration < 1".
// If artist.length() < 1 outputs to stderr: "artist has length < 1"
// If album.length() < 1 outputs to stderr: "album has length < 1"
// If genre.length() < 1 outputs to stderr: "genre has length < 1"
// (Checks are made in order listed.)
Song::Song( const std::string & key, const std::string & title, int duration, 
      const std::string & artist, const std::string & album, const std::string & genre ):
      DigitalMidia{key, title, duration}{
        if(artist.length() < 1){ 
          std::cerr << "artist has length < 1" << std::endl;
          return;
        }
        this -> artist = artist;
        if(album.length() < 1){ 
          std::cerr << "album has length < 1" << std::endl;
          return;
        }
        this -> album = album;
        if(genre.length() < 1){ 
          std::cerr << "genre has length < 1" << std::endl;
          return;
        }
        this -> genre = genre;
      }
Song::~Song(){}
void Song::print( std::ostream & out ) const{
  DigitalMedia::print(out);
  out << "\"" << this->album << "\"" << ", "
  << "\""  << this -> artist << "\"" << ", " 
  << this -> getDuration() << ", " 
  << "\"" << this->genre << "\")";
}

const std::string & Song::getArtist() const{
  return this->artist;
}
const std::string & Song::getAlbum() const{
  return this -> album;
}
const std::string & Song::getGenre() const{
  return this -> genre;
}

// Returns modified output stream. Outputs (key, "title", "album", "artist", duration, "genre").
// (Explicitly surrounds strings that might have whitespace within with double-quotation marks.)
std::ostream & operator<<( std::ostream & out, const Song & s ){
  s.print();
  return out;
}

// Returns modified input stream. Contents of s over-written with information read in if valid,
// where format is "key\ntitle\nduration\nartist\nalbum\ngenre\n". 
// If fails to obtain any of the elements, outputs to stderr the message "failed to read in XXX",
// where XXX is replaced by one of: key, title, duration, artist, album or genre, or if duration
// cannot be successfully converted to an int. In that case s is left unchanged and the
// failbit of the stream is set.
std::istream & operator>>( std::istream & in, Song & s ){
  std::string key, title, artist, album, genre;
  int duration;

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
  if(!UTIL_H::getString(in, artist)){
    std::cerr << "failed to read in artist" << std::endl;
    in.setstate(std::ios::failbit);
    return in;
  }
  if(!UTIL_H::getString(in, album)){
    std::cerr << "failed to read in album" << std::endl;
    in.setstate(std::ios::failbit);
    return in;
  }
  if(!UTIL_H::getString(in, genre)){
    std::cerr << "failed to read in genre" << std::endl;
    in.setstate(std::ios::failbit);
    return in;
  }
  s = Song{key, title, duration, artist, album, genre};
  return in;
}