#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string encryptTransposition(const string& text, int width) {
    string ciphertext = "";
    int len = text.length();

    // Create a 2D matrix to store characters column-wise
    for (int i = 0; i < width; i++) {
        for (int j = i; j < len; j += width) {
            ciphertext += text[j];
        }
    }

    return ciphertext;
}

// Function to decrypt using Transposition Cipher
string decryptTransposition(const string& ciphertext, int width) {
    int len = ciphertext.length();
    int rows = (len + width - 1) / width;  // Calculate the number of rows
    string plaintext(len, ' ');  // Placeholder for decrypted text

    int idx = 0;
    for (int i = 0; i < width; i++) {
        for (int j = i; j < len; j += width) {
            plaintext[j] = ciphertext[idx++];
        }
    }

    return plaintext;
}

int main() {
    string plaintext = "AKIF ISLAMN";
    plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());  // Remove spaces

    int width;
    cout << "Enter the width for Transposition Cipher: ";
    cin >> width;

    // Encryption
    string ciphertext = encryptTransposition(plaintext, width);
    cout << "Encrypted Text: " << ciphertext << endl;

    // Decryption
    string decryptedtext = decryptTransposition(ciphertext, width);
    cout << "Decrypted Text: " << decryptedtext << endl;

    return 0;
}
