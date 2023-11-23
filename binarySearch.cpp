#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n-1;
    int mid = low + (high-low)/2;

    while (low <= high){
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) low = mid+1;
        else high = mid-1;

        mid = low + (high-low)/2;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Take the size of the input array: ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter the number for input array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int target;
    cout<<"Take target as input for search: ";
    cin >> target;

    int ans = binarySearch(arr,target);
    if(ans == -1){
        cout<<"The target element is not present";
    }
    else cout<<"The target element is present at index: "<<ans<<endl;
}