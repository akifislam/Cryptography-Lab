#include <iostream>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cstring>

using namespace std;

string encryption(string &plaintext, string &key)
{
    int len = plaintext.length();
    string ciphertext;

    for (int i = 0; i < len; i++)
    {
        int base = plaintext[i] - 'A';
        int keyBase = key[i] - 'A';

        char ch = (base + keyBase + 1) % 26 + 'A';
        ciphertext += ch;
    }

    return ciphertext;
}

string decryption(string &ciphertext, string &key)
{
    string plaintext;
    int len = ciphertext.length();

    for (int i = 0; i < len; i++)
    {
        int base = ciphertext[i] - 'A';
        int keyBase = key[i] - 'A';

        char ch = (base - keyBase + 26 - 1) % 26 + 'A';
        plaintext += ch;
    }

    return plaintext;
}

int main()
{
    ifstream inputFile("text.txt");
    string input, plaintext, key;
    getline(inputFile, input);

    ifstream keyFile("key.txt");
    getline(keyFile, key);

    cout << input << endl;
    cout << key << endl;

    for (char ch : input)
    {
        if (isalpha(ch))
        {
            plaintext += toupper(ch);
        }
    }

    if (plaintext.length() > key.length())
    {
        cout << "Length not matched" << endl;
        return 0;
    }

    string cipher = encryption(plaintext, key);
    cout << "cipher: " << cipher << endl;
    string decrypt = decryption(cipher, key);
    cout << "decrypt: " << decrypt << endl;
}