// Lab7-JVaskis.h
// Jeremiah Vaskis
// Lab 07
// 11/12/2018

#pragma once
#ifndef LAB7_H_DEF
#define LAB7_H_DEF
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// Most Alogrithm Reference Resources Used:
// http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/
// https://rosettacode.org/wiki/Category:Sorting_Algorithms


// Concept Reference Sites:
// http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/bubble-sort/
// https://rosettacode.org/wiki/Sorting_algorithms/Bubble_sort
void bubble_sort(vector<short> &data) {

	// NOTE: This is the unoptimized version, the algorithm for
	// the optimized version can be found at:
	// http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/bubble-sort/

	bool SwapFlag = true;
	short temp;

	while (SwapFlag == true) {

		// Set Flag to false
		// If there is no swapping (list is sorted) then the loop will end
		SwapFlag = false;

		// Loop through the entire vector once
		for (int i = 0; i < data.size() - 1; i++) {

			// Check if current two elements need swaping
			if (data[i] > data[i + 1]) {
				temp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = temp;
				SwapFlag = true;	// There was at least one Swap
			}
		}
	}
}


// Concept Reference Sites:
// http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/insertion-sort/
// https://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort
void insertion_sort(vector<short> &data) {
	
	int value;
	int j = 0;

	for (int i = 1; i <= data.size() - 1; i++) {
		value = data[i];
		j = i - 1;

		while (j >= 0 && (data[j] > value)) {
			data[j + 1] = data[j];
			j = j - 1;
		}

		data[j + 1] = value;
	}
}


// Concept Reference Sites:
// http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/selection-sort/
// https://rosettacode.org/wiki/Sorting_algorithms/Selection_sort
void selection_sort(vector<short> &data) {

	short min_index;
	short temp;

	// Only execute if the array is more than one element
	if (data.size() > 1) {
		
		// Scan and update the array N times (N = array length)
		for (int N = 0; N < data.size(); N++) {
			
			min_index = N;

			for (int i = N + 1; i < data.size(); i++) {
				if (data[i] < data[min_index]) {
					min_index = i;
				}
			}

			// Swap the current N element with the current min element
			// This works even if the min_index is NOT updated
			temp = data[N];
			data[N] = data[min_index];
			data[min_index] = temp;
		}
	}
}

//====+====+====+====+====+====+====+====+====+====+====+====+====+====+====+
// The following code is sourced from rosettacode.org, I have NOT IDEA how to
// do it myself from the pseudocode alone.
//====+====+====+====+====+====+====+====+====+====+====+====+====+====+====+

#include <iterator>
#include <algorithm>	// for std::inplace_merge
#include <functional>	// for std::less


// Concept Reference Sites:
// http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/mergesort/
// https://rosettacode.org/wiki/Sorting_algorithms/Merge_sort
// Following mergesort functions are copied from the rosettacode.org website C++ example
// I have NOT IDEA how I would do this stuff myself and make it work


template<typename RandomAccessIterator, typename Order>
void mergesort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (last - first > 1)
	{
		RandomAccessIterator middle = first + (last - first) / 2;
		mergesort(first, middle, order);
		mergesort(middle, last, order);
		std::inplace_merge(first, middle, last, order);
	}
}

template<typename RandomAccessIterator>
void mergesort(RandomAccessIterator first, RandomAccessIterator last)
{
	mergesort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}



// Concept Reference Sites:
// http://www.cplusplus.com/faq/sequences/sequencing/sort-algorithms/quicksort/
// https://rosettacode.org/wiki/Sorting_algorithms/Quicksort
// Following quicksort functions are copied from the rosettacode.org website C++ example
// I have NOT IDEA how I would do this stuff myself and make it work

// helper function for median of three
template<typename T>
T median(T t1, T t2, T t3)
{
	if (t1 < t2)
	{
		if (t2 < t3)
			return t2;
		else if (t1 < t3)
			return t3;
		else
			return t1;
	}
	else
	{
		if (t1 < t3)
			return t1;
		else if (t2 < t3)
			return t3;
		else
			return t2;
	}
}

// helper object to get <= from <
template<typename Order> struct non_strict_op :
	public std::binary_function<typename Order::second_argument_type,
	typename Order::first_argument_type,
	bool>
{
	non_strict_op(Order o) : order(o) {}
	bool operator()(typename Order::second_argument_type arg1,
		typename Order::first_argument_type arg2) const
	{
		return !order(arg2, arg1);
	}
private:
	Order order;
};

template<typename Order> non_strict_op<Order> non_strict(Order o)
{
	return non_strict_op<Order>(o);
}

template<typename RandomAccessIterator,
	typename Order>
	void quicksort(RandomAccessIterator first, RandomAccessIterator last, Order order)
{
	if (first != last && first + 1 != last)
	{
		typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
		RandomAccessIterator mid = first + (last - first) / 2;
		value_type pivot = median(*first, *mid, *(last - 1));
		RandomAccessIterator split1 = std::partition(first, last, std::bind2nd(order, pivot));
		RandomAccessIterator split2 = std::partition(split1, last, std::bind2nd(non_strict(order), pivot));
		quicksort(first, split1, order);
		quicksort(split2, last, order);
	}
}

template<typename RandomAccessIterator>
void quicksort(RandomAccessIterator first, RandomAccessIterator last)
{
	quicksort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

// My own attempt at it, it did NOT end well...
//void quick_sort(vector<short> &data) {
//	
//	short temp;	// Used for swaping things
//
//	if (data.size() > 1) {
//		int pivot = data[0];			// "Any element of array"
//		int left = 0;					// first index of array
//		int right = data.size() - 1;	// last index of array
//
//		while (left <= right) {
//			// When left element is < pivot, decrement left
//			while (data[left] < pivot) {
//				left++;
//			}
//			// When right element is > pivot, increment right
//			while (data[right] > pivot) {
//				right++;
//			}
//			// Swap left and right elements
//			if (left <= right) {
//				temp = data[left];
//				data[left] = data[right];
//				data[right] = temp;
//				left++;
//				right--;
//			}
//		}
//		//quicksort(array from first index to right)
//		//quicksort(array from left to last index)
//	}
//}

#endif