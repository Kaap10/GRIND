#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int X, Y, Z;
    cin >> X >> Y >> Z;
    int ans;
    int mul = Y*Z;
    if(mul < X) {
        ans = X - mul;
    } else if( mul == X) {
        ans = 0;
    }
     else {
        ans = -1;
    }
    cout << ans;

}