#include <iostream>
#include <vector>
using namespace std;

class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        size=k;
//        for(int i=1;i<=n;++i)nums.emplace_back(i);
//        help_me(0,0);
//        return result;
//    }
//private:
//    vector<vector<int>> result{};
//    vector<int> nums;
//    vector<int> temp;
//    int size=0;
//    void help_me(int times,int k){
//        if(times>1&&temp[times-2]==temp[times-1])return;
//        if(times==size){
//            result.emplace_back(temp);
//            return;
//        }
//        for(int i=nums[k]-1;i<nums.size();++i){
//            temp.emplace_back(nums[i]);
//            help_me(times+1,i);
//            temp.pop_back();
//        }
//    }
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        if(k == 0) return ans;
        vector<int> line;
        line.reserve(k);
        vector<int> mark(n, 1);
        int last = 0;
        while(true)
        {
            for(int i = last; i < n && n - i >= k - line.size(); ++i)
            {
                if(mark[i])
                {
                    line.push_back(i + 1);
                    mark[i] = 0;
                    if(line.size() == k)
                    {
                        ans.emplace_back(line);
                        line.pop_back();
                        mark[i] = 1;
                    }
                }
            }
            if(line.empty())
                break;
            else
            {
                last = line.back();
                line.pop_back();
                mark[last - 1] = 1;
            }
        }
        return ans;
    }
};

void show_result(int str){cout<<str<<" ";}
int main() {
    vector<int> a={1,2,3};
    Solution s;
    auto result=s.combine(4,3);
    for(auto & p : result){
        for_each((p).begin(),p.end(),show_result);
        cout<<endl;
    }
    return 0;
}