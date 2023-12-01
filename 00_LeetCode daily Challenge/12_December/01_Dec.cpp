//1662. Check If Two String Arrays are Equivalent

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1="",str2="";
        for(int i=0;i<word1.size() || i< word2.size();i++){
            if(i<word1.size())
                str1+=word1[i];
            if(i<word2.size())
                str2+=word2[i];
        }
        return str1==str2;
    }
};

int main(){
    vector<string> word1={"abc", "d", "defg"};
    vector<string> word2={"abcddefg"};
    Solution s;
    bool ans=s.arrayStringsAreEqual(word1,word2);
    ans ?cout<<"True": cout<<"False";
    return 0;
}