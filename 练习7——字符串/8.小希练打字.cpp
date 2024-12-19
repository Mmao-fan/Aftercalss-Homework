#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct str {
	string s;
	int t;
};
struct cmp {
	bool operator ()(str a, str b) const {
		return a.s<b.s;
	}
};

bool side(char c);
double cal(string p) {
	double sum = 0.2;
	for (int i = 1; i < p.size(); i++) {
		if ((side(p[i-1]) ^ side(p[i])) == 0) {
			sum += 0.4;
		} else {
			sum += 0.2;
		}
	}
	return sum;
}

double ans;

int main() {
	int n;
	set<str,cmp> a;
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++) {
		string st;
		getline(cin, st);
		auto it = a.s.find(st);
		if (it != a.s.end()) {
			ans += *it.t/2;
		} else {
			double tim = cal(st);
			ans += tim;
		}
	}
	cout << ans;
	return 0;
}

bool side(char c) {
	switch(c) {
		case 'y':
		case 'u':
		case 'i':
		case 'o':
		case 'p':
		case 'h':
		case 'j':
		case 'k':
		case 'l':
		case 'n':
		case 'm':
			return 1;
		default:
			return 0;
	}
}
