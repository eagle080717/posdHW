#ifndef ATOM_H
#define ATOM_H

#include "term.h"
#include "list.h"
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
  bool match(List &l){
    return false;
  }
private:
  string _symbol;
};

#endif
