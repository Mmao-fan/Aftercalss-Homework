#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int T;

int main() {
	cin >> T;
	getchar();
	for (int i = 1; i <= T; i++) {
		string s;
		getline(cin, s);
		int l = s.size(), k = 0;
		vector<int> a(l), b(l);
		for (int j = 0; j < l; j++) {
			if (isdigit(s[j])) {
				a[k] = j;
				b[k++] = s[j]-'0';
			}
		}
		bool ans = 1;
		for (int j = 1; j < k; j++) {
			if(a[j] - a[j-1] <= b[j] + b[j-1]) {
				ans = 0;
				break;
			}
		}
		if (ans) {
			cout << "safe\n";
		} else {
			cout << "unsafe\n";
		}
	}
	return 0;
}

