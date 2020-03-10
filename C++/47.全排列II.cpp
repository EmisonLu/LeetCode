#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())return result;
        vector<bool> target(nums.size(),0);
        help_me(nums,target,0);
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
private:
    vector<vector<int>> result{};
    vector<int> xXx{};
    void help_me(vector<int> &nums,vector<bool> &target,int times){
        if(times==nums.size()){result.emplace_back(xXx);return;}
        for(int i=0;i<nums.size();++i){
            if(target[i]==0){
                xXx.emplace_back(nums[i]);
                target[i]=true;
                help_me(nums,target,times+1);
                target[i]=false;
                xXx.pop_back();
            }
        }
    }
};
//妙！
//class Solution {
//    vector<vector<int>> ans;
//
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        perm(nums, 0, nums.size() - 1);
//        return ans;
//    }
//
//    void perm(vector<int> nums, int left, int right) {
//        if (left == right)
//            ans.push_back(nums);
//        else {
//            for (int i = left; i <= right; i++) {
//                if (i != left && nums[left] == nums[i]) continue;  # 去重
//                        swap(nums[left], nums[i]);
//                perm(nums, left + 1, right);
//            }
//        }
//    }
//};

void show_result(int str){cout<<str<<" ";}
int main() {
    vector<int> a={1,1,2};
    Solution s;
    auto result=s.permuteUnique(a);
    for(auto & p : result){
        for_each((p).begin(),p.end(),show_result);
        cout<<endl;
    }
    return 0;
}