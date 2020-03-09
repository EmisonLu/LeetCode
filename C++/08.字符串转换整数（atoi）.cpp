#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long sum=0;
        bool ab=true;
        int i=0,size=str.size();
        while(str[i]==' '&&i<size)i++;
        if(i==size)return 0;
        if((str[i]!='+'&&str[i]!='-'&&int(str[i])<48&&int(str[i])>57))return 0;
        if(str[i]=='-'){if(str[i+1]=='+')return 0;++i;ab=false;}
        if(str[i]=='+')++i;
        while(int(str[i])==48)++i;
        int counts=0;
        while(counts<11&&int(str[i])>=48&&int(str[i])<=57&&i<size){
            sum=sum*10+int(str[i])-48;
            i++;
            counts++;
        }
        if(ab){
            if(sum>INT_MAX)return INT_MAX;
            else return int(sum);
        }
        if (-sum < INT_MIN)return INT_MIN;
        else return int(-sum);
    }
};
//class Solution {
//public:
//    int myAtoi(string str) {
//        int res = 0;
//        int i = 0;
//        int flag = 1;
//        // 1. 检查空格
//        while (str[i] == ' ') { i++; }
//        // 2. 检查符号
//        if (str[i] == '-') { flag = -1; }
//        if (str[i] == '+' || str[i] == '-') { i++; }
//        // 3. 计算数字
//        while (i < str.size() && isdigit(str[i])) {
//            int r = str[i] - '0';
//            // ------ 4. 处理溢出，这是关键步骤 ------
//            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) {
//                return flag > 0 ? INT_MAX : INT_MIN;
//            }
//            // ------------------------------------
//            res = res * 10 + r;
//            i++;
//        }
//        return flag > 0 ? res : -res;
//    }
//};

int main() {
    string str;
    cin>>str;
    Solution s;
    cout<<s.myAtoi(str);
    return 0;
}
