#include<bits/stdc++.h>

using namespace std;

int n, l, r, a[600001], Start, End;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> l >> r;
		Start = min(Start, l);
		End = max(End, r);
		for (int j = l; j <= r; j++){
			a[j]++;
		}
	} 
	vector <int> cnt(n+1);
	for (int i = Start; i <= End; i++){
		cnt[a[i]]++;
	}
	for (int i = 1; i <= n; i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}

