#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static void rotate(vector<vector<int>>& matrix) {
        rotate_c(matrix,0,matrix.size()-1);
    }
private:
    static void rotate_c(vector<vector<int>>& matrix,int l,int r){
        if(l==r)return;
        int temp;
        for(int i=0;i<r-l;++i){
            temp=matrix[l][i+l];
            matrix[l][i+l]=matrix[r-i][l];
            matrix[r-i][l]=matrix[r][r-i];
            matrix[r][r-i]=matrix[i+l][r];
            matrix[i+l][r]=temp;
        }
        if(r-l==1)return;
        rotate_c(matrix,l+1,r-1);
    }
};

int main() {
    vector<vector<int>> matrix={
            {5, 1, 9,11},
            {2, 4, 8,10},
            {13, 3, 6, 7},
            {15,14,12,16}
    };
    Solution::rotate(matrix);
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j)
            cout<<matrix[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}