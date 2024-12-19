#include <bits/stdc++.h>
#include <iostream>

using namespace std;

set<char> a;
int n;

int main() {
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++) {
		string str;
		getline(cin, str);
		for (char c : str) {
			if(c >= 'a' && c <= 'z') {
				a.insert(toupper(c));
			} else {
				if(c >= 'A' && c <= 'Z')
					a.insert(c);
			}
		}
		if (a.size() ==26) {
			cout << "Yes\n";
		} else {
//			cout << a.size()<<endl;
			cout << "No ";
			int j = 0;
			while(j++ <26) {
				set<char>::iterator it;
				for (it = a.begin(); it != a.end(); it++) {
					if(*it == 'A'+j-1) {
						break;
					}
				}
				if (it == a.end())
					cout << (char)('A'+j-1) << ' ';
			}
//				cout << it;
			cout << endl;
		}
		a.clear();
	}
	return 0;
}

