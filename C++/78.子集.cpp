#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())return result;
        help_me(nums.size(),nums);
        return result;
    }
private:
    vector<vector<int>> result{};
    vector<int> temp;
    void help_me(int xXx,vector<int> &nums){
        if(xXx==0){result.emplace_back(temp);return;}
        temp.push_back(nums[xXx-1]);
        help_me(xXx-1,nums);
        temp.pop_back();
        help_me(xXx-1,nums);
    }
};

void show_result(int str){cout<<str<<" ";}
int main() {
    vector<int> a={1,2,3};
    Solution s;
    auto result=s.subsets(a);
    for(auto & p : result){
        for_each((p).begin(),p.end(),show_result);
        cout<<endl;
    }
    return 0;
}