#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r){
    vector<int> temp;
    int left=l, right=m+1;
    
    while(left<=m && right<=r){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    
    //push the remaining elem from left array
    while(left<=m){
        temp.push_back(arr[left]);
        left++;
    }
    
    //push the remaing right array
    while(right<=r){
        temp.push_back(arr[right]);
        right++;
    }
    
    //copy the temp array in an original array
    for(int i=l;i<=r;i++){
        arr[i]=temp[i-l];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l>=r)
        return ;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);// left half
    mergeSort(arr,mid+1,r);// right half
    merge(arr, l, mid, r);// mergin sorted halves
    
}

int main() {
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " "  ;
    }

    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}