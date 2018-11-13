// Lab7-JVaskis.cpp
// Jeremiah Vaskis
// Lab 07
// 11/12/2018

#include <iostream>
#include "VectorDriver.h"
#include "winTimer.h"
#include <iomanip>			// std::setw
#include <algorithm>		// std::sort
#include "Lab7-JVaskis.h"	// Sorting Algorithms
using std::cout;
using std::cin;
using std::sort;

int main() {

	int selection = 0;
	// Bubble Size
	//const int size = 2320;
	//const int size = 2320*2;
	//const int size = 2320*4;

	//// Insertion Size
	//const int size = 5100;
	//const int size = 5100*2;
	//const int size = 5100*4;

	//// Selection Size
	//const int size = 3650;
	//const int size = 3650*2;
	//const int size = 3650*4;

	//// Merge Size
	//const int size = 558000;
	//const int size = 558000*2;
	//const int size = 558000*4;

	//// Quick Size
	//const int size = 6450000;
	//const int size = 6450000*2;
	//const int size = 6450000*4;

	//// STL::sort Size
	const int size = 2000000;
	//const int size = 6300000;
	//const int size = 6300000*2;
	//const int size = 6300000*4;

	Timer time;
	

	cout << "Data vector filled with random values " << size << " long with values from 1 - 500 (inclusive):" << endl;
	vector<short>Data(0);
	for (int i = 0; i < size/10; i++) {
		add_numbers(Data);
	}

	//cout << endl;
	//cout << "Data before sort:" << endl;
	//print(Data);
	//cout << endl << endl;

	cout << "Bubble		== 1" << endl;
	cout << "Insertion	== 2" << endl;
	cout << "Selection	== 3" << endl;
	cout << "Merge		== 4" << endl;
	cout << "Quick		== 5" << endl;
	cout << "STL::sort	== 6" << endl << endl;
	cout << "Select sort method: ";
	cin >> selection;

	if (selection == 1) {
		cout << endl << endl << "Bubble Sort Running..." << endl;
		time.start();
		bubble_sort(Data);
		time.stop();
	}
	if (selection == 2) {
		cout << endl << endl << "Insertion Sort Running..." << endl;
		time.start();
		insertion_sort(Data);
		time.stop();
	}
	if (selection == 3) {
		cout << endl << endl << "Selection Sort Running..." << endl;
		time.start();
		selection_sort(Data);
		time.stop();
	}
	if (selection == 4) {
		cout << endl << endl << "Merge Sort Running..." << endl;
		time.start();
		mergesort(Data.begin(), Data.end());
		time.stop();
	}
	if (selection == 5) {
		cout << endl << endl << "Quick Sort Running..." << endl;
		time.start();
		quicksort(Data.begin(), Data.end());
		time.stop();
	}
	if (selection == 6) {
		cout << endl << endl << "STL::sort Running..." << endl;
		time.start();
		sort(Data.begin(), Data.end());
		time.stop();
	}

	cout << endl << endl << "Time to completion is: " << time() << " seconds" << endl;


	cout << endl << endl;
	system("pause");

	return 0;
}