#include <iostream>
#include <vector>
using namespace std;

//暴力法（低效）
//class Solution {
//public:
//    static int maxArea(vector<int>& height) {
//        int result=0,tmp_result=0;
//        for(int i=0;i<height.size();++i){
//            for(int j=i+1;j<height.size();++j){
//                tmp_result=(j-i)*min(height[i],height[j]);
//                result=(result>tmp_result)?result:tmp_result;
//            }
//        }
//        return result;
//    }
//};
//双指针法
class Solution {
public:
    static int maxArea(vector<int>& height) {
        // st 为头指针，en 为尾指针
        int st = 0, en = height.size() - 1;
        // stlas 与 enlas 分别存储 st 与 en 指向的“当前值”
        int stlas, enlas;
        // ans 初始化
        int ans = min(height[st], height[en]) * (en - st);
        while(st < en)
        {
            // 外层 while 控制两指针交替移动
            while(height[st] <= height[en] && st < en)
            {
                stlas = height[st];
                st ++;
                // 内层 while 控制头指针寻找下一个 “值” 大于 “当前值 stlas” 的位置
                while(height[st] <= stlas && st < en) st ++;
                ans = max(ans, min(height[st], height[en]) * (en - st));
            }
            while(height[st] >= height[en] && st < en)
            {
                enlas = height[en];
                en --;
                // 内层 while 控制尾指针寻找下一个 “值” 大于 “当前值 enlas” 的位置
                while(height[en] <= enlas && st < en) en --;
                ans = max(ans, min(height[st], height[en]) * (en - st));
            }
        }
        return ans;
    }
};

int main() {
    vector<int> a{1,8,6,2,5,4,8,3,7};
    cout<<Solution::maxArea(a);
    return 0;
}