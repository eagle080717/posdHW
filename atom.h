#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "variable.h"
#include "number.h"
using std::string;
//class Variable;
//class Number;
class Atom {
public:
	  Atom (string s):_symbol(s) {}
	  //bool operator ==(Atom a) {return _symbol == a._symbol;}
	  string _symbol;
	  string symbol(){ return _symbol; }
	  string value(){ return _value; }

	  bool match(Atom &at){
	    return at.symbol() == _symbol;
  	  }
  	  bool match(Number &n){
  	  	return false;
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