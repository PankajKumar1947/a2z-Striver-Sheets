#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE : USING MAP
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
    map < int, int > freq;
    vector < int > Union;
    for (int i = 0; i < n; i++)
        freq[arr1[i]]++;
    for (int i = 0; i < m; i++)
        freq[arr2[i]]++;
    for (auto & it: freq)
        Union.push_back(it.first);
    return Union;
}
/*
    Time Compleixty : O( (m+n)log(m+n) ) . Inserting a key in map takes logN times, where N is no of elements in map. 
    At max map can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across insertion of all elements in worst it would take O((m+n)log(m+n) time.
    Using HashMap also takes the same time, On average insertion in unordered_map takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

    Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 
    O(1) {If Space of union ArrayList is not considered}
*/

// BETTER APPROACH : USING SET
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
    set < int > s;
    vector < int > Union;
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);
    for (int i = 0; i < m; i++)
        s.insert(arr2[i]);
    for (auto & it: s)
        Union.push_back(it);
    return Union;
}

// OPTIMAL APPROACH : USING 2 POINTER APPLOACH
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0; // pointers
    vector < int > Union; // Uninon vector
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]){
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        } else{
        if (Union.size() == 0 || Union.back() != arr2[j])
            Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n){
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m){
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}

/*
    Time Complexity : O(m+n)
    Space Complexity : O(m+n)
*/

int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector < int > Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto & val: Union)
        cout << val << " ";
    return 0;
}


