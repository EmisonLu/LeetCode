#include <iostream>
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    static int minimumTotal(vector<vector<int>> &triangle) {
        int size = triangle.size();
        int *res_up = new int[size];
        int *res_down = new int[size];
        res_up[0] = triangle[0][0];
        for (int i = 0; i < size - 1; ++i) {
            res_down[0] = res_up[0] + triangle[i + 1][0];
            for (int j = 0; j < i; ++j) {
                res_down[j + 1] = triangle[i + 1][j + 1] + min(res_up[j], res_up[j + 1]);
            }
            res_down[i + 1] = res_up[i] + triangle[i + 1][i + 1];
            auto ptr = res_up;
            res_up = res_down;
            res_down = ptr;
        }
        int min(res_up[0]);
        for (int i = 0; i < size; ++i) {
            min = min < res_up[i] ? min : res_up[i];
        }
        delete[]res_up;
        delete[]res_down;
        return min;
    }
};

int main() {
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    cout << Solution::minimumTotal(triangle);
    return 0;
}
