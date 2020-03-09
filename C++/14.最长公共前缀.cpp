#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    static string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return string("");
        if(strs.size()==1)
            return strs[0];
        int j;
        string tmp=strs[0],result;
        for(int i=1;i<strs.size();++i){
            j=0;
            if(i>=2)tmp=result;
            result.clear();
            while(j<min(tmp.size(),strs[i].size())&&tmp[j]==strs[i][j]){
                result.append(1,strs[i][j]);
                j++;
            }
            if(result.empty())return result;
        }
        return result;
    }
};
//简洁版（妙！）
//class Solution {
//public:
//    string longestCommonPrefix(vector<string>& strs) {
//        string r = strs.size() ? strs[0] : "";
//        for(auto s: strs){        //基于范围的for循环（C++11）
//            while(s.substr(0, r.size()) != r){
//                r = r.substr(0, r.size() - 1);
//                if(r == "") return r;
//            }
//        }
//        return r;
//    }
//};

int main() {
    vector<string> s={"dog","racecar","car"};
    cout<<Solution::longestCommonPrefix(s);
    return 0;
}