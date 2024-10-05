#include <iostream>
#include <fstream>

using namespace std;


string ceaser_cipher_encryption(string input, int shift){
    string cipher;

    for(int i =0; i<input.length();i++){
        char ch = input[i];
        if(isalpha(ch)){
            char base;
            if (islower(ch)){
                base = 'a';
            }
            else
                base = 'A';

            cipher+=(ch-base+shift)%26+base;
            
        }
    }
    return cipher;
}

string ceaser_cipher_decryption(string input, int shift){
    string encrypted_text;

    for(int i =0; i<input.length();i++){
        char ch = input[i];
        if(isalpha(ch)){
            char base = 0;
            if (islower(ch)){
                base = 'a';
            }
            else
                base = 'A';
                
            encrypted_text+=(ch-base-shift+26)%26+base;
            
        }
    }
    return encrypted_text;
}


int main(){
    ifstream file("input.txt");
    string input;
    getline(file, input); 
   
   string encrypted_text = ceaser_cipher_encryption(input,3);
   cout<<"Encrypted Text: "<<encrypted_text<<endl;

   string decrypted_text = ceaser_cipher_decryption(encrypted_text,3);
   cout<<"Decrypted Text: "<<decrypted_text<<endl;
}