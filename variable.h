#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include "list.h"
#include <string>
using std::string;

class Variable : public Term{
public:
  Variable(string s):_symbol(s),_value(s){} 
  string const symbol(){ return _symbol; }
  string const value(){
    if(_var != NULL)
      return _var->value();
    else if(_t != NULL)
      return _t->value();
    else if(_l != NULL)
      return _l->value();
    else
      return _value;
  }

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

  bool match(List &l){
    if(_l != NULL){
      if(_l->value() == l.value())
        return true;
    }
    string elements = l.symbol();
    if(elements.find(_symbol) != string::npos){
      return false;
    }
    _l = &l;
    return _l->value() == l.value();
  }

private:
  string const _symbol;
  string _value;
  Term *_t = NULL;
  Variable *_var = NULL;
  List *_l = NULL;
  bool _assignable = true;
};

#endif