#include <iostream>
#include <string>
#include <vector>
using namespace std;

//DFS
class Solution {
public:
    static vector<string> generateParenthesis(int n) {
        vector<string> result={};
        if(n==0)return result;
        help_me(result,"",0,0,n);
        return result;
    }
    static void help_me(vector<string> &result,const string& sSs,int l,int r,int n){
        if(l==n&&r==n){result.push_back(sSs);return;}
        if(l>n||r>n||l<r)return;                        //剪枝
        help_me(result,sSs+"(",l+1,r,n);
        help_me(result,sSs+")",l,r+1,n);
   }
};

void show_result(string &str){cout<<str<<endl;}
int main() {
    int n;
    cin>>n;
    auto result=Solution::generateParenthesis(n);
    for_each(result.begin(),result.end(),show_result);
    return 0;
}