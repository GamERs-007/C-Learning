Readme.md
 Created on: Sep. 1, 2025
     Author: Yan Liu

# Tutorial Solution for SimpleEncryption
A C++ program that attempts to decrypt a ROT13 message using simple frequency substitution. The program analyzes the frequency of letters in the encrypted message and replaces the most frequent letters with the most commonly used English letters. The possibilities are written to a file.     

``` c++
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Function to perform frequency analysis
std::unordered_map<char, int> frequency_analysis(const std::string& text) {
    std::unordered_map<char, int> freq_map;
    for (char c : text) {
        if (isalpha(c)) {
            freq_map[c]++;
        }
    }
    return freq_map;
}

// Function to decrypt using frequency substitution
std::string decrypt_with_frequency_substitution(const std::string& encrypted_text, const std::string& common_letters) {
    // Perform frequency analysis on the encrypted text
    auto freq_analysis = frequency_analysis(encrypted_text);
    
    // Sort the letters by frequency
    std::vector<std::pair<char, int>> sorted_freq(freq_analysis.begin(), freq_analysis.end());
    std::sort(sorted_freq.begin(), sorted_freq.end(),  {
        return b.second < a.second;
    });
    
    // Create a mapping from the most frequent letters in the encrypted text to common English letters
    std::unordered_map<char, char> substitution_map;
    for (size_t i = 0; i < sorted_freq.size() && i < common_letters.size(); ++i) {
        substitution_map[sorted_freq[i].first] = common_letters[i];
    }
    
    // Decrypt the text using the substitution map
    std::string decrypted_text;
    for (char c : encrypted_text) {
        if (substitution_map.find(c) != substitution_map.end()) {
            decrypted_text += substitution_map[c];
        } else {
            decrypted_text += c;
        }
    }
    return decrypted_text;
}

// Function to write possibilities to a file
void write_possibilities_to_file(const std::vector<std::string>& possibilities, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& possibility : possibilities) {
        file << possibility << std::endl;
    }
}

int main() {
    // Encrypted ROT13 message
    std::string encrypted_message = "Guvf vf n grfg zrffntr";
    
    // Common English letters by frequency
    std::string common_english_letters = "etaoinshrdlcumwfgypbvkjxqz";
    
    // Generate decrypted possibilities
    std::vector<std::string> decrypted_possibilities;
    decrypted_possibilities.push_back(decrypt_with_frequency_substitution(encrypted_message, common_english_letters));
    
    // Write possibilities to a file
    write_possibilities_to_file(decrypted_possibilities, "decrypted_possibilities.txt");
    
    std::cout << "Decryption possibilities written to decrypted_possibilities.txt" << std::endl;
    
    return 0;
}

```

# What Made the Code Breaking Easy?
The code breaking was made easier by the fact that ROT13 is a simple substitution cipher where each letter is replaced by the letter 13 positions after it in the alphabet. This simplicity means that frequency analysis can be effectively used to guess the original letters based on their frequency in the English language.

# How Can the Encryption Mechanism Be Improved?
To improve the encryption mechanism, you could:

+ Use a more complex substitution cipher: Instead of a fixed shift like ROT13, use a polyalphabetic cipher such as the Vigenère cipher.
+ Incorporate additional layers of encryption: Combine substitution with transposition or other cryptographic techniques.
+ Use modern encryption algorithms: EVigenère ciphermploy algorithms like AES (Advanced Encryption Standard) which are much more secure and resistant to frequency analysis and other cryptographic attacks.

## Example of Vigenère cipher
Let’s say we want to encrypt the plaintext “HELLO” using the keyword “KEY”:

+ Plaintext: H E L L O
+ Keyword:   K E Y K E
+ Using the Vigenère table:

* H shifted by K (10 positions) becomes R
* E shifted by E (4 positions) becomes I
* L shifted by Y (24 positions) becomes J
* L shifted by K (10 positions) becomes V
* O shifted by E (4 positions) becomes S

So, the ciphertext is “RIJVS”.