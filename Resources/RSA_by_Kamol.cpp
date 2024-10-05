#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll bigmod(ll base, ll power, ll mod){
    if(power == 1) return base;
    ll sq = (base * base) % mod;
    if(power % 2 == 0) return bigmod(sq, power / 2, mod);
    else return (bigmod(sq, power / 2, mod) * base ) % mod;
}

string encrypt_block(string part, ll key, ll mod){
    ll num = stoi(part);
    ll output = bigmod(num, key, mod);
    string str_out = to_string(output);
    // cout << part << " " << str_out << endl;
    return str_out;
    
}

string encrypt(string plain_text, ll key, ll mod, int input_size){
    string cipher_text;
    int len = (int) plain_text.size();

    for(int i = 0; i < len; i += input_size){
        string block = plain_text.substr(i, input_size);
        string block_cipher = encrypt_block(block, key, mod);
        cipher_text += block_cipher;
    }
    return cipher_text;
}

int main(){
    string plain_text = "6882326879666683";
    int e = 79;
    int d = 1019;
    int n = 3337;
    string cipher_text = encrypt(plain_text, e, n, 3);
    cout << cipher_text << endl;
    string original_text = encrypt(cipher_text, d, n, 4);
    cout << original_text << endl;
    return 0;
}
