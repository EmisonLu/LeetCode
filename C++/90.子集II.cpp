#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        if(nums.empty())return result;
//        help_me(nums.size(),nums);
//        for(auto & p:result){
//            sort(p.begin(),p.end());
//        }
//        sort(result.begin(),result.end());
//        result.erase(unique(result.begin(),result.end()),result.end());
//        return result;
//    }
//private:
//    vector<vector<int>> result{};
//    vector<int> temp;
//    void help_me(int xXx,vector<int> &nums){
//        if(xXx==0){result.emplace_back(temp);return;}
//        temp.push_back(nums[xXx-1]);
//        help_me(xXx-1,nums);
//        temp.pop_back();
//        help_me(xXx-1,nums);
//    }
//};
//妙！
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res = {{}};//res.size()=1
        sort(nums.begin(), nums.end());
        int start = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            start = (i && nums[i] == nums[i - 1])?start:0;
            int len = res.size();
            for(int j = start; j < len; j++)
            {
                auto tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
            start = len;
        }
        return res;
    }
};

void show_result(int str){cout<<str<<" ";}
int main() {
    vector<int> a={1,2,2};
    Solution s;
    auto result=s.subsetsWithDup(a);
    for(auto & p : result){
        for_each((p).begin(),p.end(),show_result);
        cout<<endl;
    }
    return 0;
}