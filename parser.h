#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "number.h"
#include "variable.h"
#include "list.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
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

  vector<Term*> getArgs()
  {
    Term* term = createTerm();
    vector<Term*> args = {};
    if(term)
      args.push_back(term);
    while((_currentToken = _scanner.nextToken()) == ',') {
      args.push_back(createTerm());
    }
    return args;
  }

private:
  Scanner _scanner;
  int _currentToken;
};
#endif