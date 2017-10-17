#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
//#include "atom.h"
using std::string;

//class Atom;
//class Number;

class Variable : public Term{
public:
  Variable(string s):_symbol(s){}
  string const _symbol;
  string symbol(){ return _symbol; }
  string value(){ return _value; }

  /*template <class matchTmp> 
  bool match(matchTmp &arg){
    if(_assignable){
        _value = arg.symbol();
        _assignable = false;
      }
      return arg.symbol() == _value;
  }
  */

  bool match(Term &t){
    if(_assignable){
      _value = t.symbol();
      _assignable = false;
    }
    return t.symbol() == _value;
  }

  bool _assignable = true;
  string _value;
//private:
  
  //bool _assignable = true;
};

#endif