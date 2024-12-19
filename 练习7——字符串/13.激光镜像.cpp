#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool w[1001][1001], mark[1001][1001];
int x0, y_0;
string d ;

void ray(int , int , int );
void prepare(int , int);
int direction(string);

int main() {
//	cout << cin.rdbuf();
	int n, m, k, x, y;
	long long cnt=0;
	cin >> n >> m >> k;
//	cout << n <<' '<< m <<' '<< k<<endl;
	prepare(n, m);
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
//		cout << x << ' ' << y << '*';
		w[x][y] = 1;
	}
	cin >> x0 >> y_0 >> d ;
//	cout <<x0 <<' '<<y_0<<' '<<d;
	ray(direction(d ), x0, y_0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m ; j++) {
			if(mark[i][j]) {
				cnt++;
//				cout<<i <<' '<<j<<endl;
			}
		}
	}
	cout << cnt;
	return 0;
}

void ray(int drct, int x, int y) { //dirction:1-SE;2-SW;3-NW;4-NE
//	cout<<x<<' '<<y<<' '<<drct<<endl;
	if(x == x0 && y == y_0 && drct == direction(d ) && mark[x0][y_0]) return;
	switch(drct) {
		case 1:
			if(w[x+1][y+1]) {
				if(w[x][y+1] ^ w[x+1][y] == 0) {
					ray(3, x, y);
				} else {
					if(w[x][y+1]) {
						mark[x+1][y] = 1;
						ray(2, x+1, y);
					} else {
						mark[x][y+1] = 1;
						ray(4, x, y+1);
					}
				}
			} else {
				mark[x+1][y+1] = 1;
				ray(1, x+1, y+1);
			}
			break;
		case 2:
			if(w[x+1][y-1]) {
				if(w[x][y-1] ^ w[x+1][y] == 0) {
					ray(4, x, y);
				} else {
					if(w[x][y-1]) {
						mark[x+1][y] = 1;
						ray(1, x+1, y);
					} else {
						mark[x][y-1] = 1;
						ray(3, x, y-1);
					}
				}
			} else {
				mark[x+1][y-1] = 1;
				ray(2, x+1, y-1);
			}
			break;
		case 3:
			if(w[x-1][y-1]) {
				if(w[x][y-1] ^ w[x-1][y] == 0) {
					ray(1, x, y);
				} else {
					if(w[x][y-1]) {
						mark[x-1][y] = 1;
						ray(4, x-1, y);
					} else {
						mark[x][y-1] = 1;
						ray(2, x, y-1);
					}
				}
			} else {
				mark[x-1][y-1] = 1;
				ray(3, x-1, y-1);
			}
			break;
		default:
			if(w[x-1][y+1]) {
				if(w[x][y+1] ^ w[x-1][y] == 0) {
					ray(2, x, y);
				} else {
					if(w[x][y+1]) {
						mark[x-1][y] = 1;
						ray(3, x-1, y);
					} else {
						mark[x][y+1] = 1;
						ray(1, x, y+1);
					}
				}
			} else {
				mark[x-1][y+1] = 1;
				ray(4, x-1, y+1);
			}
	}
}

void prepare(int n, int m) {
	for (int i = 0; i <= m+1; i++) {
		w[0][i] = w[n+1][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		w[i][0] = w[i][m+1] = 1;
	}
}

int direction(string s) {
	if(s[0] == 'S') {
		if(s[1] == 'E') {
			return 1;
		} else {
			return 2;
		}
	}
	if(s[0] == 'N') {
		if(s[1] == 'W') {
			return 3;
		} else {
			return 4;
		}
	}
	return 0;
}
/*
10 10 59
8 7
10 9
9 7
9 10
3 10
10 3
2 6
6 2
2 4
7 8
10 7
5 6
1 2
5 3
6 4
1 5
6 8
1 8
8 6
6 6
9 6
5 7
4 10
7 5
9 5
8 5
4 1
2 1
1 6
1 7
6 5
8 9
3 3
1 9
7 6
3 6
8 8
5 8
5 10
10 4
6 9
3 2
1 4
3 1
9 2
10 10
9 1
5 5
7 4
3 5
4 5
1 10
2 2
3 7
4 2
10 5
7 1
5 9
4 6
8 2 SW
*/
