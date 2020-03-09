#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
//    vector<int> twoSum(vector<int> &nums, int target) {
//        int size = nums.size();
//        for (int i = 0; i < size - 1; ++i) {
//            for (int j = i + 1; j < size; ++j) {
//                if (nums[i] + nums[j] == target) {
//                    return {i, j};
//                }
//            }
//        }
//        return {};
//    }
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;//建立hash表存放数组元素
        vector<int> b(2, -1);//存放结果
        for (int i = 0; i < nums.size(); i++)
            a.insert(pair<int, int>(nums[i], i));
        for (int i = 0; i < nums.size(); i++) {
            if (a.count(target - nums[i])==1 && (a[target - nums[i]] != i))
                //判断是否找到目标元素且目标元素不能是本身
            {
                b[0] = i;
                b[1] = a[target - nums[i]];
                break;
            }
        }
        return b;
    }
};


int main(){
    vector<int> a={0,1,2,3};
    int p=4;
    Solution s;
    vector<int> q=s.twoSum(a,p);
    cout<<q[0]<<' '<<q[1];
    return 0;
}
