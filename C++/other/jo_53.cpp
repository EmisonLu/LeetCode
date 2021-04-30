#include <iostream>
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    static int missingNumber(vector<int> &nums) {
        int left(0), right(int(nums.size()) - 1), mid;
        if (int(nums.size()) == 0) {
            return -1;
        }
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> a = {1};
    cout << Solution::missingNumber(a);
    return 0;
}
