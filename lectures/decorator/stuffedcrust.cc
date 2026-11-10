#include "stuffedcrust.h"
#include <string>
using namespace std;

StuffedCrust::StuffedCrust(Pizza *p): Decorator{p} {}

float StuffedCrust::price() const { return component->price() + 2.69; }

string StuffedCrust::description() const {
 return component->description() + " with stuffed crust";
}

