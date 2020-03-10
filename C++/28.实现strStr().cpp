#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static int strStr(const string &haystack,const string &needle) {
        if(needle.empty())return 0;
        auto temp=haystack.find(needle);
        if(temp==haystack.npos)return -1;
        return temp;
    }
};

int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<Solution::strStr(s1,s2);
    return 0;
}