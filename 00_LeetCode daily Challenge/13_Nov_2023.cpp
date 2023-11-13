//2785. Sort Vowels in a String
#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Note that We can also use this isVowel Function to check where the character is a vowel or not .
private:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
public:
    string sortVowels(string s) {
        vector<char> temp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
             s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                temp.push_back(s[i]);
        }

        sort(temp.begin(),temp.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
             s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                 s[i]=temp[j];
                 j++;
             }
        }
        return s;
    }
};

int main(){
    string s="lEetcOde";
    Solution St;
    string sortedAns=St.sortVowels(s);

    cout<<"Result:  "<<sortedAns;

    return 0;
}