#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <time.h> 

using namespace std;

int digitcount(int n){ 
    return (log10(n) + 1);
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
    return dec_value;
}


int main()
{
    int d[11], n;
    for(int i = 0; i < 11; i++){
        d[i] = 1;
    }
    d[3] = d[7] = d[9] = d[10] = 0;
    cout<<"Enter 7 bit code : ";
    cin>>n;
    for(int i = 10; i >= 0; i--){
        if(d[i]){
            d[i] = n%10;
            n = n/10;
        }
    }
    d[10] = d[8] ^ d[6] ^ d[4] ^ d[2] ^ d[0];
    d[9] = d[8] ^ d[5] ^ d[4] ^ d[1] ^ d[0];
    d[7] = d[6] ^ d[5] ^ d[4];
    d[3] = d[2] ^ d[1] ^ d[0];
    cout<<"Hamming Code : ";
    for(int i = 0; i < 11; i++){
        cout<<d[i];
    }
    cout<<".\n.\n.\n.\n.\n.\n.\n";
    // Noise
    srand (time(0));
    int pos = rand()%11;
    srand (time(NULL));
    int bit = rand()%2;
    d[pos] = bit;

    cout<<"Received Bits : ";
    for(int i = 0; i < 11; i++){
        cout<<d[i];
    }
    int r4 = d[10] ^ d[8] ^ d[6] ^ d[4] ^ d[2] ^ d[0];
    int r3 = d[9] ^ d[8] ^ d[5] ^ d[4] ^ d[1] ^ d[0];
    int r2 = d[7] ^ d[6] ^ d[5] ^ d[4];
    int r1 = d[3] ^ d[2] ^ d[1] ^ d[0];
    int p = r4 + r3*10 + r2*100 + r1*1000;
    cout<<"\nPosition of error(In Binary) : "<<p;
    cout<<"\nPosition of error(In Decimal) : "<<binaryToDecimal(p);
    if(d[11 - binaryToDecimal(p)] == 0){
        d[11 - binaryToDecimal(p)] = 1;
    }
    else{
        d[11 - binaryToDecimal(p)] = 0;
    }
    cout<<"\nOriginal Hamming Code : ";
    for(int i = 0; i < 11; i++){
        cout<<d[i];
    }
    return 0;
}
