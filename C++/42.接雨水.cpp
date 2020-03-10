#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int trap(vector<int>& height) {
        if(height.empty()||height.size()==1)return 0;
        int left=0,right=int(height.size()-1),left_max=height[0],right_max=height[right],sum(0);
        while(left<right){
            if(left_max<=right_max){
                ++left;
                if(left_max<height[left])left_max=height[left];
                else sum+=left_max-height[left];
            }
            else{
                --right;
                if(right_max<height[right])right_max=height[right];
                else sum+=right_max-height[right];
            }
        }
        return sum;
    }
};

int main() {
    vector<int> tr{0,1,0,1};
    cout<<Solution::trap(tr);
    return 0;
}