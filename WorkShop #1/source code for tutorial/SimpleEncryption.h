/*
 * SimpleEncryption.cpp
 *
 *  Created on: Sep. 1, 2025
 *      compiled by Yan Liu for coen 244 fall 2025
 */
#include <iostream>
#include <string>
using namespace std;

std::string rot13Encrypt(const std::string & message) {
	std::string encryptedMessage = message;

    for (char &c : encryptedMessage) {

        if (isalpha(c)) {

            char base = islower(c) ? 'a' : 'A';

            c = (c - base + 13) % 26 + base;
        }
    }
    return encryptedMessage;
}


std::string rot13Decrypt(const std::string &encryptedMessage) {
    // ROT13 decryption is the same as encryption
    return rot13Encrypt(encryptedMessage);
}


std::string testEncrypt(){
		std::string message;
	    std::cout << "Enter a message to encrypt: ";
	    std::getline(std::cin, message);
	    std::string encryptedMessage = rot13Encrypt(message);
	    std::cout << "Encrypted message: " << encryptedMessage << std::endl;
	    return encryptedMessage;
}

std::string testDecrypt(){
		std::string encryptedMessage;
	    std::cout << "Enter a message to decrypt: ";
	    std::getline(std::cin, encryptedMessage);
	    std::string decryptedMessage = rot13Decrypt(encryptedMessage);
	    std::cout << "Decrypted message: " << decryptedMessage << std::endl;
	    return decryptedMessage;
}





