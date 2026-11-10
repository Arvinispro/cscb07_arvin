#include "dippingsauce.h"
#include <string>
using namespace std;

DippingSauce::DippingSauce(string flavour, Pizza *p):
  Decorator{p}, flavour{flavour} {}

float DippingSauce::price() const { return component->price() + .30; }

string DippingSauce::description() const {
 return component->description() + " with " + flavour + " dipping sauce";
}

