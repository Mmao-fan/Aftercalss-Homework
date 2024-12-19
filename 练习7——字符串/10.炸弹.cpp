#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main() {
	int T;
//	char c;
//	cout << cin.rdbuf();
	cin >> T;
	cin.ignore();
	for (int i = 1; i <= T; i++) {
		int n, m, total=0, b=0, jump=0, havewall=0;
		char w[100][100]={};
		set<int> h, l;
		cin >> n >> m;
//		char **w = new char*[n+1];
		for (int j = 1; j <= n; j++) {
			int _h=0;
//			w[j] = new char[m+1];
			for (int k = 1; k <= m; k++) {
				cin >> w[j][k];
				if (w[j][k] == '*') {
					havewall = 1;
					h.insert(j);
					l.insert(k);
					total++;
					_h++;
				}
			}
			if(_h>1) {
				b++;
				jump = j;
			}
		}
		if(!havewall) {
			cout<<"YES\n";
			continue;
		}
		if(b > 1) {
			cout << "NO\n";
		} else {
			if(b == 1) {
				if(h.size() == 1) {
					cout << "YES\n";
				} else {
					l.clear();
					for (int j = 1; j <= n; j++) {
						if(j == jump) {
							j++;
						}
						for (int k = 1; k <= m; k++) {
							if (w[j][k] == '*') {
								l.insert(k);
							}
						}
					}
					if(l.size() == 1) {
						cout << "YES\n";
					} else {
						cout << "NO\n";
					}
				}
			} else {
				if(l.size() == 1 || l.size() == 2) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			}
		}
//		delete[] w;
	}
	return 0;
}
/*
int main() {
	int T;
	char c;
	cin >> T;
	cin.ignore();
	for (int i = 1; i <= T; i++) {
		int n, m, b=0;
		set<int> h, l;
		cin >> n >> m;
		for (int j = 1; j <= n; j++) {
			int num = 0;
			for (int k = 1; k <= m; k++) {
				cin >> c;
				if (c == '*') {
					h.insert(j);
					l.insert(k);
					num++;
				}
			}
			if(num > 1) {
				b++;
			}
		}
		if(b > 1) {
			cout << "NO\n";
		} else {
			if(b == 1) {
				if(h.size() == 1 || l.size() == 1) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}
*/
