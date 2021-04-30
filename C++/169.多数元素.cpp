#include <iostream>
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    static int majorityElement(vector<int> &nums) {
        map<int, int> map;
        for (int &num : nums) {
            if (map.find(num) == map.end()) {
                map[num] = 1;
                continue;
            }
            map[num]++;
        }
        for (auto &p : map) {
            if (p.second > nums.size() / 2)
                return p.first;
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    cout << Solution::majorityElement(nums);
    return 0;
}
