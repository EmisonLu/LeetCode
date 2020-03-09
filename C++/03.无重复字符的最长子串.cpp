#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
//暴力法
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int start(0),end(0),temp(0),max_temp=0,max=0;
//        int size=s.size();
//        while(++end<=size){
//            max_temp=end-start-1;
//            for(temp=start;temp<end;++temp){
//                if(s[end]==s[temp])break;
//            }
//            if(temp!=end){
//                max_temp=end-start;
//                start=temp+1;
//            }
//            if(temp==end)++max_temp;
//            if(max_temp>max)max=max_temp;
//        }
//        return max;
//    }
//};
//哈希法
class Solution
{
public:
    static int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        unordered_map<char, int> hash;
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};

int main() {
    string s;
    cin>>s;
    Solution t;
    cout<<t.lengthOfLongestSubstring(s);
    return 0;
}
