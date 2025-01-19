#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
    for(int i=0;i<arr.size();i++){
        int minInd=i;
        int minVal=arr[i];
        for(int j=i+1;j<arr.size();j++){
            if(minVal>arr[j]){
                minVal=arr[j];
                minInd=j;
            }
        }
        swap(arr[i],arr[minInd]);
    }
}

void bubbleSort(vector<int>& arr) {
    for(int rnd=0;rnd<arr.size();rnd++){
        for(int j=0;j<arr.size()-1-rnd;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

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

void insertionSort(vector<int>& arr) {
    for(int i=1;i<arr.size();i++){
        int j=i;
        int temp=arr[i];
        
        while(j-1>=0 && arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
        }
        
        arr[j]=temp;
    }
}

int main(){
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    
    
    insertionSort(arr);
    cout << "After Using insertion Sort: " << endl;
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
    return 0;
}