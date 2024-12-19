#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string s;
int i = 0;

int main() {
	getline(cin, s);
	while(i < s.size()) {
		if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
			if(i) cout << ' ';
			i += 3;
			while(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
				i += 3;
			}
		} else {
			cout << s[i];
			i++;
		}
	}

	return 0;
}

