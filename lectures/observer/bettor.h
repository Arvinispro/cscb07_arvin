#ifndef BETTOR_H
#define BETTOR_H
#include <string>
#include "observer.h"
#include "horserace.h"

class Bettor: public Observer {
  HorseRace *subject;
  const std::string name;
  const std::string myHorse;

 public:
  Bettor(HorseRace *hr, std::string name, std::string horse);
  void notify() override;
  ~Bettor();
};

#endif
