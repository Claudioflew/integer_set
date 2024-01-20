#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <vector>

class IntegerSet {
public:
  IntegerSet();
  IntegerSet(int[], int);

  // Comment 1: These class objects should be pass by reference to save the memory.
  IntegerSet unionOfSets(IntegerSet&);
  IntegerSet intersectionOfSets(IntegerSet&);
  void insertElement(int);
  void deleteElement(int);
  // Comment 2: We don't forget keyword const when the function doesn't change anything.
  void printSet() const;
  bool isEqualTo(IntegerSet&) const;
  void inputSet();
  
private:
  // Comment 3: The number of bool element is the same amoung all the class object, so it should be static.
  static const int NUM_ELEMENT = 101;
  std::vector<bool> intVec;  
};

#endif


