#include<bits/stdc++.h>
using namespace std;

/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	// Write your code here
	int loc=start;
	while(start<end){
		while(start<end && input[loc]<=input[end])
			end--;
		if(start==end)
			break;
		swap(input[loc],input[end]);
		loc=end;

		while(start<end && input[start]<=input[loc])
			start++;
		if(start==end)
			break;
		swap(input[start],input[loc]);
		loc=start;
	}
	return loc;
}

void quickSort(int input[], int start, int end) {
	int loc=partitionArray(input,start,end);
	if(loc>start+1)
		quickSort(input,start,loc-1);
	if(loc<end-1)
		quickSort(input,loc+1,end);
}

int main(){
    int arr[] = {4,6,2,5,7,9,1,3};
    int n = 8;
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr,0,n-1);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}