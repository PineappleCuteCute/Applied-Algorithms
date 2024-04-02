#include <iostream>
#include <limits.h>
 
using namespace std;
 
int a[23][23], b[23], s = 0, m = INT_MAX, d = 0, n, k, amin = INT_MAX;
bool c[23];
 
void f(int x) {
	int i = 0, j;
	if (d < k){
		for (i = 1; i < n+1; i++) {
			if (c[i]) {
				s += a[b[x - 1]][i];
				if (s + amin * (2*n+1 - x) < m) {
					b[x] = i;
					c[i] = false;
					d++;
//					cout << x << " " << i << " " << d << endl;
					f(x + 1);
					c[i] = true;
					d--;
				} 
				s -= a[b[x - 1]][i];
			}
		}
	} 
		
	for (i = n+1; i < 2*n+1; i++) {
		if (c[i] && !c[i - n]) {
			s += a[b[x - 1]][i];
			if (s + amin * (2*n+1 - x) < m){
				b[x] = i;
				c[i] = false;
				d--;
//					cout << x << "  " << i << "  " << d << endl;
				if (x < 2*n) f(x + 1);
				else if (s + a[b[x]][0] < m) 
					m = s + a[b[x]][0];
				d++;
				c[i] = true;
			}
			s -= a[b[x - 1]][i];
		}
	}	
	
}
 
int main() {
	int i, j;
	
	cin >> n >> k;
 
	for (i = 0; i < 2*n+1; i++) {
		c[i] = true;
		for (j = 0; j < 2*n+1; j++) {
			cin >> a[i][j];
			if (amin > a[i][j] && i != j) amin = a[i][j];			
		}

	}
	
	c[0] = false;
	b[0] = 0;
	f(1);
	
	cout << m;
}