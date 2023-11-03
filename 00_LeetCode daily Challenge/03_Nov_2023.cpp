//1441. Build an array from stack operations push and pop
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<string>buildArray(vector<int>& target, int n){
        vector<string>ans;
        int index = 0;

        for(int i=1;i<=n && index<target.size();i++){
            if(target[index]==i){
                ans.push_back("Push");
                index++;
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};


int main(){
    Solution s;
    vector<int> target={1,2,3};
    int n=3;
    vector<string> ans;
    ans=s.buildArray(target,n);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
    return 0;
}