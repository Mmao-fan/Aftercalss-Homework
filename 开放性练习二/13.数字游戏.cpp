#include<bits/stdc++.h>

using namespace std;

string st;
long long num;

int main(){
	cin >> st;
	cout << st + ' ';
	//cout << cin.rdbuf();
	while(st.size() != 1){
		num = 1;
		for (char c:st){
			if (c > '0' && c <= '9') num *= c - '0';
		}
		cout << num << ' ';
		st = to_string(num);
	}
	return 0;
}

