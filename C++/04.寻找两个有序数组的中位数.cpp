#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        copy(nums2.begin(),nums2.end(),insert_iterator<vector<int>>(nums1,nums1.end()));
//        sort(nums1.begin(),nums1.end());
//        int size=nums1.size();
//        double s;
//        if(size%2==0) s=(nums1[size/2-1]+nums1[size/2])/double(2);
//        else s=nums1[(size-1)/2];
//        return s;
//    }
//};

//二分法
//#define max(a,b) (((a) > (b)) ? (a) : (b))
//#define min(a,b) (((a) < (b)) ? (a) : (b))
//
//class Solution {
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        int n = nums1.size();
//        int m = nums2.size();
//
//        if (n > m)  //保证数组1一定最短
//        {
//            return findMedianSortedArrays(nums2, nums1);
//        }
//
//        // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
//        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
//
//        while (lo <= hi)   //二分
//        {
//            c1 = (lo + hi) / 2;  //c1是二分的结果
//            c2 = m + n - c1;
//
//            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
//            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
//            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
//            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];
//
//            if (LMax1 > RMin2)
//                hi = c1 - 1;
//            else if (LMax2 > RMin1)
//                lo = c1 + 1;
//            else
//                break;
//        }
//        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
//    }
//};



int main() {
    vector<int> a={1,2,3};
    vector<int> b={8,10,11};
    Solution s;
    cout<<fixed;
    cout.precision(1);
    cout<<s.findMedianSortedArrays(a,b);
    return 0;
}
