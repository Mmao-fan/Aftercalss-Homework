#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int T, l, r;
string str;

int main(){
	cin >> T;
	getchar();
	for (int i = 1; i <= T; i++){
		getline(cin, str);
		auto it = str.find('^');
		l = r = 0;
		for (int j = 0; j < it; j++){
			if (str[j] != '='){
				l += (str[j]-'0')*(it-j);
			}
		} 
		for (int j = it+1; j < str.size(); j++){
			if (str[j] != '='){
				r += (str[j]-'0')*(j-it);
			}
		} 
		if (l == r){
			cout << "balance\n";
		}else{
			if (l > r){
				cout << "left\n";
			}else{
				cout << "right\n";
			}
		}
	}
	return 0;
}

