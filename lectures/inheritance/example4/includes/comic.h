#ifndef COMIC_H
#define COMIC_H
#include <string>
#include "book.h"

class Comic: public Book {
  std::string hero;
 public:
  Comic(const std::string &title, const std::string &author, int numPages, const std::string &hero);
  bool isItHeavy() const override;
  std::string getHero() const;

  bool favourite() const override;
};

#endif
