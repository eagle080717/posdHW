#ifndef STRUCT_H
#define STRUCT_H

#include "atom.h"
#include "list.h"
#include <vector>
#include <string>

using std::string;

class Struct : public Term
{
public:
  Struct(Atom name, std::vector<Term *> args):_name(name), _args(args) {}

  Term *args(int index) {
    return _args[index];
  }

  int arity() {
    return _args.size();
  }

  Atom name() {
    return _name;
  }

  string const symbol(){
    if(_args.empty())
      return _name.symbol() + "(" + ")";  
    string ret = _name.symbol() + "(";
    for(int i = 0; i < _args.size() - 1 ; i++){
      ret += _args[i]-> symbol() + ", ";
    }
    ret += _args[_args.size()-1]-> symbol() + ")";
    return ret;
  }

  string const value(){
    if(!_args.empty()){
      string ret =_name.symbol() + "(";
      for(int i = 0; i < _args.size() - 1 ; i++){
        ret += _args[i]-> value() + ", ";
      }
      ret += _args[_args.size()-1]-> value() + ")";
      return ret;
    } else 
      return _name.symbol() + "(" + ")";  
  }

  bool match(Term &term){
    Struct * ps = dynamic_cast<Struct *>(&term);
    if (ps){
      if (!_name.match(ps->_name))
        return false;
      if(_args.size()!= ps->_args.size())
        return false;
      for(int i=0;i<_args.size();i++){
        if(_args[i]->symbol() != ps->_args[i]->symbol())
            return false;
      }
      return true;
    }
    return false;
  }

  bool match(List &l){
    return false;
  }

private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
