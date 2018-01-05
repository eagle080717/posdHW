#ifndef EXP_H
#define EXP_H

#include "atom.h"

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getExpress() = 0;
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }

  bool evaluate(){
    return _left->match(*_right);
  }

  string getExpress(){
    if(!evaluate())
      return "false";
    else if(_left->symbol() == _right->symbol())
      return "true";
    else {
      string result = _left->symbol();
      result += " = ";
      result += _right->value();
      return result;
    }
  }

private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }

  string getExpress(){
    if(_left->getExpress() == "true" && _right->getExpress() == "true")
      return "true";
    else if(_left->getExpress() == "false" || _right->getExpress() == "false")
      return "false";
    else if(_left->getExpress() == "true")
      return _right->getExpress();
    else if(_right->getExpress() == "true")
      return _left->getExpress();
    else {
      if(_left->getExpress() == _right->getExpress() || _left->getExpress().find(_right->getExpress()) != string::npos)
        return _left->getExpress();
      string result = _left->getExpress();
      result += ", ";
      result += _right->getExpress();
      return result;
    }
  }

private:
  Exp * _left;
  Exp * _right;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }

  string getExpress(){
      string result = _left->getExpress();
      if(result != "false"){
        string result_R = _right->getExpress();
        if(result_R != "false"){
          result += "; ";
          result += result_R;
        }
      } else {
        result = _right->getExpress();
      }
      return result;
  }

private:
  Exp * _left;
  Exp * _right;
};
#endif
