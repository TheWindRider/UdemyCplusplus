/*
 * Vector&List.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: frankycg
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    vector<string> words; /* not need length, resizable */
    list<int> num_list;

    words.push_back("first");
    words.push_back("second");
    words.push_back("third");
    num_list.push_back(1);
    num_list.push_back(2);
    num_list.push_back(3);
    num_list.push_front(0); /* vector can add to end, list can add to any position */

    /* Iterate vector or list with iterator */
    vector<string>::iterator vec_it = words.begin();
    list<int>::iterator list_it = num_list.begin();
    for (vec_it = words.begin(); vec_it != words.end(); vec_it++) {
        cout << *vec_it << endl;
    }
    /* Iterate made easier in C++11 */
    for (auto eachWord : words) {
    	cout << eachWord << endl;
    }
    /* insert and erase works for list, but not vector */
    while (list_it != num_list.end()) {
    	if (*list_it == 2) {
    		num_list.insert(list_it, 1234);
    	}
    	/* how to erase and continue iterating */
    	if (*list_it == 1) {
    		list_it = num_list.erase(list_it);
    	}
    	else list_it++;
    }
    list_it = num_list.begin();
    for (list_it = num_list.begin(); list_it != num_list.end(); list_it++) {
    	cout << *list_it << endl;
    }
    /* vector iterator can move multiple steps, and both direction, but not list */
    vec_it -= 2;
    cout << "reverse second is " << *vec_it << endl;

	/* Initialized, not as easy as num_table(5,5) */
	vector< vector<int> > num_table(5, vector<int>(5, 0));
	/* No need to have same length each row */
	num_table[3].push_back(9);
	/* Iterate vector with index */
	for (int row = 0; row < num_table.size(); row++) {
	    for (int col = 0; col < num_table[row].size(); col++) {
	        if (col == row) cout << col << flush;
	        else cout << num_table[row][col] << flush;
	    }
	    cout << endl;
	}

	vector<double> numbers(10);
	int number_tank = numbers.capacity();

	for(int i = 0; i < 1000; i++) {
	    numbers.push_back(i);
	    if(number_tank < numbers.capacity()) {
	        /* size increase 1 by 1, capacity increase 2-fold */
	        cout << numbers.size() << ',' << numbers.capacity() << endl;
	        number_tank = numbers.capacity();
	    }
	}

	/* change capacity if request more than current */
	numbers.reserve(100);
	cout << numbers.size() << ',' << numbers.capacity() << endl;
	numbers.reserve(5000);
	cout << numbers.size() << ',' << numbers.capacity() << endl;
	/* remove all items, capacity remain same */
	numbers.clear();
	cout << numbers.size() << ',' << numbers.capacity() << endl;
	return 0;
}
