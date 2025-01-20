#include<bits/stdc++.h>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    for(int rnd=0;rnd<arr.size();rnd++){
        for(int j=0;j<arr.size()-1-rnd;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

// Modified Bubble Sort
void modifiedBubbleSort(vector<int>& arr) {
    for(int rnd=0;rnd<arr.size();rnd++){
        bool sortedOrder=true;
        for(int j=0;j<arr.size()-1-rnd;j++){
            if(arr[j]>arr[j+1]){
                sortedOrder=false;
                swap(arr[j],arr[j+1]); 
            }
        }
        if(sortedOrder)
            break;
    }
}

// Recursive Bubble Sort
void recurBubb(vector<int>& arr, int n){
    if(n==1)
        return ;
        
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    recurBubb(arr,n-1);
}

// Optimised Recursive Bubble Sort
void recurBubbleOptimised(vector<int> & arr, int n){
    if(n==1)
        return ;

    int didSwap=false;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            didSwap=true;
        }
    }

    if(!didSwap)
        return ;
    recurBubb(arr,n-1);
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    recurBubbleOptimised(arr,arr.size());
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}