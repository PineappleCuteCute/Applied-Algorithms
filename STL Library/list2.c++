#include <bits/stdc++.h> 
using namespace std;
int main() {
list<int> L;
for(int v = 1; v <= 5; v++) L.push_back(v); list<int>::iterator p;
p = L.begin(); advance(p,2);
cout << "item at position p is " << *p << endl; L.erase(p);//remove the item at position p
for(p = L.begin(); p!= L.end(); p++) cout << *p << " ";
}