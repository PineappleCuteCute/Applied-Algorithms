#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1 = "hello";
    string s2 = s1 + " ManhDepTrai";
    cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
    string ss = s2.substr(2, 6);
    cout << "s2 = " << s2 << ", length = " << s2.length() << endl;
    cout << "s2.substring(2, 6) = " << ss << endl;
    s2.replace(6, 5, "abc");
    cout << "new s2 = " << s2 << endl;
    return 0;
}