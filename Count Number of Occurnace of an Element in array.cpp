#include <bits/stdc++.h>
using namespace std;

/*
Write a program to find the total number of occurrences of the target value.

input:- array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}, target = 3
output:- 4

input:- array[] = {1, 1, 2, 2, 2, 2, 2, 3}, target = 2
output:- 5
*/

//Brute Force Approch:-[Using Map]
/*
We use 'map' dadat structure which store unique key and its value as well.
"We have an 'ans' variable and a 'map' data structure. During array traversal, 
each element of the array is added to the map."

"We then perform a subsequent traversal on the 'map'. If the target element is found 
(checked using it.first == target), we store the corresponding value in 'ans' 
(ans = it.second) and return 'ans'."
*/

int countOccuranceElementMap(vector<int> &nums, int target){
    int ans = 0;
    map<int, int> mpp;

    for(auto it : nums){
        mpp[it]++;
    }

    for(auto it : mpp){
        if(it.first == target) ans = it.second;
    }
    return ans;
}


//Better Approch Force Apprch:-
/*
"We use a counter variable to track the number of occurrences of an element. We perform a 
linear traversal up to the size of the array, and whenever we find the target element, 
we increment the counter variable by 1, returning the final count."
*/
int countOccuranceElementBrute(vector<int> &nums, int target){
    int n = nums.size();
    int count = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == target) count++;
    }
    return count;
}

//Optimal Approch:-Binary Search
/*
Observation:-
Total number of occurrences = [last occurrence – first occurrence]+1

"The 'First Occurrence' and 'Last Occurrence' functions provide the first and last index 
of the target element in an array. The total occurrence of the target element is 
calculated as the difference between the last and first indices. 
To obtain the actual count, we add 1 to this difference."
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

int lastOccuranceElementOptimal(vector<int> &nums, int target){
    int n = nums.size();
    int ans = -1;
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] == target){
            ans = mid;
            low = mid+1;
        }
        else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return ans;
}

int countOccuranceElementOptimal(vector<int> &nums, int target){
    int lastPosition = lastOccuranceElementOptimal(nums, target);
    int firstPosition = firstOccuranceElementOptimal(nums, target);

    if(lastPosition == -1 && firstPosition == -1) return 0;

    int ans = (lastPosition - firstPosition)+1;
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
    int ansMap = countOccuranceElementMap(arr, target);
    if(ansMap== 0) cout<<"Target element is not present in the given Array: "<<endl;
    else cout<<"Total count of Target element is: "<<ansMap<<endl;
    */

    /*
    int ansBrute = countOccuranceElementBrute(arr, target);
    if(ansBrute == 0) cout<<"Target element is not present in the given Array: "<<endl;
    else cout<<"Total count of Target element is: "<<ansBrute<<endl;
    */
    


    int ansOptimal = countOccuranceElementOptimal(arr, target);
    if(ansOptimal == 0) cout<<"Target element is not present in the given Array: "<<endl;
    else cout<<"Total count of Target element is: "<<ansOptimal<<endl;
}
