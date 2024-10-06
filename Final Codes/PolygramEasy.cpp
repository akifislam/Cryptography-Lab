#include <iostream>
#include <map>
#include <string>

using namespace std;

// Encrypt function using a polygram substitution cipher
string encryptPolygram( string plaintext,  map<string, string> cipherMap) {
    string ciphertext = "";
    for (size_t i = 0; i < plaintext.length(); i++) {
        string block = plaintext.substr(i, 3);  // Take blocks of 3 characters
        
        if (cipherMap.find(block)!= cipherMap.end()){
            ciphertext+=cipherMap[block];
            i+=2;
        }
        else{
            ciphertext+=plaintext[i];
        }
  
    }
    return ciphertext;
}

// Decrypt function using a polygram substitution cipher
string decryptPolygram( string ciphertext,  map<string, string> decipherMap) {
    string plaintext = "";
    for (size_t i = 0; i < ciphertext.length(); i++) {
        string block = ciphertext.substr(i, 3);  // Take blocks of 3 characters
        
        if (decipherMap.find(block)!= decipherMap.end()){
            plaintext+=decipherMap[block];
            i+=2;
        }
        else{
            plaintext+=ciphertext[i];
        }
  
    }
    return plaintext;
}

int main() {
    // Define the cipher map for encryption (3-letter blocks)
    map<string, string> cipherMap;
    cipherMap.insert(make_pair("ABC", "XYZ"));
    cipherMap.insert(make_pair("DEF", "LMN"));
    cipherMap.insert(make_pair("GHI", "OPQ"));
    
    // Define the decipher map for decryption
    map<string, string> decipherMap;
    decipherMap.insert(make_pair("XYZ", "ABC"));
    decipherMap.insert(make_pair("LMN", "DEF"));
    decipherMap.insert(make_pair("OPQ", "GHI"));

    // Input plaintext and encrypt
    string plaintext = "ABCXDEFGHIX";
    cout<<"Original Text :"<<plaintext<<endl;
    string ciphertext = encryptPolygram(plaintext, cipherMap);

    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt the ciphertext back to plaintext
    string decryptedText = decryptPolygram(ciphertext, decipherMap);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
