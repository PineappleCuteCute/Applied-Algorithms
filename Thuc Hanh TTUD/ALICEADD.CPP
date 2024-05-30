#include<bits/stdc++.h>
using namespace std;

/*Alice co a cai keo. Bob cho Alice b cai keo. Hoi Alice co bao nhieu cai keo
0 <= a, b <= 10^18*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int i = 0;i<T;i++){
        long long a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}


