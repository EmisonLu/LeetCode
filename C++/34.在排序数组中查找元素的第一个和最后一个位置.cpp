#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        int l=0,r=nums.size()-1,mid(0);
        if(target<nums[l]||target>nums[r])return {-1,-1};
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target)break;
            if(nums[mid]<target){
                l=mid+1;
            }
            else r=mid-1;
        }
        if(l>r)return {-1,-1};
        int mid_c=mid;
        while(mid_c-1>=0&&nums[mid_c-1]==nums[mid])--mid_c;
        while(mid+1<=nums.size()-1&&nums[mid+1]==nums[mid])++mid;
        return {mid_c,mid};
    }
};

int main() {
    vector<int> nums={5,7,7,8,8,10};
    auto result=Solution::searchRange(nums,9);
    cout<<result[0]<<' '<<result[1];
    return 0;
}