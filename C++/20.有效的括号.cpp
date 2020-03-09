#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    static bool isValid(string s) {
        if(s.empty()) return true;
        stack<char> tt;
        if(s[0]=='('||s[0]=='['||s[0]=='{')tt.push(s[0]);
        else return false;
        for(int i=1;i<s.size();++i){
            int a=tt.size();
            if(s[i]=='('||s[i]=='['||s[i]=='{')tt.push(s[i]);
            if(s[i]==')'){
                if(tt.empty())return false;
                if(tt.top()=='(')tt.pop();
                else return false;
            }
            if(s[i]==']'){
                if(tt.empty())return false;
                if(tt.top()=='[')tt.pop();
                else return false;
            }
            if(s[i]=='}'){
                if(tt.empty())return false;
                if(tt.top()=='{')tt.pop();
                else return false;
            }
        }
        return tt.empty();
    }
};

int main() {
    string str;
    cin>>str;
    cout<<Solution::isValid(str);
    return 0;
}