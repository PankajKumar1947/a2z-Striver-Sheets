#include<bits/stdc++.h>
using namespace std;

int recur(int start,int end,vector<int>& arr){
    if(start>end)
        return 1000000;
       
    if(start==end)
        return 0;

    cout<<"start="<<start<<endl;
    
    int mini=1000000;
    for(int i=0;i<arr.size();i++){
        start=(start*arr[i])%100000;
        mini=min(mini,1+recur(start,end,arr));
    }
    cout<<"value"<<mini<<" ";
    return mini;   
}

int minimumMultiplications(vector<int>& arr, int start, int end) {
    // code here
    int ans=recur(start,end,arr);
    if(ans==1000000)
        return -1;
    return ans;
}

int main(){
    vector<int>arr={3, 4, 65};
    int start=7, end=66175;
    cout<<"ans="<<minimumMultiplications(arr,start,end);

    return 0;
}