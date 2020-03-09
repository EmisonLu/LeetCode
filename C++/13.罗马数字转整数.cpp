#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//暴力法
//class Solution {
//public:
//    static int romanToInt(string s) {
//        for(int i=0;i<4000;++i){
//            if(intToRoman(i)==s)return i;
//        }
//        return 0;
//    }
//private:
//    static string intToRoman(int num) {
//        int a,b,c,d;
//        string result;
//        a=num%10;
//        b=(num/10)%10;
//        c=(num/100)%10;
//        d=(num/1000)%10;
//        switch (d){
//            case 1: result+='M';
//                break;
//            case 2: result+="MM";
//                break;
//            case 3: result+="MMM";
//                break;
//        }
//        switch (c){
//            case 1: result+='C';
//                break;
//            case 2: result+="CC";
//                break;
//            case 3: result+="CCC";
//                break;
//            case 4: result+="CD";
//                break;
//            case 5: result+="D";
//                break;
//            case 6: result+="DC";
//                break;
//            case 7: result+="DCC";
//                break;
//            case 8: result+="DCCC";
//                break;
//            case 9: result+="CM";
//        }
//        switch (b){
//            case 1: result+='X';
//                break;
//            case 2: result+="XX";
//                break;
//            case 3: result+="XXX";
//                break;
//            case 4: result+="XL";
//                break;
//            case 5: result+="L";
//                break;
//            case 6: result+="LX";
//                break;
//            case 7: result+="LXX";
//                break;
//            case 8: result+="LXXX";
//                break;
//            case 9: result+="XC";
//        }
//        switch (a){
//            case 1: result+='I';
//                break;
//            case 2: result+="II";
//                break;
//            case 3: result+="III";
//                break;
//            case 4: result+="IV";
//                break;
//            case 5: result+="V";
//                break;
//            case 6: result+="VI";
//                break;
//            case 7: result+="VII";
//                break;
//            case 8: result+="VIII";
//                break;
//            case 9: result+="IX";
//        }
//        return result;
//    }
//};
//哈希法
class Solution {
public:
    static int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int pos = 0;
        for (int i = 0;i < s.size()-1;++i){
            if (mp[s[i]] < mp[s[i+1]])
                pos -= mp[s[i]];
            else
                pos += mp[s[i]];
        }
        pos += mp[s.back()];
        return pos;
    }
};
int main() {
    string str;
    cin>>str;
    cout<<Solution::romanToInt(str);
    return 0;
}