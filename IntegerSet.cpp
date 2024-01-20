#include "IntegerSet.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

IntegerSet::IntegerSet() {
  // Comment 4: I don't know how to initialize a bool vector with 101 false values except this.
  vector<bool> temp(NUM_ELEMENT, false);
  intVec = temp;
}

IntegerSet::IntegerSet(int arr[], int size) {
  vector<bool> temp(NUM_ELEMENT, false);
  intVec = temp;
  for (int i = 0; i < size; i++) {
    // Comment 5: We should use the member function instead of inserting each element to the vector here.
    insertElement(arr[i]);
  }
}

IntegerSet IntegerSet::unionOfSets(IntegerSet& mou) {
  // Comment 6: Built-in array doesn't have a method to know its size, so we need this variable, size.
  int arr[NUM_ELEMENT], size = 0;
  
  for (int i = 0; i < NUM_ELEMENT; i++) {
    // Comment 7: This pointer is not necessary here, but to make it clear, I added it.
    if (this->intVec[i] || mou.intVec[i]) {
      arr[size] = i;
      size++;
    }
  };
  // Comment 8: This is an unnamed object.
  return IntegerSet(arr, size);
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet& mou) {
  int arr[NUM_ELEMENT], size = 0;
  
  for (int i = 0; i < NUM_ELEMENT; i++) {
    if (this->intVec[i] && mou.intVec[i]) {
      arr[size] = i;
      size++;
    }
  }
  return IntegerSet(arr, size);
}

// Comment 9: This function should be responsible for input validation.
void IntegerSet::insertElement(int num) {
  if (num >= 0 && num < NUM_ELEMENT) {
    intVec[num] = true;
  } else {
    cout << "Invalid insert attempted!" << endl;
  }
}

void IntegerSet::deleteElement(int num) {
  if (intVec[num]) {
    intVec[num] = false;
  } else {
    cout << "The entry is not in the set or invalid." << endl;
  }
}

void IntegerSet::printSet() const {
  // Comment 10: We want a flag variable to print "--" when the set is empty.
  bool empty = true;
  cout << "{ ";
  for (int i = 0; i < NUM_ELEMENT; i++) {
    if (intVec[i]) {
      empty = false;
      cout << i << " ";
    }
  }
  if (empty) { cout << "-- "; }
  cout << "}\n";
}
  
bool IntegerSet::isEqualTo(IntegerSet& mou) const {
  for (int i = 0; i < NUM_ELEMENT; i++) {
    // Comment 11: Testing the elements are not equal is better because once we found an inequality, we arrive at a conclusion and don't need to iterate anymore.
    if (this->intVec[i] != mou.intVec[i]) {
      return false;
    }
  }
  return true;
}

void IntegerSet::inputSet() {
  int userInput;
  cout << "Enter an element (-1 to end): ";
  cin >> userInput;
  while (userInput != -1) {
    // Comment 12: I don't think we need input validation here because insertElement() function does that.
    if (userInput < 0 || userInput >= NUM_ELEMENT) {
      cout << "Invalid element" << endl;
    } else {
      insertElement(userInput);
    }
    cout << "Enter an element (-1 to end): ";
    cin >> userInput;
  }
  cout << "Entry complete\n";
}