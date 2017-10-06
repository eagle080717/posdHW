#ifndef UTTERM_H
#define UTTERM_H

#include "variable.h"
#include "atom.h"
#include "number.h"

//test Number.value()
TEST (Number, ctor) {
	Number n(25);
	ASSERT_EQ(NULL, n.value());
}

//test Number.symbol()
TEST (Number, symbol) {
	Number n(25);
	ASSERT_EQ("25", n.symbol());
}

//?- 25 = 25.
// true.
TEST (Number, matchSuccess) {
	Number n1(25);
	Number n2(25);
	ASSERT_TRUE(n1.match(n2));
}

//?- 25 = 0.
// false.
TEST (Number, matchFailureDiffValue) {
	Number n1(25);	//n.symbol = 25
	Number n2(0);
	ASSERT_FALSE(n1.match(n2));	//25 = 0
}

//?- 25 = tom.
// false.
TEST (Number, matchFailureDiffConstant) {
	Number n(25);	//n.symbol = 25
	Atom tom("tom");
	ASSERT_FALSE(n.match(tom));	//25 = tom.
}

//?- 25 = X.
// true.
TEST (Number, matchSuccessToVar) {
  	Number n(25);	//n.symbol = 25
	Variable val("X");
	ASSERT_TRUE(n.match(val.symbol()));	//25 = X
}


//?- tom = 25.
// false.
TEST (Atom, matchFailureDiffConstant) {
	Atom tom("tom");
	Number n(25);
	ASSERT_FALSE(tom.match(n.value()));
}


// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	Atom tom("tom");
	Variable X("X");
	ASSERT_TRUE(tom.match(X.symbol()));
	ASSERT_TRUE(X.match(tom.symbol()));
}

// ?- X = tom, tom = X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	Atom tom("tom");
	Variable X("X");
	ASSERT_TRUE(X.match(tom.symbol()));
	ASSERT_TRUE(tom.match(X.symbol()));
	ASSERT_TRUE(X.match(tom.symbol()));
}

// ?- X = jerry, tom = X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
	Atom tom("tom");
	Atom tom("jerry");
	Variable X("X");
	ASSERT_TRUE(X.match(jerry.symbol()));
	ASSERT_FALSE(tom.match(X.symbol()));
}


// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
 	Number n(5);
 	Variable X("X");
 	ASSERT_TRUE(X.match(n.symbol()));
 	ASSERT_TRUE(X.match(n.symbol()));
}

// ?- X = 25, X = 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {
	Number n1(25);
	Number n2(100);
 	Variable X("X");
 	ASSERT_TRUE(X.match(n1.symbol()));
 	ASSERT_FALSE(X.match(n2.symbol()));
}

// ?- X = tom, X = 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {
	Atom tom("tom");
	Variable X("X");
	Number n(25);
	ASSERT_TRUE(X.match(tom.symbol()));
	ASSERT_FALSE(X.match(n.symbol()));
}

//?- tom = X, 25 = X.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {
	Atom tom("tom");
	Variable X("X");
	Number n(25);
	ASSERT_TRUE(tom.match(X.symbol()));
	ASSERT_FALSE(n.match(X.symbol()));
}

//?- X = tom, X = tom.
// true.
TEST(Variable, reAssignTheSameAtom){
	Atom tom("tom");
	Variable X("X");
	ASSERT_TRUE(X.match(tom.symbol()));
	ASSERT_TRUE(tom.match(X.symbol()));
}



#endif