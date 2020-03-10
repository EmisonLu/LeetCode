#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        auto p=nums.begin();
        while(p!=nums.end()){
            if(*p==val){
                nums.erase(p);
                continue;
            }
            ++p;
        }
        return nums.size();
    }
};

int main() {
    vector<int> nums={3,2,2,3};
    cout << Solution::removeElement(nums,3);
    return 0;
}