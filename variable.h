#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"

#include <string>
using std::string;

class Variable : public Term{
public:
  Variable(string s):_symbol(s),_value(s){} 
  string const symbol(){ return _symbol; }
  string const value(){
    if(_var != NULL)
      return _var->value();
    /*if(_assignable && _var != NULL)
      return _var->value();
    else if(_var != NULL)
      return _var->value();
    */
    else if(_t != NULL)
      return _t->value();
    else
      return _value;
  }

  /*
  bool match(Term &t){
    if(_assignable){
      if(_var != NULL){
        _var->match(t);
        return _var->value() == t.value();
      }
      else {
        _value = t.symbol();
        _assignable = false;
      }
    }
    return t.symbol() == _value;   
  }
  */
  bool match(Term &t){
    if(_assignable){
      if(_var != NULL){
        _var->match(t);
        return _var->value() == t.value();
      }
      else {
        _t = &t;
        _assignable = false;
      }
    }
    return _t->value() == t.value();
  }

  bool match(Variable &v){
    if(v.symbol() == _symbol)
      return true;
    if(_var == NULL){
      _var = &v;
    } else {
      _var->match(v);
    }
    return _var->value() == v.value();
  }

private:
  string const _symbol;
  string _value;
  Term *_t = NULL;
  Variable *_var = NULL;
  bool _assignable = true;
};

#endif