//Input
//6 2 3
//3 5 9 6 7 4
//
//Output
//19
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n, l1, l2;
int a[MAX];

void input(){
  cin >> n >> l1 >> l2;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
}

void GoldMining(){
  int f[n];
  deque <pair<int, int> > b;
  int res = 0;
  for(int i=0;i<n;i++){
    f[i] = a[i];
    while(!b.empty() && b.front().second < i - l2){
      b.pop_front();
    }

    if(i - l1 >= 0){
      while(!b.empty() && b.back().first < f[i - l1]){
        b.pop_back();
      }
      b.push_back(make_pair(f[i - l1], i - l1));
    }
    if(!b.empty()) f[i] += b.front().first;
    res = max(res, f[i]);
  }
  cout <<res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    GoldMining();
}
