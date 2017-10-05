#ifndef UTTERM_H
#define UTTERM_H

#include "variable.h"
#include "atom.h"
#include "number.h"

//test Number.value()
TEST (Number, ctor) {
	Number n(25);
	ASSERT_EQ("0", n.value());
}

//test Number.symbol()
TEST (Number, symbol) {
	Number n(25);
	ASSERT_EQ("25", n.symbol());
}

//?- 25 = 25.
// true.
TEST (Number, matchSuccess) {
	Number n(25);
	Atom at("25");
	ASSERT_TRUE(n.match(at));
}

//?- 25 = 0.
// false.
TEST (Number, matchFailureDiffValue) {
	Number n(123);	//n.symbol = 25
	Atom val("25");
	n.match(val);	//assign 25 as n's value
	Atom at("0");
	ASSERT_FALSE(n.match(at));	//25 = 0
}

//?- 25 = tom.
// false.
TEST (Number, matchFailureDiffConstant) {
	Number n(123);	//n.symbol = 25
	Atom val("25");
	n.match(val);	//assign 25 as n's value
	Atom tom("tom");
	ASSERT_FALSE(n.match(tom));	//25 = tom.
}

//?- 25 = X.
// true.

TEST (Number, matchSuccessToVar) {
  	Number n(25);	//n.symbol = 25
	Variable val("X");
	ASSERT_TRUE(val.match(n.symbol()));	//25 = X
}


//?- tom = 25.
// false.
TEST (Atom, matchFailureDiffConstant) {
	Atom tom("tom");
	Number n(25);
	ASSERT_FALSE(tom.match(n.symbol()));
}

/*
// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {

}

// ?- X = tom, tom = X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {

}

// ?- X = jerry, tom = X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {

}

// ?- X = 5.
// X = 5.
TEST (Variable, matchSuccessToNumber) {
 
}

// ?- X = 25, X = 100.
// false.
TEST (Variable, matchFailureToTwoDiffNumbers) {

}

// ?- X = tom, X = 25.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom = X, 25 = X.
// false.
TEST (Variable, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X = tom, X = tom.
// true.
TEST(Variable, reAssignTheSameAtom){

}

*/

#endif