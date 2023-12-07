//1903. Largest Odd Number in String
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
       string ans="";
       int i=0;
       for(i=num.length()-1;i>=0;i--){
           if(num[i]%2!=0)
            break;
       } 
       ans=num.substr(0,i+1);
       return ans;
    }
};