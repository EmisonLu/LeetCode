#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int l=0,r=nums.size()-1,mid;
        if(nums[0]==target)return 0;
        if(nums[r]==target)return r;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==nums[l])break;
            if(nums[mid]>nums[l]){
                l=mid;
                continue;
            }
            if(nums[mid]<nums[l]){
                r=mid;
                continue;
            }
        }
        if(target<=nums[nums.size()-1]){
            l=l+1;
            r=nums.size()-1;
        }
        if(target>=nums[0]){
            r=l;
            l=0;
        }
        if(nums[nums.size()-1]>nums[0]){
            l=0;
            r=nums.size()-1;
        }
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int lo = 0, hi = nums.size() - 1;
//        while (lo < hi) {
//            int mid = (lo + hi) / 2;
//            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
//                lo = mid + 1;
//            else
//                hi = mid;
//        }
//        return lo == hi && nums[lo] == target ? lo : -1;
//    }
//};
//nums[0] <= nums[mid]（0 - mid不包含旋转）且nums[0] <= target <= nums[mid] 时 high 向前规约；
//nums[mid] < nums[0]（0 - mid包含旋转），target <= nums[mid] < nums[0] 时向前规约（target 在旋转位置到 mid 之间）
//nums[mid] < nums[0]，nums[mid] < nums[0] <= target 时向前规约（target 在 0 到旋转位置之间）
//其他情况向后规约
//也就是说nums[mid] < nums[0]，nums[0] > target，target > nums[mid] 三项均为真或者只有一项为真时向后规约。

int main() {
    vector<int> nums={1,2,3,5,6,-1,0};
    for(int i=-1;i<7;++i) {
        cout << Solution::search(nums, i);
        cout << ' ';
    }
    return 0;
}