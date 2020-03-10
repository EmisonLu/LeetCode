#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        cols=board[0].size();
        rows=board.size();
        str=word;
        int **visited=new int*[rows];
        for(int i=0;i<rows;++i){
            visited[i]=new int[cols];
            for(int j=0;j<cols;++j){
                visited[i][j]=0;
            }
        }
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(board[i][j]==word[0]){
                    if(search_judge(board,visited,i,j,0))return true;
                }
            }
        }
        for(int i=0;i<rows;++i){
            delete []visited[i];
        }
        delete [] visited;
        return false;
    }
private:
    int rows=0;
    int cols=0;
    string str;
    bool search_judge(vector<vector<char>>& board,int**visited,int i,int j,int index){
        if(index==str.length()-1)return true;
        visited[i][j]=1;
        if(i+1<rows&&board[i+1][j]==str[index+1]&&visited[i+1][j]==0){
            if(search_judge(board,visited,i+1,j,index+1))return true;
        }
        if(i-1>=0&&board[i-1][j]==str[index+1]&&visited[i-1][j]==0){
            if(search_judge(board,visited,i-1,j,index+1))return true;
        }
        if(j+1<cols&&board[i][j+1]==str[index+1]&&visited[i][j+1]==0){
            if(search_judge(board,visited,i,j+1,index+1))return true;
        }
        if(j-1>=0&&board[i][j-1]==str[index+1]&&visited[i][j-1]==0){
            if(search_judge(board,visited,i,j-1,index+1))return true;
        }
        visited[i][j]=0;
        return false;
    }
};

//class Solution {
//public:
//    bool dfs(vector<vector<char>> & board, int row, int col, string & word, int index) {
//        int maxRow = board.size();
//        int maxCol = board[0].size();
//        if(index == word.length() - 1) {
//            return true;
//        }
//        board[row][col] = '\n';
//        if(row + 1 < maxRow && board[row + 1][col] == word[index + 1]) {
//            if(dfs(board, row + 1, col, word, index + 1)) return true;
//        }
//
//        if(row - 1 >= 0 && board[row - 1][col] == word[index + 1]) {
//            if(dfs(board, row - 1, col, word, index + 1)) return true;
//        }
//
//        if(col + 1 < maxCol && board[row][col + 1] == word[index + 1]) {
//            if(dfs(board, row, col + 1, word, index + 1)) return true;
//        }
//
//        if(col - 1 >= 0 && board[row][col - 1] == word[index + 1]) {
//            if(dfs(board, row, col - 1, word, index + 1)) return true;
//        }
//        board[row][col]=word[index];
//        return false;
//    }
//    bool exist(vector<vector<char>>& board, string word) {
//        int row = board.size();
//        if(!row) return false;
//        int col = board[0].size();
//        for(int i = 0; i < row; i++) {
//            for(int j = 0; j < col; j++) {
//                if(board[i][j] == word[0]) {
//                    if(dfs(board, i, j, word, 0)) return true;
//                }
//            }
//        }
//        return false;
//    }
//};

int main() {
    vector<vector<char>> board= {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    Solution s;
    cout<<s.exist(board,"ABCCA");
    return 0;
}