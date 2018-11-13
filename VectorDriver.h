// VectorDriver.h
// COSC 2030
// Jeremiah Vaskis
// 10/08/2018
// Lab 04

/* File: VectorDriver.cpp
 * Athr: Dimitri Zarzhitsky
 * Date: October 16, 2002
 *
 * Desc: provides the basic framework and examples for an introduction to
 *       the STL::vector, iterators, and the algorithms facilities.
 *
 * Edited by: Rafe Cooley
 * Date: October 1, 2017 (the future)
 *
 */
typedef unsigned long ulong;

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// My own header stuffs
// Referenced cplusplus.com for below headers
#include<stdio.h>	/* printf, scanf, puts, NULL */
#include<stdlib.h>	/* srand, rand */
#include<time.h>	/* time */
// My own header stuffs


// fill vector that has pre-allocated space with consecutive numbers
void fill_vector(vector<short> &data) {
  for (ulong i=0; i<data.size(); i++) {
    data.at(i) = i;
  }
}

// print our vector in a fancy way
void print(const vector<short> &data) {
  if (data.empty()) {
    cout << "<empty>";
  } else {
    cout << "<" << data.at(0);
    for (ulong i=1; i<data.size(); i++) {
      cout << ", " << data.at(i);
    }
    cout << ">";
  }
}

// use iterator to sum the elements of a vector
short compute_sum(const vector<short> &data) {
  std::vector<short>::const_iterator iter = data.begin();

  short sum = 0;
  while (iter != data.end()) {
    sum += *iter;
    iter++;
  }

  return sum;
}

// TODO: implement add_numbers
void add_numbers(vector<short> &data) {
	
	int RandomNum = -1;

	// initialize random seed
	srand(time(NULL));
	// Needs to be outside of for loop to work.
	// rand() seems to have
	// its own incrementor (if you put srand in the for-loop, it will only
	// spit out the first iteration of the "rand()-loop")

	for (int i = 0; i < 10; i++) {
		// Create Random number between 1 and 500 (required for Lab 07)
		RandomNum = rand() % 500 + 1;
		data.push_back(RandomNum);
	}
}

// TODO: implement print_even
void print_even(const vector<short> &data) {
	if (data.empty()) {
		cout << "<empty>";
	}
	else {
		cout << "<";
		cout << data.at(0);
		for (int i = 1; i < data.size(); i++) {
			if ((i%2) == 0) {
				cout << ", ";
				cout << data.at(i);
			}
		}
		cout << ">";
	}
}

// TODO: implement is_present
// use iterator to sum the elements of a vector
bool is_present(const vector<short> &data, short value) {
	std::vector<short>::const_iterator iter = data.begin();
	
	bool foundNum = false;
	while ((iter != data.end()) && (foundNum == false)) {
		if (*iter == value) {
			foundNum = true;
		}
		iter++;
	}
	return foundNum;
}

// TODO: implement std::sort function


