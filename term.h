#ifndef TERM_H
#define TERM_H

#include <string>
using std::string;

class Term{
public:
  virtual const string symbol() = 0;
  //virtual const string value() = 0;
  //virtual bool match(Term &term) = 0;
  virtual const string value() {
    return symbol();
  }
  virtual bool match(Term &term) {
    return symbol() == term.symbol();
  }
};

#endif