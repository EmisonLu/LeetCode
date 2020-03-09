#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        const int temp=2*(numRows-1);
        int left=s.size()%temp;
        int main_part=(s.size()-left)/temp;
        string result;
        for(int j=1;j<=main_part;++j)
            result.append(1,s[0+(j-1)*temp]);
        if(left>=1)
            result=result+s[main_part*temp];
        for(int i=2;i<=numRows-1;++i){
            for(int j=0;j<main_part;++j){
                result.append(1,s[i-1+temp*j]);
                result.append(1,s[i-1+temp*j+temp-2*(i-1)]);
            }
            if(left>=i)
                result.append(1,s[i-1+main_part*temp]);
            if(left>=(i+temp-2*(i-1)))
                result.append(1,s[i-1+main_part*temp+temp-2*(i-1)]);
        }
        for(int j=1;j<=main_part;++j)
            result.append(1,s[numRows-1+(j-1)*temp]);
        if(left>=numRows)
            result=result+s[main_part*temp-1+numRows];
        return result;
    }
};

int main(){
    string s;
    int n;
    cin>>s>>n;
    Solution str;
    cout<<str.convert(s,n);
    return 0;
}
//LDREOEIIECIHNTSG