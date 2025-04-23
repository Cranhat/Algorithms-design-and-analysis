#pragma once
#include "../DataStructure/DataStructure.hpp"

class DynamicArray : public DataStructure {
protected:

	int* data;
	int size;
	int capacity;

	void resize();

public:

	DynamicArray();

	~DynamicArray();

	void printElements();

	void addFront(int value); 

	void addBack(int value);

	void addIndex(int element, int index);

	void deleteBack();

	void deleteFront();

	void deleteIndex(int index);

	int getSize();

	int firstElement();

	int lastElement();

	void clear();
	
	bool contains(int value); 

	void sort();

	void reverse();

};