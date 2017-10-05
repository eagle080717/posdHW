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
	  bool matchFunc(Atom atom){
	      return atom._symbol == _symbol;
	  }
	  bool match(Atom atom){
	      return matchFunc(atom);
	  }
private:
	string _value;
};

#endif