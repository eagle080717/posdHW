#ifndef ATOM_H
#define ATOM_H

#include "term.h"

#include <string>
using std::string;

class Atom : public Term{
public:
  Atom (string s):_symbol(s){}
  string const symbol() {
    return _symbol;
  }
  string const value() {
    return _symbol;
  }
  bool match(Term &t) {
    return t.symbol() == _symbol;
  }
private:
  string _symbol;
};

#endif
