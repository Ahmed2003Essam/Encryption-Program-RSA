using namespace std;
using ll = long long;
#include <bits/stdc++.h>
#include <iostream>

ll Pow_mod ( ll a , ll b, ll n ) {  
    ll power = 1 , i ;  
    for ( i = 1 ; i <= b ; i++) {  
        power = power * a ;
        power = power % n; 
    }  
    return power ;  
} 

int main() {
   int reverse;
   ll p, q, n, f,coprime_numbers_with_n, e, d, encrypted_code_letter; 
   string message, encrypted_message; 
   vector<string>  ASCII_code;
   vector<ll>  encrypted_messages_vec; 
   p = 47; 
   q = 59; 
   n= p*q; 

  coprime_numbers_with_n = (p-1) *  (q-1);
  
  
       for(ll i = 2; i <coprime_numbers_with_n; i++){
        if( (__gcd(i, coprime_numbers_with_n) == 1) && (__gcd(i,n) == 1 )){
            e =  i; 
            break;
        }
    }
    
      for(ll i = 2; i <coprime_numbers_with_n; i++){
        if( ((i*e) % coprime_numbers_with_n == 1) ){
            d = i;
            break;
        }
    }
    

  cout << "Please enter the message you want to encrypt\n"; 
   getline(cin, message); 
    
      for (int i = 0; i < message.length(); i++)
    {
        char c = message.at(i);
        f = int(c);
        ASCII_code.push_back(to_string(f));
    }
    
        
          cout << "Our Key is (" << n << "," << e << ")" << endl; 
  
        
        for(int i = 0; i < ASCII_code.size();i++){
        encrypted_code_letter = Pow_mod(stoi(ASCII_code[i]), e, n);
        encrypted_message += to_string(encrypted_code_letter) + " "; 
    }
    
    cout << "This is our Encoded message:" << encrypted_message << endl;
}