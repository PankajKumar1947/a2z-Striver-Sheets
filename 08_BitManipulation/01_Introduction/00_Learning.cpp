#include<bits/stdc++.h>
using namespace std;

//1. Convert decimal number to binary
string deciToBinary(int n){
    string bin="";
    while(n!=1){
        if(n%2==0)
            bin+="0";
        else
            bin+="1";
        n/=2;
    }
    if(n==1)
        bin+="1";
    else
        bin+="0";
    reverse(bin.begin(),bin.end());
    return bin;
}

//2. Convert binary to decimal
int binaryToDecimal(string bin){
    int num=0;
    int power2=1;//for calculating power of 2.
    for(int i=bin.length()-1;i>=0;i--){
        if(bin[i]=='1')
            num+=power2;
        power2*=2;
    }
    return num;
}

int main(){
    int n=13;
    string bin=deciToBinary(n);
    cout<<"Binary of "<<n<<" is "<<bin<<endl;
    cout<<"Decimal of "<<bin<<" is "<< binaryToDecimal(bin)<<endl;
    return 0;
}