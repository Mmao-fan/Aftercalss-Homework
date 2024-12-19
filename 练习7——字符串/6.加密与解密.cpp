#include <bits/stdc++.h>
#include <iostream>

using namespace std;

string s;

void trans(int n){
	int i = 0;
	n--;
	while(i < n){
		swap(s[i], s[n]);
		i++, n--;
	}
}

int main() {
	getline(cin, s);
	int l = s.size();
	for (int i = 2; i <= l; i++){
		if (l % i == 0){
			trans(i);
		}
	} 
	cout << s;
	return 0;
}

