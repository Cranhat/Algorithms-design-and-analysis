#include "DynamicArray.hpp"
#include "../DynamicArray/DynamicArray.hpp"
#include <iostream>
#include <fstream>

DynamicArray::DynamicArray() {

	capacity = 10;
	size = 0;
	data = new int[capacity];

}

DynamicArray::~DynamicArray() {

	delete[] data;

}

void DynamicArray::resize() {

	capacity = capacity * 2;
	int* newData = new int[capacity];

	for (int i = 0; i < size; i++) {

		newData[i] = data[i];

	}

	delete[] data;
	data = newData;
}

int DynamicArray::getSize(){

	return size;

} 

void DynamicArray::addFront(int value) {
	if (size == capacity) {

		resize();
	}
	for (int i = size; i > 0; i--) {

		data[i] = data[i - 1];
	}
	data[0] = value;
	size++;

}

void DynamicArray::printElements(){

	for(int i = 0; i < size; i++){

		printf("%dith element = %d\n", i, data[i]);

	}
}

void DynamicArray::addBack(int value) {

	if (size == capacity) {

		resize();
		data[size] = value;
		size++;

	}
	else {
		
		data[size] = value;
		size++;

	}
}

void DynamicArray::deleteFront() {

	if (size > 0) {

		for (int i = 0; i < size; i++) {

			data[i] = data[i + 1];

		}
		size--;

	}
}

void DynamicArray::deleteBack() {

	if (size > 0) {

		size--;

	}
}

void DynamicArray::addIndex(int element, int index) {

	if (index < 0 || index > size) {

		std::cout << "Nieprawidłowy indeks!" << std::endl;
		return;

	}
	if (size == capacity) {

		resize();

	}
	for (int i = size; i > index; i--) {

		data[i] = data[i - 1];

	}

	data[index] = element;
	size++;
}

void DynamicArray::deleteIndex(int index) {

	if (index < 0 || index >= size) {
		std::cout << "Nieprawidłowy indeks!" << std::endl;
		return;

	}
	for (int i = index; i < size - 1; i++) {

		data[i] = data[i + 1];

	}
	size--;

}

bool DynamicArray::contains(int value){

	for (int i = 0; i < size; i++) {

		if (data[i] == value) {

			return true;

		}
	}
	return false;

}

int DynamicArray::firstElement(){

	return data[0];

}

int DynamicArray::lastElement(){

	if (size > 0){

		return data[size - 1];

	}else{

		printf("empty\n");
		return -1;

	}

}

void DynamicArray::clear(){

	delete[] data;
	capacity = 10;
	size = 0;
	data = new int[capacity];
	
}

void DynamicArray::sort(){}

void DynamicArray::reverse(){
	
	for (int i = 0; i < size - 1; i++){

        std::swap(data[i], data[size - 1 - i]);
        
    }
}