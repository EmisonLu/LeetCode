#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result{};
        vector<int> tmp{};
        int sum=0;
        if(candidates.empty())return result;
        help_me(result,tmp,target,sum,0,candidates);
        return result;
    }
    static void help_me(vector<vector<int>> &result,vector<int> &tmp,int target,int sum,int i,vector<int> &can){
        if(sum>target)return;
        if(sum==target){result.push_back(tmp);return;}
        if(sum<target){
            for(;i<can.size();++i){
                tmp.push_back(can[i]);
                help_me(result,tmp,target,sum+can[i],i,can);
                tmp.pop_back();
            }
        }
    }
};

void show_result(int str){cout<<str<<" ";}
int main() {
    vector<int> a={1,2,3,6,7};
    int target=7;
    auto result=Solution::combinationSum(a,target);
    for(auto & p : result){
        for_each((p).begin(),p.end(),show_result);
        cout<<endl;
    }
    return 0;
}