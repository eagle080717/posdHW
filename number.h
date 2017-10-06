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

  //template <class matchTmp> 
  bool match(Atom at=NULL, Number n=NULL, Variable v=NULL){
    if(at != NULL)
      return false;

    else if(v != NULL)
      if(_assignable){
        _value = v.symbol();
        _assignable = false;
      }
      return v.symbol() == _value;

    else
      return n.symbol() == _symbol;
    //return arg.symbol() == _value;
  }

private:
  string _value = NULL;
  bool _assignable = true;
};

#endif