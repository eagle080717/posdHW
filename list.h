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
  	
  }

  bool match(List &l){
    if(l.value() == this->value())
      return true;
    else {
      if(l.ListSize() != _elements.size())
        return false;
      for(auto iter1=_elements.begin(), iter2=_elements.begin(); iter1 != _elements.end(); iter1++, iter2++){
        if((*iter1)->symbol() != (*iter2)->symbol())
          if((*iter1)->symbol() != (*iter2)->value())
            if((*iter2)->symbol() != (*iter1)->value())
              if((*iter2)->value() != (*iter1)->value())
                return false;
      }
    }
    return true;
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

  int ListSize() const {
    return _elements.size();
  }

private:
  vector<Term *> _elements;
};

#endif