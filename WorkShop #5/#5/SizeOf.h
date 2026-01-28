/*
 * SizeOf.h
 *
 *  Created on: Jan. 23, 2025
 *      Author: umroot
 */

#ifndef SIZEOF_H_
#define SIZEOF_H_



#include <iostream>

 size_t getSize(double* ptr); // prototype

void testSizeOfOperator() {
	double numbers[20]; // 20 doubles; occupies 160 bytes on our system

	std::cout << "\nNumber of bytes in numbers is " << sizeof(numbers)<<std::endl;

	//std::cout << "Number of element returned by getSize is " << sizeof(numbers)/ sizeof(numbers[0])<<std::endl;
	std::cout << "Number of element returned by getSize is " << sizeof(numbers)/ getSize(numbers)<<std::endl;
}


size_t getSize(double* ptr) {
	return sizeof(ptr[0]);
}



#endif /* SIZEOF_H_ */
