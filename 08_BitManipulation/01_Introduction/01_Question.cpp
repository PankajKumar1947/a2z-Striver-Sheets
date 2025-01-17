#include<bits/stdc++.h>
using namespace std;

//1. Swap two number
void swapNumber(int &a, int &b){
	a=a^b;
	b=a^b;
	a=a^b;
}

//2. Given a number ‘N’ and a number ‘K’. Return true if ‘K’th bit of number is set, else return false.
bool isKthBitSet(int n, int k)
{
    if((n & (1 << k)) != 0)
        return true;
    else
        return false;
}

/*
3.You have a 32-bit unsigned integer called 'num' and another integer called 'i'. (i-> index from the last position of number)
You need to perform the following operations on the 'num' integer based on the value of 'i':
    1. Get the bit value at the "i"th position of "num".
    2. Set the bit at the "i"th position of "num".
    3. Clear the bit at the "i"th position of "num".
*/

void checkIthSetBit(int num , int i){
    //using left sift operator

    // if(num && (1<<i) > 0)
    //     cout<<i<<"th Bit of given number "<<num<<" is Set Bit"<<endl;
    // else
    //     cout<<i<<"th Bit of given number "<<num<<" is Not Set Bit"<<endl;
    

    //Using right shift operator
    if(((num>>i) & 1))
        cout<<"Set Bit";
    else
        cout<<"Not set bit";

}

void setIthSetBit(int num, int i){
    num=num | 1<<i;
    cout<<"Number of Bit after setting"<< i<<"th bit "<<num;
}

void clearSetBit(int num, int i){
    num=num & (~(1<<i));
    cout<<"After clearing "<<i<<" th Bit, Num= "<<num;
}

//4. Toggle the ith bit
void toggleIthBit(int num, int i){
    num=num^(1<<i);
    cout<<"Number after toggling the ith bit"<<num;
}

//5. Remove the last set Bit(right most set bit) from the number
void removeLastSetBit(int num){
    num=num &(num-1);
    cout<<"Number after clearing the set bit "<<num;
}

//6. Check if the number is  a power of 2 or not
void checkPowerOf2(int num){
    //let's observe : 2=10, 4=100, 8=1000, 16=10000
    // all have only one set bit which is in the first
    //here we are removing the last set bit
    if((num & (num-1))==0)
        cout<<num<<" is a Power of 2";
    else
        cout<<num<<" is not a power of 2";
}

int main(){
    //checkIthSetBit(13,2);//check ith set bit;

    //setIthSetBit(13,1);
    //clearSetBit(13,2);
    //toggleIthBit(13,2);
    //removeLastSetBit(13);
    checkPowerOf2(14);
}