#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int maxSubArray(vector<int>& nums) {
        int max_(nums[0]),sum(0);
        for(auto p:nums){
            if(sum<0)sum=0;
            sum+=p;
            max_=max(max_,sum);
        }
        return max_;
    }
};

int main() {
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<Solution::maxSubArray(nums);
    return 0;
}