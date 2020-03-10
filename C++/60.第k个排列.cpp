#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==1){
            str=char(int('0'+n));
            return str;
        }
        int fff=1;
        for(int i=1;i<=n-1;++i)fff*=i;
        int left=k%fff;
        int times=k/fff;
        int xXx=0;
        vector<bool> target(n,0);
        if(left==0)left=fff;
        if(left!=0){
            nums.emplace_back(times+1);
            for(int i=1;i<=n;++i){if(i!=times+1)nums.emplace_back(i);}
            permute(target,0,left,xXx);
            return result[left-1];
        }
    }
private:
    vector<string> result;
    vector<int> nums;
    string str;
    void permute(vector<bool> & target,int times,int k,int &xXx){
        if(times == nums.size()){
            result.emplace_back(str);
            xXx++;
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(target[i]==0){
                str+=char(int('0'+nums[i]));
                target[i]=true;
                permute(target,times+1,k,xXx);
                if(xXx==k)return;
                target[i]=false;
                str.erase(str.end()-1,str.end());
            }
        }
    }
};
//直接找到第k个排列
//class Solution {
//    static const vector<int> fac;
//public:
//    string getPermutation(int n, int k) {
//        string res;
//        string s = string("123456789").substr(0, n);
//        --k;
//        while(k > 0)
//        {
//            size_t i = k/fac[n - 1];
//            res.push_back(s[i]);
//            s.erase(s.begin() + i);
//            k %= fac[n - 1];
//            --n;
//        }
//        return res + s;
//    }
//};
//const vector<int> Solution::fac = {0,1,2,6,24,120,720,5040,40320,362880,3628800};

int main() {
    Solution s;
    auto result=s.getPermutation(4,9);
    cout<<result;
    return 0;
}