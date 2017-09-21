#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "Shapes.h"

class Sort {

  public :

  static void sortByIncreasingPerimeter(std::list<Shape *> * shapeList){
  		int flag = 0;
      std::list<Shape *>::iterator it = shapeList->begin();
      std::list<Shape *>::iterator last = std::prev(shapeList->end(), 1); //the end-1
      std::list<Shape *>::iterator next = std::next(it, 1); // the begin+1

      while(!shapeList->empty()){

        next = std::next(shapeList->begin(), 1);

        flag = 0;
        for(it=shapeList->begin(); it!=last; it++, next++){
    				//std::cout << (*it)->perimeter() << "///" << (*next)->perimeter() << std::endl;

            if((*it)->perimeter() > (*next)->perimeter()){
              
    					flag = 1;                 					
              std::swap(*it, *next);  					
    				}
          //std::cout << (*it)->perimeter() << std::endl;
    		}
        //fgetc(stdin);
    		if(flag == 0)
    			break;
      }

      /*  for testing only
      it = shapeList->begin();
      std::cout << "------\n" << (*it)->perimeter() << std::endl;
      it++;
      std::cout << (*it)->perimeter() << std::endl;
      it++;
      std::cout << (*it)->perimeter() << std::endl;
      */

  	}

  

  static void sortByDecreasingPerimeter(std::list<Shape *> * shapeList){
      int flag = 0;
      std::list<Shape *>::iterator it = shapeList->begin();
      std::list<Shape *>::iterator last = std::prev(shapeList->end(), 2); //the end-1
      std::list<Shape *>::iterator next = std::next(it, 1); // the begin+1

      while(!shapeList->empty()){
        next = std::next(shapeList->begin(), 1);
        flag = 0;
        for(it=shapeList->begin(); it!=last; it++, next++){
            if((*it)->perimeter() < (*next)->perimeter()){
              flag = 1;
              //std::swap(*std::next(it, 0), *std::next(next, 0));
              std::swap(*it, *std::next(next, 0));                               
            }
          
        }

        if(flag == 0)
          break;
      }

      /* for testing only
      it = shapeList->begin();
      std::cout << "------\n" << (*it)->perimeter() << std::endl;
      it++;
      std::cout << (*it)->perimeter() << std::endl;
      it++;
      std::cout << (*it)->perimeter() << std::endl;
      */

  }

  static void sortByIncreasingArea(std::list<Shape *> * shapeList){
      int flag = 0;
      std::list<Shape *>::iterator it = shapeList->begin();
      std::list<Shape *>::iterator last = std::prev(shapeList->end(), 1); //the end-1
      std::list<Shape *>::iterator next = std::next(it, 1); // the begin+1

      while(!shapeList->empty()){

        next = std::next(shapeList->begin(), 1);

        flag = 0;
        for(it=shapeList->begin(); it!=last; it++, next++){
            //std::cout << (*it)->perimeter() << "///" << (*next)->perimeter() << std::endl;

            if((*it)->area() > (*next)->area()){
              
              flag = 1;                           
              std::swap(*it, *next);            
            }
          //std::cout << (*it)->perimeter() << std::endl;
        }
        //fgetc(stdin);
        if(flag == 0)
          break;
      }
  }

  static void sortByDecreasingArea(std::list<Shape *> * shapeList){
      int flag = 0;
      std::list<Shape *>::iterator it = shapeList->begin();
      std::list<Shape *>::iterator last = std::prev(shapeList->end(), 2); //the end-1
      std::list<Shape *>::iterator next = std::next(it, 1); // the begin+1

      while(!shapeList->empty()){
        next = std::next(shapeList->begin(), 1);
        flag = 0;
        for(it=shapeList->begin(); it!=last; it++, next++){
            if((*it)->area() < (*next)->area()){
              flag = 1;
              //std::swap(*std::next(it, 0), *std::next(next, 0));
              std::swap(*it, *std::next(next, 0));                               
            }
          
        }

        if(flag == 0)
          break;
      }
  }
  
  static void sortByIncreasingCompactness(std::list<Shape *> * shapeList){
      // Compactness = area/perimeter
      int flag = 0;
      std::list<Shape *>::iterator it = shapeList->begin();
      std::list<Shape *>::iterator last = std::prev(shapeList->end(), 1); //the end-1
      std::list<Shape *>::iterator next = std::next(it, 1); // the begin+1

      while(!shapeList->empty()){

        next = std::next(shapeList->begin(), 1);

        flag = 0;
        for(it=shapeList->begin(); it!=last; it++, next++){
            //std::cout << (*it)->perimeter() << "///" << (*next)->perimeter() << std::endl;

            if((*it)->compactness() > (*next)->compactness()){
              
              flag = 1;                           
              std::swap(*it, *next);            
            }
          //std::cout << (*it)->perimeter() << std::endl;
        }
        //fgetc(stdin);
        if(flag == 0)
          break;
      }
  }
  
};
