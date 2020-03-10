#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size(),sum=0;
        vector<vector<long>> a(rows,vector<long>(cols));
        for(int i=cols-1;i>=0;--i){
            sum+=grid[rows-1][i];
            a[rows-1][i]=sum;
        }
        sum=0;
        for(int i=rows-1;i>=0;--i){
            sum+=grid[i][cols-1];
            a[i][cols-1]=sum;
        }
        for(int i=cols-2;i>=0;--i)
            for(int j=rows-2;j>=0;--j){
                sum=min(a[j+1][i],a[j][i+1]);
                a[j][i]=sum+grid[j][i];
            }
        return a[0][0];
    }
};

int main() {
    vector<vector<int>> AbA={
            {1,3,1},
            {1,1,1},
            {0,2,1}
    };
    cout<<Solution::minPathSum(AbA);
    return 0;
}