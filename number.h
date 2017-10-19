#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"

#include <string>
using namespace std;

//class Atom;
//class Variable;
class Number : public Term{
public:
  Number(double v):_value(to_string(v)){}
  string symbol(){ return _value; }
  string value(){ return _value; }

  bool match(Term &t){
    return t.value() == _value;
  }
/*
  bool match(Variable &v){
    if(_assignable && v._assignable){
          v._value = _value;
          v._assignable = false;
          
          _symbol = v.symbol();
          _assignable = false;       
      }
    return v.symbol() == _symbol;
  }
*/
  
private:
  string _symbol;
  string const _value;
};

#endif