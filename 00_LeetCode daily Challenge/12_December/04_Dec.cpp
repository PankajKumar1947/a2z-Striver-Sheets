//2264. Largest 3-Same-Digit Number in String

#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool check(string temp){
        if(temp=="999" || temp=="888" || temp=="777" || temp=="666" || temp=="555" || temp=="444" || temp=="333" || temp=="222" || temp=="111" || temp=="000")
            return true;
        return false;
    }
public:
    string largestGoodInteger(string num) {
        string ans="";
        for(int j=0;j<num.length();j++){
            string temp=num.substr(j,3);
            if(check(temp)){
                if(temp>ans)
                    ans=temp;
            }
        }
        return ans;
    }
};