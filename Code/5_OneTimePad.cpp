#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


string encrypt_otp(string plaintext,string KEY){
    string cipher_text = "";

    for (int i = 0; i < plaintext.length(); i++)
    {
        if(isalpha(plaintext[i])){
            char p = plaintext[i]-'A';
            char k = KEY[i]-'A';
            char c = ((p+k)%26)+'A'+1;
            cout<<int(p)<<"-"<<int(k)<<"-"<<c<<endl;
            cipher_text+=c;
        }
    }
    return cipher_text;

}

string decrypt_otp(string encrypted_text,string KEY){
    string decrypted_text = "";

    for (int i = 0; i < encrypted_text.length(); i++)
    {
        if(isalpha(encrypted_text[i])){
            char p = encrypted_text[i]-'A';
            char k = KEY[i]-'A';
            char c = (p-k+26-1)%26+'A';

            decrypted_text+=c;
        }
    }
    return decrypted_text;

}


int main(){
    ifstream file("input.txt");
    string input;
    getline(file,input);
    string KEY = "TBFRGFARFM";

    string encrypted_text = encrypt_otp(input,KEY);
    cout<<encrypted_text<<endl;

    string decrypted_text = decrypt_otp(encrypted_text,KEY);
    cout<<decrypted_text<<endl;

}