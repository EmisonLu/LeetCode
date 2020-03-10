#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    static int largestRectangleArea(vector<int>& heights) {
        return help_me(heights,0,heights.size()-1);
    }
private:
    static int help_me(vector<int>& heights,int l,int r){
        if(l>r)return 0;
        int mid=l,re=heights[l];
        for(int i=l;i<=r;++i){
            if(heights[i]<re){
                mid=i;
                re=heights[i];
            }
        }
        int mid_l=mid,mid_r=mid;
        while(mid_l-1>=0&&heights[mid_l-1]>=heights[mid])--mid_l;
        while(mid_r+1<heights.size()&&heights[mid_r+1]>=heights[mid])++mid_r;
        int max_1=heights[mid]*(r-l+1),max_2(0),max_3(0);
        int mid_l_c=mid-1;
        int mid_r_c=mid+1;
        while(mid_l_c>=0&&heights[mid_l_c]<=heights[mid])--mid_l_c;
        while(mid_r_c<heights.size()&&heights[mid_r_c]<=heights[mid])++mid_r_c;
        max_2=help_me(heights,l,mid_l_c);
        max_3=help_me(heights,mid_r_c,r);
        return max(max_1,max(max_2,max_3));
    }
};

int main() {
    vector<int> heights{1,1,1,1,1};
    cout << Solution::largestRectangleArea(heights);
    return 0;
}