#ifndef NUMBER_H
#define NUMBER_H

#include <string>
using namespace std;

class Atom;
class Variable;
class Number : public Term{
public:
  Number(double v):_value(to_string(v)){}
  string const _value;

  string symbol(){ return _symbol; }
  string value(){ return _value; }
/*
  bool match(Atom &at){
    return false;
  }

  bool match(Number &n){
    return n.value() == _value;
  }
*/
  bool match(Term &t){
    return t.value() == _value;
  }

  bool match(Variable &v){
    if(_assignable && v._assignable){
          v._value = _value;
          v._assignable = false;
          
          _symbol = v.symbol();
          _assignable = false;       
      }
    return v.symbol() == _symbol;
  }


private:
  string _symbol;
  bool _assignable = true;
};

#endif