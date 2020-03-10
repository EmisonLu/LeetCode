#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    static void nextPermutation(vector<int>& nums) {
//        int size=nums.size(),min_tr;
//        int j=size-1;
//        while(j>0){
//            if(nums[j-1]<nums[j])break;
//            --j;
//        }
//        if(j==0){sort(nums.begin(),nums.end());return;}
//        --j;
//        int temp=j+1;
//        min_tr=nums[j+1]-nums[j];
//        for(int i=j+1;i<size;++i){
//            if(nums[i]-nums[j]>0&&nums[i]-nums[j]<min_tr){
//                min_tr=nums[i]-nums[j];
//                temp=i;
//            }
//        }
//        swap(nums[j],nums[temp]);
//        auto p=&nums[j+1];
//        sort(p,p+size-j-1);
//   }
//};

class Solution {
public:
    static void nextPermutation(vector<int>& nums) {
        if(!next_permutation(nums.begin(),nums.end()))
            sort(nums.begin(),nums.end());
    }
};

void show(int &x){cout<<x<<' ';}
int main() {
    vector<int> nums={3,2,1};
    Solution::nextPermutation(nums);
    for_each(nums.begin(),nums.end(),show);
    return 0;
}