#include <bits/stdc++.h>
using namespace std;

/* 
Write a program to find the indices of the first occurrences of the target value.

input:- arr[] = {2, 4, 6, 8, 8, 8, 11, 13}, target = 8
output:- 3

input:- arr[] = {2, 4, 6, 8, 8, 8, 11, 13}, target = 10
output:- -1 i.e 10 is not present in given array therefor output is -1.

*/

//Brute Force Approch:-
/*
"We use linear traversal to find the first occurrence of an element. We traverse the 
array until its size, and whenever the target is found, we store its index and break 
out of the loop."
*/
int firstOccuranceElementBrute(vector<int> nums, int target){
    int n = nums.size();
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(nums[i] == target){
            ans = i;
            break;
        }
    }
    return ans;
}

//Using Binary Search i.e Optimal Approch:-
/*
Intuition: The first thing to note is that we always apply Binary Search to a sorted array; 
therefore, the first occurrence of any element is expected to be on the left side or 
left half of the array.

-->We itearte on array up till low does not cross the high i.e[low <= high].
-->"During the iteration, if we find the target, we store its index as 'ans=mid' and move 
to the left half of the array by updating 'high' to 'mid-1'."

-->During the iteration, if the target is greater than the current element, then move to 
the right half of the array by setting 'low' to 'mid+1'; 
otherwise, 
During the iteration, if the target is less than the current element, then move to 
the left half of the array by setting 'high' to 'mid-1'

*/
int firstOccuranceElementOptimal(vector<int> nums, int target){
    int n = nums.size();
    int ans = -1;

    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] == target){
            ans = mid;
            high = mid-1;
        }
        else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
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

    int target;
    cout<<"Take Target as input for Search: ";
    cin>>target;

    /*
    int ansBrute = firstOccuranceElementBrute(arr, target);
    if(ansBrute == -1) cout<<"Target element is not present in the given Array: "<<endl;
    else cout<<"Target element is present at the index: "<<ansBrute<<endl;
    */

    int ansOptimal = firstOccuranceElementBrute(arr, target);
    if(ansOptimal == -1) cout<<"Target element is not present in the given Array: "<<endl;
    else cout<<"Target element is present at the index: "<<ansOptimal<<endl;
}
