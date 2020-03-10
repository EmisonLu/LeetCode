#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result{};
        vector<int> tmp{};
        int sum=0;
        if(candidates.empty())return result;
        help_me(result,tmp,target,sum,0,candidates);
        for(auto & p : result)sort(p.begin(),p.end());
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
    static void help_me(vector<vector<int>> &result,vector<int> &tmp,int target,int sum,int i,vector<int> &can){
        if(sum>target)return;
        if(sum==target){
            result.emplace_back(tmp);
            return;
        }
        if(sum<target){
            for(;i<can.size();++i){
                tmp.push_back(can[i]);
                help_me(result,tmp,target,sum+can[i],i+1,can);
                tmp.pop_back();
            }
        }
    }
};

void show_result(int str){cout<<str<<" ";}
int main() {
    vector<int> a={2,5,2,1,2};
    int target=5;
    auto result=Solution::combinationSum2(a,target);
    for(auto & p : result){
        for_each((p).begin(),p.end(),show_result);
        cout<<endl;
    }
    return 0;
}