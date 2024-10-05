#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

string encryptTransposition(const string &text, int width)
{
    string ciphertext = "";
    int len = text.length();

    for (int i = 0; i < width; i++)
    {
        for (int j = i; j < len; j += width)
        {
            ciphertext += text[j];
        }
    }

    return ciphertext;
}

// Function to decrypt using Transposition Cipher
string decryptTransposition(const string &ciphertext, int width)
{
    int len = ciphertext.length();
    string plaintext(len, ' ');

    int index = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = i; j < len; j += width)
        {
            if (index < len)
                plaintext[j] = ciphertext[index++];
        }
    }

    return plaintext;
}

int main()
{
    ifstream input("input.txt");
    string inputText, plaintext;
    getline(input, inputText);

    for (char ch : inputText)
    {
        if (isalpha(ch))
            plaintext += ch;
    }

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