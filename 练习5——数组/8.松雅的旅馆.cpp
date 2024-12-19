#include<bits/stdc++.h>

using namespace std;

int n, d, cnt=2, a[10000];

int main(){
	cin >> n >> d;
//	vector <int> a(n); 
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 2; i <= n; i++){
		if (a[i] - a[i-1] == 2 * d){
			cnt++;
		}else {
			if (a[i] - a[i-1] > 2 * d){
				cnt += 2;
			}
		}
	}
	cout << cnt;
	return 0;
}

