#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static string intToRoman(int num) {
        int a,b,c,d;
        string result;
        a=num%10;
        b=(num/10)%10;
        c=(num/100)%10;
        d=(num/1000)%10;
        switch (d){
            case 1: result+='M';
                break;
            case 2: result+="MM";
                break;
            case 3: result+="MMM";
                break;
        }
        switch (c){
            case 1: result+='C';
                break;
            case 2: result+="CC";
                break;
            case 3: result+="CCC";
                break;
            case 4: result+="CD";
                break;
            case 5: result+="D";
                break;
            case 6: result+="DC";
                break;
            case 7: result+="DCC";
                break;
            case 8: result+="DCCC";
                break;
            case 9: result+="CM";
        }
        switch (b){
            case 1: result+='X';
                break;
            case 2: result+="XX";
                break;
            case 3: result+="XXX";
                break;
            case 4: result+="XL";
                break;
            case 5: result+="L";
                break;
            case 6: result+="LX";
                break;
            case 7: result+="LXX";
                break;
            case 8: result+="LXXX";
                break;
            case 9: result+="XC";
        }
        switch (a){
            case 1: result+='I';
                break;
            case 2: result+="II";
                break;
            case 3: result+="III";
                break;
            case 4: result+="IV";
                break;
            case 5: result+="V";
                break;
            case 6: result+="VI";
                break;
            case 7: result+="VII";
                break;
            case 8: result+="VIII";
                break;
            case 9: result+="IX";
        }
        return result;
    }
};
//暴力法简洁版
//class Solution
//{
//public:
//    string intToRoman(int num)
//    {
//        string result;
//        vector<string> tmpVec1 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//        vector<string> tmpVec2 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//        vector<string> tmpVec3 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//        vector<string> tmpVec4 = {"", "M", "MM", "MMM"};
//        vector<vector<string>> store = {tmpVec1, tmpVec2, tmpVec3, tmpVec4};
//        result.append(store[3][num / 1000 % 10]);
//        result.append(store[2][num / 100 % 10]);
//        result.append(store[1][num / 10 % 10]);
//        result.append(store[0][num % 10]);
//        return result;
//    }
//}；

//贪心法
//class Solution
//{
//public:
//    string intToRoman(int num)
//    {
//        string result;
//        vector<int> store = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//        vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//        int storeSize = int(store.size());
//        //贪心法
//        for (int i = 0; i < storeSize; i++)
//        {
//            while (num >= store[i])
//            {
//                result.append(strs[i]);
//                num -= store[i];
//            }
//        }
//        return result;
//    }
//};

int main() {
    int n;
    cin>>n;
    cout<<Solution::intToRoman(n);
    return 0;
}