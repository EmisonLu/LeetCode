#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result={};
        if(nums.size()<=2)return result;
        sort(nums.begin(),nums.end());
        int start(0),mid(0),end(0),left(0);
        for(start=0;start<=nums.size()-3;++start){
            left=-nums[start];
            mid=start+1;
            end=nums.size()-1;
            while(mid<end){
                if(nums[mid]+nums[end]==left){
                    result.push_back({nums[start],nums[mid],nums[end]});
                    ++mid;
                    --end;
                    continue;
                }
                if(nums[mid]+nums[end]>left){--end;continue;}
                if(nums[mid]+nums[end]<left){++mid;continue;}
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
int main() {
    vector<int> num={-1,0,1,2,-1,-4};
    vector<vector<int>> result=Solution::threeSum(num);
    for(auto & p : result){
        for(int j=0;j<3;++j)cout<<p[j]<<' ';
        cout<<endl;
    }
    return 0;
}