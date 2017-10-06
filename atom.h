#ifndef ATOM_H
#define ATOM_H

#include <string>

using std::string;

class Atom {
public:
	  Atom (string s):_symbol(s) {}
	  //bool operator ==(Atom a) {return _symbol == a._symbol;}
	  string _symbol;
	  string symbol(){ return _symbol; }
	  string value(){ return _value; }

	  bool match(Atom at=NULL, Number n=NULL, Variable v=NULL){
	    if(n != NULL)
	      return false;

	    else if(v != NULL)
	      if(_assignable){
	        _value = v.symbol();
	        _assignable = false;
	      }
	      return v.symbol() == _value;

	    else
	      return at.symbol() == _symbol;

  	  }
private:1`
	string _value = NULL;
	bool _assignable = true;
};

#endif