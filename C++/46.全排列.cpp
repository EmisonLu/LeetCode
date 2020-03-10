#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())return result;
        vector<bool> target(nums.size(),0);
        help_me(nums,target,0);
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
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>> result;
//        permute(nums, result, 0);
//        return result;
//    }
//    void permute(vector<int> & nums, vector<vector<int>> & result, int i){
//        if(i == nums.size()){
//            result.push_back(nums);
//            return;
//        }
//        for(int j = i; j<nums.size(); j++){
//            if(i!=j) swap(nums[i], nums[j]);
//            permute(nums, result, i+1);
//            if(i!=j) swap(nums[i], nums[j]);
//        }
//    }
//};

void show_result(int str){cout<<str<<" ";}
int main() {
    vector<int> a={1,2,3};
    Solution s;
    auto result=s.permute(a);
    for(auto & p : result){
        for_each((p).begin(),p.end(),show_result);
        cout<<endl;
    }
    return 0;
}