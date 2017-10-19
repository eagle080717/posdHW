#ifndef ATOM_H
#define ATOM_H

#include "term.h"

#include <string>
using std::string;

/*
class Term{

public:
  virtual string symbol() const= 0;

  virtual string value() const{
    return symbol();
  };

  virtual bool match(Term & term) {
    return symbol() == term.symbol();
  }


};
*/

class Atom : public Term{
public:
  Atom (string s):_symbol(s){}
  string symbol() const{
    return _symbol;
  }
  string value() const{
    return _symbol;
  }
private:
  string const _symbol;
};

#endif
