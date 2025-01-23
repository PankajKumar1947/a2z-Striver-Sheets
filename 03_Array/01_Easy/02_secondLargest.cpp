#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE -> WORKS ONLY WHEN NO DUPLICATE ARRAY ELEMENT
void getElements(int arr[],int n)
{
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
    sort(arr,arr+n);
    int small=arr[1];
    int large=arr[n-2];
    cout<<"Second smallest is "<<small<<endl;
    cout<<"Second largest is "<<large<<endl;
}
/*
    Time Complexity: O(NlogN), For sorting the array
    Space Complexity: O(1)
*/

// BETTER APPROACH -> Traverse the array 2 times one for find largest and antoher for second largest
void getSecondLargestSmallest(int arr[],int n)
{
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
    int small=INT_MAX,second_small=INT_MAX;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        small=min(small,arr[i]);
        large=max(large,arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
            second_small=arr[i];
        if(arr[i]>second_large && arr[i]!=large)
            second_large=arr[i];
    }

    cout<<"Second smallest is "<<second_small<<endl;
    cout<<"Second largest is "<<second_large<<endl;
}

// Finding second smallest element
void getSecondSmallest(int arr[],int n){
    if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
    int small=INT_MAX,second_small=INT_MAX;
    int i;
    for(i=0;i<n;i++)
    {
        small=min(small,arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
            second_small=arr[i];
    }

    cout<<"Second smallest is "<<second_small<<endl;
}
/*
    Time Complexity: O(N), We do two linear traversals in our array
    Space Complexity: O(1)
*/



// OPTIMAL SOLUTION : TRAVERSE ARRAY ONLY ONE TIMES
int getSecondLargest(vector<int> &arr) {
    // Code Here
    int firstLong=INT_MIN, secondLong=INT_MIN;
    for(int num:arr){
        if(num>firstLong){
            secondLong=firstLong;
            firstLong=num;
        }else if(secondLong<num && firstLong!=num){
            secondLong=num;
        }
            
    }
    
    return secondLong==INT_MIN ? -1 : secondLong;
}
/*
    Time Complexity: O(N), Single-pass solution
    Space Complexity: O(1)
*/

int main(){
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    return 0;
}
