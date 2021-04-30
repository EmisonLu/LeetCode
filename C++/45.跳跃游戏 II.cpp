#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    static int jump(vector<int> &nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << Solution::jump(nums);
    return 0;
}
