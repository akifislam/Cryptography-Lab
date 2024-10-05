#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string encryption(const string &plaintext, int shift)
{
    string ciphertxt;
    for (char ch : plaintext)
    {
        if (isalpha(ch))
        {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base + shift) % 26 + base;
            ciphertxt += ch;
        }
        else if (ch == ' ')
            ciphertxt += ch;
    }
    return ciphertxt;
}

string decryption(const string &ciphertext, int shift)
{
    string plaintext;
    for (char ch : ciphertext)
    {
        if (isalpha(ch))
        {
            char base = islower(ch) ? 'a' : 'A';
            ch = (ch - base - shift + 26) % 26 + base;
            plaintext += ch;
        }
        else if (ch == ' ')
            plaintext += ch;
    }

    return plaintext;
}

int main()
{
    ifstream inputFile("input.txt");
    string plainText;
    getline(inputFile, plainText);
    inputFile.close();

    int shift = 3;
    string ciphertext = encryption(plainText, shift);
    cout << ciphertext << endl;

    cout << decryption(ciphertext, shift) << endl;
}