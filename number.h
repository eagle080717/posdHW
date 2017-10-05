#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "atom.h"
using namespace std;

class Number{
public:
  Number(int s):_symbol(to_string(s)){}
  string const _symbol;
  string symbol(){ return _symbol; }
  string value(){ return _value; }

  template <class matchTmp> 
  bool match(matchTmp &arg){
    if(_assignable){
      _value = arg.symbol();
      _assignable = false;
    } 
    return arg.symbol() == _value;
  }

private:
  string _value = "0";
  bool _assignable = true;
};

#endif