#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <unordered_map>
using std::string;

#include "atom.h"
#include "number.h"
#include "variable.h"
#include "list.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "node.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}

  /*
  Term* createTerm(){
    int token = _scanner.nextToken();
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    } else if(token == NUMBER){
        return new Number(_scanner.tokenValue());
    } else if(token == ATOM || token == ATOMSC){
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        vector<Term*> terms = {};

        switch(_scanner.currentChar()) {
          case '(': _scanner.extractChar();
                    _scanner.skipLeadingWhiteSpace();
                    if(_scanner.currentChar() == ')'){
                      _scanner.nextToken();
                      return new Struct(*atom, terms);
                    }
                    else {
                      terms = getArgs();                    
                      if(_currentToken == ')')
                        return new Struct(*atom, terms);
                      throw std::string("unexpected token");
                    }   
                    break;

          case '[': _scanner.extractChar();
                    _scanner.skipLeadingWhiteSpace();            
                    if(_scanner.currentChar() == ']'){
                      _scanner.nextToken();
                      return new List;
                    }                  
                    else {
                      terms = getArgs();
                      if(_currentToken == ']')
                        return new List(terms);
                      throw std::string("unexpected token");                 
                    }
                    break;

          default:  return atom;
                    break;
        }
        
    }
    return NULL;
  }
  */

  Term *createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }

  Term *structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _tmpSArg = args;
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term *list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> &getTerms() {
    return _terms;
  }

  void matchings() {
    Node *nodeptr;
    Term *t;
    unordered_map<std::string, int> charSets;
    unordered_map<std::string, Term *> struSets;
    int counter = 0;
    int tmpCounter = 100;

    while(t = createTerm()) {

      if(!charSets.empty()){
    
        auto search = charSets.find(t->symbol());
        if(!struSets.empty()){ 
          auto search2 = struSets.find(t->symbol());
          if(search2 != struSets.end()){
            t = search2->second;
          }
        }

        if(search != charSets.end()){
          _terms.push_back(_terms[search->second]);
          _nodes.push_back(_nodes[search->second]);  
        } 

        

        else {
          if(!_tmpSArg.empty()){
            for(int k=0; k<_tmpSArg.size(); k++){
              struSets.insert({_tmpSArg[k]->symbol(), _tmpSArg[k]});
            }
          }

          _terms.push_back(t);
          _nodes.push_back(new Node(TERM, t, nullptr, nullptr));
          charSets.insert({t->symbol(), counter});
        }
      } else{         
        _terms.push_back(t);
        _nodes.push_back(new Node(TERM, t, nullptr, nullptr));
        charSets.insert({t->symbol(), counter}); 
      }

      counter++;

      if(_scanner.currentChar() == '.')
        break;

      switch(_scanner.currentChar()){
        case ';': _nodes.push_back(new Node(SEMICOLON));
                  break;

        case ',': _nodes.push_back(new Node(COMMA));
                  break;

        case '=': _nodes.push_back(new Node(EQUALITY));
                  break;

        default:  break;
      }
      _scanner.nextToken(); //continue

    }

    int lastCOMMA = 0;

    for(int i = 0; i < _nodes.size(); i++){
      //X=1, Y=2, Z=3.
      if(i%2 == 1){
        if(_nodes[i]->payload == COMMA || _nodes[i]->payload == SEMICOLON){
          _root = _nodes[i];

          if(lastCOMMA != 0){
            _nodes[i]->left = _nodes[i+2];
            _nodes[i]->right = _nodes[lastCOMMA];
          }
          else {
            _nodes[i]->left = _nodes[i-2];
            _nodes[i]->right = _nodes[i+2];
          }         

          lastCOMMA = i;    
        }
        else {
          _nodes[i]->left = _nodes[i-1];
          _nodes[i]->right = _nodes[i+1];     
          if(_root == nullptr)
            _root = _nodes[i];
        }
        i++;
      }
    }

  }

  Node *expressionTree() {
    return _root;
  }

  void createTerms()
  {
    Term *term = createTerm();
    if(term != nullptr){
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

private:
  vector<Term *> _tmpSArg;
  vector<Term *> _terms;
  vector<Node *> _nodes;
  Node *_root = nullptr;
  Scanner _scanner;
  int _currentToken;
};

#endif