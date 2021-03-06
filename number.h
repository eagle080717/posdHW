#ifndef NUMBER_H
#define NUMBER_H

#include "term.h"
#include "list.h"
#include "variable.h"
#include <string>
using namespace std;

class Number : public Term{
public:
  Number(double v):_value(to_string(v)){ 
    _value.erase(_value.find_last_not_of('0')+1, string::npos);
    int last = _value.length() - 1;
    if(_value[last] == '.')
      _value.pop_back();
  }
  string const symbol(){ return _value; }
  string const value(){ return _value; }

  bool match(Term &t){
    return t.value() == _value;
  }
  bool match(List &l){
    return false;
  }

  bool match(Variable &v){
    return v.match(*this);
  }

  
private:
  //string _symbol;
  string _value;
};

#endif