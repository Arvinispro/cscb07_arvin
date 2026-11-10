#include "subject.h"

Subject::Subject() {}
Subject::~Subject() {}

void Subject::attach(Observer *o) {
  if (numObservers < maxObservers) observers[numObservers++] = o;
}

void Subject::detach(Observer *o) {
  for (int i = 0; i < numObservers; ++i) {
    if (observers[i] == o) {
      // Shift the remaining observers down to fill the gap
      for (int j = i; j + 1 < numObservers; ++j) observers[j] = observers[j + 1];
      --numObservers;
      break;
    }
  }
}

void Subject::notifyObservers() const {
  for (int i = 0; i < numObservers; ++i) observers[i]->notify();
}
