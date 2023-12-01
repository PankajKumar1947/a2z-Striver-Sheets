//1980. Find Unique Binary String

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateBin(int len, vector<string> &AllBinString, string temp){
        if(temp.length()==len){
            AllBinString.push_back(temp);
            return ;
        }
        temp+="0";
        generateBin(len,AllBinString,temp);
        temp.pop_back();
        temp+="1";
        generateBin(len,AllBinString,temp);
        temp.pop_back();
    }


    //for understanding: printing allBinString
    void printgeneratedString(vector<string> AllBinString){
        for(auto it:AllBinString){
            cout<<it<<endl;
        }
    }
   
public:
    string findDifferentBinaryString(vector<string>& nums) {
        vector<string> AllBinString;
        string temp="";
        int n=nums[0].length();
        generateBin(n,AllBinString,temp);

        //now check the required condn
        for(auto it:AllBinString){
            bool check=false;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==it){
                    check=true;
                    break;
                }
            }
            if(check==false)
                return it;
            
        }
        return "";
        
        
    }
};

int main(){
    Solution S;
    vector<string> nums={"111","011","001"};
    cout<<S.findDifferentBinaryString(nums);
    return 0;
}