#include <bits/stdc++.h>
#include <iostream>

using namespace std;



int main() {
	int n, T;
	string s;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int a[3]={0};
		cin >> n >> s;
		for (int j = 1; j < n; j++) {
			if (s[j] == 'S' && s[j-1] == 'T') {
				a[2]++;
			} else {
				if (s[j] == 'T' && s[j-1] == 'S') {
					a[1]++;
				}
			}
		}
		if(a[1] > a[2]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}

