#include <iostream>
using namespace std;

class Solution {
public:
    static int divide(int dividend, int divisor) {
        long res(0),left(dividend),t(1);
        if(dividend>=0&&divisor>0){
            while(left>=0){
                ++res;
                left=left-divisor;
            }
            --res;
        }
        if(dividend>=0&&divisor<0){
            while(left>=0){
                --res;
                left=left+divisor;
            }
            ++res;
        }
        if(dividend<0&&divisor>0){
            while(left<0){
                --res;
                left=left+divisor;
            }
        }
        if(dividend<0&&divisor<0){
            while(left<0){
                ++res;
                left=left-divisor;
            }
        }
        if(res<INT_MIN||res>INT_MAX)res=INT_MAX;
        return int(res);
    }
};

int main() {
//    cout<<INT_MAX<<' '<<INT_MIN<<endl;
//    cout<<Solution::divide(2147483647,1);
    return 0;
}