#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isvowel(char c) {
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;
			break;
		default:
			return 0;
	}
}

string str;

int main() {
	getline(cin, str);
	//cout <<str;
	for (int i = 0; i < str.size(); i++) {
		if (!isvowel(str[i])) {
			if (str[i] != 'n') {
				if (!isvowel(str[i+1])) {
					cout << "NO";
					return 0;
				} 
			}
		}
	}
	cout << "YES";
	return 0;
}

