#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static bool isPalindrome(int x) {
        if(x<0)return false;
        int tmp=x,t;
        string str;
        while(tmp>=1){
            t=tmp%10;
            str+=char(48+t);
            tmp/=10;
        }
        string s=str;
        reverse(str.begin(),str.end());
        if(str==s)return true;
        else return false;
    }
};
int main()
{
    int x;
    cin>>x;
    Solution s;
    cout<<s.isPalindrome(x);
    return 0;
}
