#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())return 0;
        int l=0,r=nums.size()-1,mid(0);
        if(target<nums[l])return 0;
        if(target>nums[r])return r+1;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};

int main() {
    vector<int> nums={1,3,5,6};
    cout<<Solution::searchInsert(nums,7);
    return 0;
}