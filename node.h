#ifndef NODE_H
#define NODE_H

enum Operators {SEMICOLON, COMMA, EQUALITY, TERM};

class Node {
public:
  Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Node(Operators op, Term *t, Node *l, Node *r):payload(op), term(t), left(l), right(r) {}

  bool evaluate() {
  	bool lTree;
  	bool rTree;
  	switch(payload){
  		case SEMICOLON:	{	lTree = left->evaluate();
  							rTree = right->evaluate();
  							if(lTree || rTree)
  								return true;
  							else
  								return false;
  							break;
  						}
  		case COMMA:	{	return left->evaluate() && right->evaluate();	//left subtree & right subtree should be true					
  						break;
  						}
  		case EQUALITY:	{ //cout << left->term->symbol() << "....." << right->term->symbol() << std::endl;
  							//cout << &(left->term) << "....." << &(right->term) << std::endl;
  							return (left->term)->match(*right->term);
  						break;
  						}
  		case TERM:	break;
  		default:	return false;
  					break;
  	}
  }

  Operators payload;
  Term *term;
  Node *left;
  Node *right;
};

#endif