#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())return {};
        rows=matrix.size();
        cols=matrix[0].size();
        help_me(matrix,0);
        return res;
    }
private:
    int rows=0;
    int cols=0;
    vector<int> res;
    void help_me(vector<vector<int>>& matrix,int times){
        if(cols-2*times==0)return;
        if(rows-2*times==0)return;
        if(rows-2*times==1){
            for(int x=0;x<cols-2*times;++x)
                res.emplace_back(matrix[times][times+x]);
            return;
        }
        if(cols-2*times==1){
            for(int x=0;x<rows-2*times;++x)
                res.emplace_back(matrix[times+x][times]);
            return;
        }
        for(int x=0;x<cols-2*times-1;++x)
            res.emplace_back(matrix[times][times+x]);
        for(int x=0;x<rows-2*times-1;++x)
            res.emplace_back(matrix[times+x][cols-times-1]);
        for(int x=0;x<cols-2*times-1;++x)
            res.emplace_back(matrix[rows-times-1][cols-times-1-x]);
        for(int x=0;x<rows-2*times-1;++x)
            res.emplace_back(matrix[rows-times-1-x][times]);
        help_me(matrix,times+1);
    }
};

//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        vector <int> ans;
//        if(matrix.empty()) return ans; //若数组为空，直接返回答案
//        int u = 0; //赋值上下左右边界
//        int d = matrix.size() - 1;
//        int l = 0;
//        int r = matrix[0].size() - 1;
//        while(true)
//        {
//            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
//            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
//            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
//            if(-- r < l) break; //重新设定有边界
//            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
//            if(-- d < u) break; //重新设定下边界
//            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
//            if(++ l > r) break; //重新设定左边界
//        }
//        return ans;
//    }
//};

void show(int x){cout<<x<<' ';}
int main() {
    vector<vector<int>> nums={
            { 2,3},
            { 5,6},
            { 8,9},
            { 11,12},
            {14,15}
    };
    Solution s;
    auto res=s.spiralOrder(nums);
    for_each(res.begin(),res.end(),show);
    return 0;
}