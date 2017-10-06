#ifndef NUMBER_H
#define NUMBER_H

#include <string>
//#include "atom.h"
//#include "variable.h"
using namespace std;

class Atom;
class Variable;
class Number{
public:
  Number(int s):_symbol(to_string(s)){}
  string const _symbol;

  string symbol(){ return _symbol; }
  string value(){ return _value; }

  bool match(Atom &at){
    return false;
  }

  bool match(Number &n){
    return n.symbol() == _symbol;
  }

  bool match(Variable &v){
    if(_assignable){
        if(!v._assignable){
          return v.value() == _symbol;
        } else {
          v._value = _symbol;
          v._assignable = false;
          
        
          _value = v.symbol();
          _assignable = false;
        }
      }
    return v.symbol() == _value;
  }


private:
  string _value;
  bool _assignable = true;
};

#endif