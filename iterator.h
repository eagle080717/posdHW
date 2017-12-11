#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include "struct.h"
#include "list.h"

class Iterator {
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual Term* currentItem() const = 0;
  virtual bool isDone() const = 0;
};

class NullIterator :public Iterator{
public:
  NullIterator(Term *n){}
  void first(){}
  void next(){}
  Term * currentItem() const{
    return nullptr;
  }
  bool isDone() const{
    return true;
  }
};

class StructIterator :public Iterator {
public:
  StructIterator(Struct *s): _index(0), _s(s) {}
  friend class Struct;
  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _s->args(_index);
  }

  bool isDone() const {
    return _index >= _s->arity();
  }

  void next() {
    _index++;
  }


private:
  int _index;
  Struct* _s;
};

class ListIterator :public Iterator {
public:
  ListIterator(List *list): _index(0), _list(list) {}

  void first() {
    _index = 0;
  }

  Term* currentItem() const {
    return _list->args(_index);
  }

  bool isDone() const {
    return _index >= _list->arity();
  }

  void next() {
    _index++;
  }

private:
  int _index;
  List* _list;
};

/*
template <class T>
class DFSIterator :public Iterator<T>{
public:
  DFSIterator(Iterator *it): _it(it) {}

  void first() {
    _index = 0;
    _it->first();

    //while(!_it->isDone()){
      _args.push_back(_it->currentItem());
      /*Iterator *itPtr = _it->currentItem()->createIterator();
      itPtr->first();
      while(!itPtr->isDone()){
        _args.push_back(_itPtr->currentItem());
        itPtr->next();
      }
      _it->next();  
    //}

  }

  T currentItem() const {
    return _args[_index];
  }

  bool isDone() const {
    return _index >= _args.size();
  }

  void next() {
    _index++;
  }

  //int sz(){return _args.size();  }
private:
  Iterator* _it;
  int _index;
  std::vector<Term *> _args; //tmp stack
};

template <class T>
class BFSIterator :public Iterator<T> {
public:
  BFSIterator(Iterator *it): _index(0), _it(it) {}

  void first() {
    _index = 0;
  }

  T currentItem() const {
    //return _list->args(_index);
    return nullptr;
  }

  bool isDone() const {
    //return _index >= _list->arity();
    return true;
  }

  void next() {
    _index++;
  }
private:
  int _index;
  Iterator* _it;
};*/
#endif
