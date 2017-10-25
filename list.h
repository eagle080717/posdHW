#ifndef LIST_H
#define LIST_H

#include "term.h"
#include <string>
#include <vector>
#include <stdexcept>
using std::vector;
using std::string;

class List : public Term {
public:
  //List (): _elements() {}
  List (vector<Term *> const &elements):_elements(elements){}
  string const symbol() {
  	// To do: sorting the numbers
  	if(!_elements.empty()){
  		string str = "[";
  		for(auto iter=_elements.begin(); iter != _elements.end(); ++iter){
  			str += (*iter)->symbol();
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

  string const value() {
  	// To do: sorting the numbers
  	if(!_elements.empty()){
  		string str = "[";
  		for(auto iter=_elements.begin(); iter != _elements.end(); iter++){
  			str += (*iter)->value();
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

  bool match(List &l){
    if(l.value() == this->value())
      return true;
    else
      return false;
  }

  Term *head() const {
    if(_elements.empty())
      throw std::out_of_range("Accessing head in an empty list");

  	return _elements.front();
  }

  List *tail() const {
    if(_elements.empty())
      throw std::out_of_range("Accessing tail in an empty list");

    vector<Term *> tmpVec;
    for(auto iter=_elements.begin()+1; iter != _elements.end(); iter++){
        tmpVec.push_back(*iter);
    }

    return new List(tmpVec);                                        
  }

private:
  vector<Term *> _elements;
};

#endif