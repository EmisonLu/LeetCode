#include <iostream>
#include <string>
using namespace std;

//暴力法（部分实例无法通过）
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int a=s.size(),max(0);
//        string str,tmp;
//        for(int i=0;i<a;++i){
//            for(int j=i+1;j<=a;++j){
//                str=s.substr(i,j-i);
//                if(judge_method(str)){
//                    if(str.size()>max){
//                        tmp=str;
//                        max=str.size();
//                    }
//                }
//            }
//        }
//        return tmp;
//    }
//private:
//    bool judge_method(string s);
//};
//bool Solution::judge_method(string s) {
//    int a=s.length();
//    for(int i=0;i<a;++i){
//        if(s[i]!=s[a-i-1])return false;
//    }
//    return true;
//}
//中心扩展法
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//记录回文子串起始位置
        int end=0;//记录回文子串终止位置
        int mlen=0;//记录最大回文子串的长度
        for(int i=0;i<len;i++)
        {
            int len1=expendaroundcenter(s,i,i);//一个元素为中心
            int len2=expendaroundcenter(s,i,i+1);//两个元素为中心
            mlen=max(max(len1,len2),mlen);
            if(mlen>end-start+1)
            {
                start=i-(mlen-1)/2;
                end=i+mlen/2;
            }
        }
        return s.substr(start,mlen);
        //该函数的意思是获取从start开始长度为mlen长度的字符串
    }
private:
    int expendaroundcenter(string s,int left,int right)
    //计算以left和right为中心的回文串长度
    {
        int L=left;
        int R=right;
        while(L>=0 && R<s.length() && s[R]==s[L])
        {
            L--;
            R++;
        }
        return R-L-1;
    }
};

int main() {
    string str;
    cin>>str;
    Solution s;
    cout<<s.longestPalindrome(str);
    return 0;
}
