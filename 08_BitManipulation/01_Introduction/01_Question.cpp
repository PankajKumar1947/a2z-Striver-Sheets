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
3.You have a 32-bit unsigned integer called 'num' and another integer called 'i'.
You need to perform the following operations on the 'num' integer based on the value of 'i':
    1. Get the bit value at the "i"th position of "num".
    2. Set the bit at the "i"th position of "num".
    3. Clear the bit at the "i"th position of "num".
*/

int main(){

}