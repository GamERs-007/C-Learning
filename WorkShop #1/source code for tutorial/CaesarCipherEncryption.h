/*
 * CaesarCipherEncryption.h
 *
 *  Created on: Sep 4, 2025
 *      Author: umroot
 */

#ifndef CAESARCIPHERENCRYPTION_H_
#define CAESARCIPHERENCRYPTION_H_


/*
 * CaesarCipher.cpp
 *
 *  Created on: Sep. 4, 2025
 *      Example for COEN 244 Fall 2025 - Caesar Cipher Implementation
 */
#include <iostream>
#include <string>
using namespace std;

std::string caesarEncrypt(const std::string &message, int shift) {
    std::string encryptedMessage = message;

    // Normalize shift to be within 0-25 range
    shift = ((shift % 26) + 26) % 26;

	//shift = shift % 26;
	//if (shift < 0) {
	//	shift += 26;
	//}


    for (char &c : encryptedMessage) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return encryptedMessage;
}

std::string caesarDecrypt(const std::string &encryptedMessage, int shift) {
    // Decryption is encryption with negative shift
    return caesarEncrypt(encryptedMessage, -shift);
}

//unit testing function
std::string testCipherEncrypt() {
    std::string message;
    int shift;
    std::cout << "Enter a message to encrypt: ";
    std::getline(std::cin, message);
    std::cout << "Enter shift value (1-25): ";
    std::cin >> shift;
    std::cin.ignore(); // Clear the newline from input buffer

    std::string encryptedMessage = caesarEncrypt(message, shift);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    return encryptedMessage;
}

std::string testCipherDecrypt() {
    std::string encryptedMessage;
    int shift;
    std::cout << "Enter a message to decrypt: ";
    std::getline(std::cin, encryptedMessage);
    std::cout << "Enter shift value used for encryption: ";
    std::cin >> shift;
    std::cin.ignore(); // Clear the newline from input buffer

    std::string decryptedMessage = caesarDecrypt(encryptedMessage, shift);
    std::cout << "Decrypted message: " << decryptedMessage << std::endl;
    return decryptedMessage;
}


void testMultipleCases(){
			// Unit Test 1: Test encryption with shift 3
		   std::string testResult1 = (caesarEncrypt("hello", 3) == "khoor") ? "pass" : "fail";
		   std::cout << "Encryption Test 1 (hello -> khoor): " << testResult1 << std::endl;

		   // Unit Test 2: Test decryption with shift 3
		   std::string testResult2 = (caesarDecrypt("khoor", 3) == "hello") ? "pass" : "fail";
		   std::cout << "Decryption Test 2 (khoor -> hello): " << testResult2 << std::endl;

		   // Unit Test 3: Test with mixed case
		   std::string testResult3 = (caesarEncrypt("Hello World", 5) == "Mjqqt Btwqi") ? "pass" : "fail";
		   std::cout << "Mixed Case Test 3 (Hello World -> Mjqqt Btwqi): " << testResult3 << std::endl;

		   // Unit Test 4: Test wrap-around (z -> c with shift 3)
		   std::string testResult4 = (caesarEncrypt("xyz", 3) == "abc") ? "pass" : "fail";
		   std::cout << "Wrap-around Test 4 (xyz -> abc): " << testResult4 << std::endl;
}


#endif /* CAESARCIPHERENCRYPTION_H_ */
