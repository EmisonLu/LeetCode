#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int climbStairs(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        vector<int> a(n+1);
        a[0]=1;
        a[1]=1;
        for(int i=0;i<n-1;++i)
            a[i+2]=a[i]+a[i+1];
        return a[n];
    }
};

int main() {
    cout<<Solution::climbStairs(5);
    return 0;
}