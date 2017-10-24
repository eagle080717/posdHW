#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

class List : public Term {
public:
  string symbol() const {
  	// To do: sorting the numbers
  	if(!_elements.empty()){
  		string str = "[";
  		for(auto iter=_elements.begin(); iter != iter.end(); ++iter){
  			str += *iter.symbol();
  			str += ", ";
  		}
  		//str = str.substr(0, str.size()-2);
  		str.pop_back();
  		str.pop_back();
  		str += "]";
  		return str;
  	}
  	else	
  		return "[]";
  }

  string value() const {
  	// To do: sorting the numbers
  	if(!_elements.empty()){
  		string str = "[";
  		for(auto iter=_elements.begin(); iter != iter.end(); iter++){
  			str += *iter.value();
  			str += ", ";
  		}
  		str.pop_back();
  		str.pop_back();
  		str += "]";
  		return str;
  	}
  	else	
  		return "[]";
  }

  bool match(Term &term) {
  	//Check whether is a list or not, if not, then return false, otherwise, comparing the list element
  	
  }

public:
  List (): _elements() {}

  List (vector<Term *> const &elements):_elements(elements){}

  Term * head() const {
  	auto iter = _elements.begin();
  	return *iter;
  }

  List * tail() const {
  	return _elements.back();
  }

private:
  vector<Term *> _elements;

};

#endif