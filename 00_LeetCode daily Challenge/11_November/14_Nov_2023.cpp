//1930. Unique Length-3 Palindromic Subsequences
#include<bits/stdc++.h>
using namespace std;

//Brut Force: Space Complexity exceeded.
class Solution {
private:
    void countSubs(int index, string ds, string s, set<string> &st){
        if(index==s.length()){
            if(ds.length()==3 && ds[0]==ds[2])
                st.insert(ds);
            return ;
        }
        ds+=s[index];
        countSubs(index+1,ds,s,st);
        ds.pop_back();
        countSubs(index+1,ds,s,st);
        
    }
public:
    int countPalindromicSubsequence(string s) {
       string ds="";
       set<string> st;
       countSubs(0,ds,s,st);
       return st.size();

    }
};

//Optimal Solution:
class Solution1 {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<int> first(26, s.length());
        vector<int> last(26);

        for (int i = 0; i < s.length(); ++i) {
        const int index = s[i] - 'a';
        first[index] = min(first[index], i);
        last[index] = i;
        }

        for (int i = 0; i < 26; ++i)
        if (first[i] < last[i])
            ans += unordered_set<int>(s.begin() + first[i] + 1, s.begin() + last[i])
                    .size();

        return ans;

    }
};