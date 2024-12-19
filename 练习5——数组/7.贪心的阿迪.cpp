#include<bits/stdc++.h>

using namespace std;

int n, k, M, D, ans, can ;

int main(){
	cin >> n >> k >> M >> D;
	for (int i = M; i >= 1; i--){
		int num = ceil (n / i / (double)k);
		if (num <= D) {
			can = num * i;
		}else {
			can = 0;
		}
		ans = max(ans, can);
	}
	cout << ans;
	return 0;
}

