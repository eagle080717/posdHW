#ifndef EXP_H
#define EXP_H
#include "include/Shapes.h"
#include "include/Media.h"
#include "include/Sort.h"

TEST (Sort, sortByIncreasingPerimeter) {
	std::list<Shape *> shapeList;
	Rectangle rect(0,0,10,10);	//peri = 40
	Circle circ(5,5,10);	//peri = 62.8
	vertex vtA = {10, 10};	//AB = 7.07
	vertex vtB = {5, 5};	//BC = 10
	vertex vtC = {15, 5};	//AC = 7.07
	Triangle tri(vtA,vtB,vtC);	//peri = 24.24
	shapeList.push_back(&rect);
	shapeList.push_back(&circ);
	shapeList.push_back(&tri);	//40, 62.8, 24.24
	Sort sorter;
	sorter.sortByIncreasingPerimeter(&shapeList);	//24.24, 40, 62.8
	std::list<Shape *>::iterator it = shapeList.begin();

	for(it; it!=std::prev(shapeList.end(), 1); it++){	
		ASSERT_LE((*it)->perimeter(), (*std::next(it, 1))->perimeter());	//less than or equal
	}

}


TEST (Sort, sortByDecreasingPerimeter) {
	std::list<Shape *> shapeList;
	Rectangle rect(0,0,10,10);	//area = 100
	Circle circ(5,5,10);	//area = 314
	vertex vtA = {10, 10};	//AB = 7.07
	vertex vtB = {5, 5};	//BC = 10
	vertex vtC = {15, 5};	//AC = 7.07
	Triangle tri(vtA,vtB,vtC);	//area = 25
	shapeList.push_back(&rect);
	shapeList.push_back(&circ);
	shapeList.push_back(&tri);	//100, 314, 25
	Sort sorter;
	sorter.sortByDecreasingPerimeter(&shapeList);	//314, 100, 25
	std::list<Shape *>::iterator it = shapeList.begin();
	
	/* //for testing only
	it = shapeList.begin();
    std::cout << "------\n" << (*it)->perimeter() << std::endl;
    it++;
    std::cout << (*it)->perimeter() << std::endl;
    it++;
    std::cout << (*it)->perimeter() << std::endl;
	*/

	for(it; it!=std::prev(shapeList.end(), 1); it++){
			ASSERT_GE((*it)->perimeter(), (*std::next(it, 1))->perimeter());	//greater than or equal
	}
}


TEST (Sort, sortByIncreasingArea) {
	std::list<Shape *> shapeList;
	Rectangle rect(0,0,10,10);	//peri = 40
	Circle circ(5,5,10);	//peri = 62.8
	vertex vtA = {10, 10};	//AB = 7.07
	vertex vtB = {5, 5};	//BC = 10
	vertex vtC = {15, 5};	//AC = 7.07
	Triangle tri(vtA,vtB,vtC);	//peri = 24.24
	shapeList.push_back(&rect);
	shapeList.push_back(&circ);
	shapeList.push_back(&tri);	//40, 62.8, 24.24
	Sort sorter;
	sorter.sortByIncreasingArea(&shapeList);	//24.24, 40, 62.8
	std::list<Shape *>::iterator it = shapeList.begin();

	for(it; it!=std::prev(shapeList.end(), 1); it++){	
		ASSERT_LE((*it)->area(), (*std::next(it, 1))->area());	//less than or equal
	}
}


TEST (Sort, sortByDecreasingArea) {
	std::list<Shape *> shapeList;
	Rectangle rect(0,0,10,10);	//area = 100
	Circle circ(5,5,10);	//area = 314
	vertex vtA = {10, 10};	//AB = 7.07
	vertex vtB = {5, 5};	//BC = 10
	vertex vtC = {15, 5};	//AC = 7.07
	Triangle tri(vtA,vtB,vtC);	//area = 25
	shapeList.push_back(&rect);
	shapeList.push_back(&circ);
	shapeList.push_back(&tri);	//100, 314, 25
	Sort sorter;
	sorter.sortByDecreasingArea(&shapeList);	//314, 100, 25
	std::list<Shape *>::iterator it = shapeList.begin();
	

	for(it; it!=std::prev(shapeList.end(), 1); it++){
			ASSERT_GE((*it)->area(), (*std::next(it, 1))->area());	//greater than or equal
	}
}


TEST (Sort, sortByIncreasingCompactness) {
	std::list<Shape *> shapeList;
	Rectangle rect(0,0,10,10);	//peri = 40
	Circle circ(5,5,10);	//peri = 62.8
	vertex vtA = {10, 10};	//AB = 7.07
	vertex vtB = {5, 5};	//BC = 10
	vertex vtC = {15, 5};	//AC = 7.07
	Triangle tri(vtA,vtB,vtC);	//peri = 24.24
	shapeList.push_back(&rect);
	shapeList.push_back(&circ);
	shapeList.push_back(&tri);	//40, 62.8, 24.24
	Sort sorter;
	sorter.sortByIncreasingCompactness(&shapeList);	//24.24, 40, 62.8
	std::list<Shape *>::iterator it = shapeList.begin();

	for(it; it!=std::prev(shapeList.end(), 1); it++){	
		ASSERT_LE((*it)->compactness(), (*std::next(it, 1))->compactness());	//less than or equal
	}
}


#endif
