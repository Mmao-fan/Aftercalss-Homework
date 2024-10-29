#include<bits/stdc++.h>

using namespace std;

char N, S, n, s;
int ans;

int main(){
	cin >> N >> S;
	for(int i = 1; i <= 5; i++){
		cin >> n >> s;
		if (N == n || S == s) ans++;
	}
	if (ans) cout << "YES";
		else cout << "NO";
	return 0;
}

