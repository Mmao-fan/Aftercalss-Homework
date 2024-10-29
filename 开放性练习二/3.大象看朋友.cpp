#include<bits/stdc++.h>

using namespace std;

long long ans, x, m;

int main(){
	cin >> x >> m;
	x = abs(x);
	m = 2 * m - 1;
	ans += x / m;
	x %= m;
	if (x % 2 == 0){
		if (x == 0)cout << ans;
		else cout << ans + 2; 
	}
	else {
		cout << ++ans;
	}
	return 0;
}

