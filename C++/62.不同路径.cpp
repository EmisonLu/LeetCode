#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int uniquePaths(int m, int n) {
        if(m==1||n==1)return 1;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<m-1;++i)a[n-1][i]=1;
        for(int i=0;i<n-1;++i)a[i][m-1]=1;
        for(int i=m-2;i>=0;--i)
            for(int j=n-2;j>=0;--j)
                a[j][i]=a[j+1][i]+a[j][i+1];
        return a[0][0];
    }
};

int main() {
    cout<<Solution::uniquePaths(3,2);
    return 0;
}