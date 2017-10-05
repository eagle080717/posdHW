#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
using std::string;

class Variable{
public:
  Variable(string s):_symbol(s){}
  string const _symbol;
  string value(){ return _value; }
  bool assignVal(Atom atom){
    if(_assignable){
      _value = atom._symbol ;
      _assignable = false;
    } 
    return atom._symbol == _value;
  }
  bool match(Atom atom){
    return assignVal(atom);
  }

private:
  string _value;
  bool _assignable = true;
};

#endif