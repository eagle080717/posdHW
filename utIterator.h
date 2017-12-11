#ifndef UTITERATOR_H
#define UTITERATOR_H

#include "struct.h"
#include "variable.h"
#include "atom.h"
#include "list.h"
#include "iterator.h"

TEST(iterator, first) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t(Atom("t"), { &X, &two });
    Struct s(Atom("s"), { &one, &t, &Y });
    // StructIterator it(&s);
    Iterator *itStruct = s.createIterator();
    // Iterator& itStruct = it;
    // ASSERT_EQ(it.first()->symbol());
    itStruct->first();
    ASSERT_EQ("1", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("t(X, 2)", itStruct->currentItem()->symbol());
    ASSERT_FALSE(itStruct->isDone());
    itStruct->next();
    ASSERT_EQ("Y", itStruct->currentItem()->symbol());
    itStruct->next();
    ASSERT_TRUE(itStruct->isDone());
}

TEST(iterator, NullIterator){
    Number one(1);
    NullIterator nullIterator(&one);
    nullIterator.first();
    ASSERT_TRUE(nullIterator.isDone());
    Iterator *it = one.createIterator();
    it->first();
    ASSERT_TRUE(it->isDone());
}

TEST(iterator, StructIterator) {
   Number one(1);
   Variable X("X");
   Variable Y("Y");
   Number two(2);
   Struct t(Atom("t"), { &X, &two });
   Struct s(Atom("s"), { &one, &t, &Y });
   Iterator *it = s.createIterator();
   it->first();
   ASSERT_EQ("1", it->currentItem()->symbol());
   it->next();
   ASSERT_EQ("t(X, 2)", it->currentItem()->symbol());
   ASSERT_FALSE(it->isDone());
   it->next();
   ASSERT_EQ("Y", it->currentItem()->symbol());
   ASSERT_FALSE(it->isDone());
   it->next();
   ASSERT_TRUE(it->isDone());
}

TEST(iterator, ListIterator) {
    Number one(1);
    Variable X("X");
    Variable Y("Y");
    Number two(2);
    Struct t2(Atom("t2"), { &X, &two });
    List l({ &one, &t2, &Y });
    Iterator *itList = l.createIterator();
    itList->first();
    ASSERT_EQ("1", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("t2(X, 2)", itList->currentItem()->symbol());
    ASSERT_FALSE(itList->isDone());
    itList->next();
    ASSERT_EQ("Y", itList->currentItem()->symbol());
    itList->next();
    ASSERT_TRUE(itList->isDone());
}

TEST(iterator, DFSStruct1){
    //DFS: bigMac(bun, beefPatty), bun, beefPatty, coke, fries
    Variable bun("bun");
    Variable beefPatty("beefPatty");
    Variable coke("coke");
    Variable fries("fries");
    Struct bigMac(Atom("bigMac"), { &bun, &beefPatty });   
    Struct combo(Atom("combo"), { &bigMac, &coke, &fries});

    //Iterator *it = combo.createIterator();

    //ASSERT_EQ("bigMac(bun, beefPatty)", it->currentItem()->symbol());
    //ASSERT_FALSE(it->isDone());
    //itList->next();
}


#endif
