#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool cmp(double x, double y){
        return x<y;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution sol = *new Solution;
    cout<<sol.cmp(2, 3);

    return 0;
}
