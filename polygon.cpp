#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to encrypt using Polygram Substitution Cipher with block size of 3
string encryptPolygram(const string &plaintext, unordered_map<string, string> &substitutionKey, int blockSize)
{
    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++)
    {
        string block = plaintext.substr(i, blockSize); // Get a block of 3 characters
        if (substitutionKey.find(block) != substitutionKey.end())
        {
            ciphertext += substitutionKey[block]; // Substitute the block
            i += blockSize - 1;
        }
        else
        {
            ciphertext += plaintext[i]; // If no substitution exists, keep the block unchanged
        }
    }

    return ciphertext;
}

// Function to decrypt using Polygram Substitution Cipher with block size of 3
string decryptPolygram(const string &ciphertext, unordered_map<string, string> &reverseKey, int blockSize)
{
    string plaintext = "";

    for (int i = 0; i < ciphertext.length(); i++)
    {
        string block = ciphertext.substr(i, blockSize); // Get a block of 3 characters
        if (reverseKey.find(block) != reverseKey.end())
        {
            plaintext += reverseKey[block]; // Reverse the substitution
            i += blockSize - 1;
        }
        else
        {
            plaintext += ciphertext[i]; // If no reverse substitution exists, keep the block unchanged
        }
    }

    return plaintext; // Remove padding after decryption
}

int main()
{
    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Remove any non-alphabetic characters and convert to uppercase
    string cleanText = "";
    for (char ch : plaintext)
    {
        if (isalpha(ch))
        {
            cleanText += toupper(ch); // Convert to uppercase for uniformity
        }
    }

    // Define the substitution key (Example key for blocks of 3 letters)
    unordered_map<string, string> substitutionKey = {
        {"BAN", "PQR"}, {"GLA", "XYZ"}, {"DES", "ABC"}
        // Add more substitutions as needed
    };

    // Create the reverse key for decryption
    unordered_map<string, string> reverseKey;
    for (auto &pair : substitutionKey)
    {
        reverseKey[pair.second] = pair.first;
    }

    // Encryption
    int blockSize = 3; // Block size for polygram cipher
    string ciphertext = encryptPolygram(cleanText, substitutionKey, blockSize);
    cout << "Encrypted Text: " << ciphertext << endl;

    // Decryption
    string decryptedText = decryptPolygram(ciphertext, reverseKey, blockSize);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
