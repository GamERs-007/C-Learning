/*
 * testDriver.cpp
 *
 *  Created on: Sep 4, 2025
 *      Author: umroot
 */


#include <iostream>
#include "SimpleEncryption.h"
#include "CaesarCipherEncryption.h"

using namespace std;

int main() {

	//assertion; comparing actual output with the expectation (test code here is coen 244)
	std::string testResult = (testEncrypt()=="pbra244")? "pass":"fail";
	std::cout << testResult << std::endl;

	testResult = (testDecrypt()=="coen244")?"pass":"fail";
	std::cout << testResult << std::endl;

	testMultipleCases();



    return 0;
}



