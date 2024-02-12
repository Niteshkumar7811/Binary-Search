#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array of N integers and an integer x, write a program to find the lower 
bound of x.

input:- array[] = {1,2,2,3},  x = 2
output:- 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.

input:- array[] = {3,5,8,15,19},  x = 9
output:- 3
Explanation: Index 3 is the smallest index such that arr[3] >= x.
*/

/*
LOWER BOND:-The lower bound algorithm finds the first or the smallest index in a sorted 
array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index 
is not found, the lower bound algorithm returns n i.e. size of the given array.
*/

int implementLowerBondBrute(vector<int>&nums, int x){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] >= x) return i;
    }
    return n;
}

int implementLowerBondOptimal(vector<int> &nums, int x){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int mid = low + (high-low)/2;
    int ans = n;

    while(low <= high){
        if(nums[mid] >= x){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;

        mid = low + (high-low)/2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the Array: ";
    cin>> n;

    vector<int> arr(n);
    cout<<"Enter the number for input array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int x;
    cout<<"Take X as input for find Lower Bond: ";
    cin>>x;

    int bruteAns = implementLowerBondBrute(arr, x);
    cout<<"Brute Force Approch:- The lower Bond Index is: "<<bruteAns<<endl;

    int optimalAns = implementLowerBondOptimal(arr, x);
    cout<<"Optimal Approch:- The lower Bond Index is: "<<optimalAns<<endl;
}