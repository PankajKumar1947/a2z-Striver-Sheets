//1897. Redistribute Characters to Make All Strings Equal
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        //map to store the the count of each character.
        unordered_map<char,int>mpp;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                mpp[words[i][j]]++;
            }
        }

        //find if the count of the character is not equal to the length of the words then return false otherwise return false.
        for(auto it:mpp){
            if(it.second%words.size()!=0)
                return false;
        }

        return true;
    }
};