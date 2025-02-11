/*
Start with low = 0 and high = n - 1 (where n is the size of nums).
Find the middle element (mid).
Check if nums[mid] is a peak:
If nums[mid] > nums[mid + 1], then the peak is in the left half, so move high to mid.
Otherwise, move low to mid + 1 (since the right half has a higher value).
*/
#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int> nums){
    int n = nums.size();
    int low = 0, high = n-1;
    while(low < high){
        int mid = low + (high - low)/2;
        if(nums[mid] > nums[mid+1]){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {1, 3, 2, 4, 1};
    cout<<findPeakElement(nums)<<endl;
    return 0;
}
