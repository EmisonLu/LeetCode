#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    static int reverse(int x) {
        vector<long> a;
        long n=x;
        while(n!=0){
            a.push_back(n%10);
            n/=10;
        }
        long s=a.size(),sum=0;
        for(auto p=a.begin();p!=a.end();++p){
            sum+=(*p)*pow(10,--s);
        }
        if(sum>INT_MAX||sum<INT_MIN)return 0;
        return int(sum);
    }
};

int main() {
    int tmp;
    cin>>tmp;
    Solution s;
    cout<<s.reverse(tmp);
    return 0;
}
