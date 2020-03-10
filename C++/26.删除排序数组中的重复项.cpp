#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        if(nums.empty())return 0;
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
    }
};

int main() {
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    cout<<Solution::removeDuplicates(nums);
    return 0;
}