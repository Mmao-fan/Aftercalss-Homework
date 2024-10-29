#include<bits/stdc++.h>

using namespace std;

int n;
long long ans;
long a[19] = { 4, 10, 22, 46, 94, 190, 382, 766, 1534, 3070, 6142, 12286, 24574, 49150, 98302, 196606, 393214, 786430, 1572862};

int main(){
	cin >> n;
	cout << a[n-2];
	/*
	ans = 1;
	for (int i = 1; i < n; i++){
		ans = (ans<<1) + 2;
		cout << ans << ' ';
	}
	*/ 
	return 0;
}

