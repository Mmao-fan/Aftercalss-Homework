#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string s1, s2;

int main() {
	getline(cin, s1);
	getline(cin, s2);
	int l1 = s1.size()-1, l2 = s2.size()-1;
	int i = l1, j = l2;
	while (i >= 0 && j >= 0) {
//		cout << i << ' ' << j << endl;
		if (s1[i] == s2[j]) {
			i--, j--;
		} else {
			break;
		}
	}
	cout << i+j+2;
	return 0;
}

