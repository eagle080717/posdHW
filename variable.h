#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
using std::string;

class Variable{
public:
  Variable(string s):_symbol(s){}
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
  /*bool match(Atom at=NULL, Number n=NULL, Variable v=NULL){

    int type = 3; //variable
    if(at != NULL)  //atom
      type = 1;
    else if(n != NULL)  //number
      type = 2;

    if(_assignable){
      switch(type){
        case 1:
          _value = at.symbol();
          break;
        case 2:
          _value = n.symbol();
          break;
        case 3:
          _value = v.symbol();
          break;
      }
      _assignable = false;
    }

    else
    {
      switch(type){
        case 1:
          return _value == at.symbol();
        case 2:
          return _value == n.symbol();
        case 3:
          return _value == v.symbol();
    }

    return true;
    */
/*
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
      

  }*/

private:
  string _value = NULL;
  bool _assignable = true;
};

#endif