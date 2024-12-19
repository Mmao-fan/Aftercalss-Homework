#include<bits/stdc++.h>

using namespace std;

struct Teacher{
	int r, cnt=0;
};

int n, k;

int main(){
	cin >> n >> k;
	vector <Teacher> a(n+1);
	for (int i = 1; i <= n; i++){
		cin >> a[i].r;
	} 
	for (int i = 1; i <= k; i++){
		int p, q;
		cin >> p >> q;
		if (a[p].r > a[q].r){
			a[p].cnt--;
		}else {
			if (a[p].r < a[q].r){
				a[q].cnt--;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			if (a[i].r > a[j].r){
				a[i].cnt++;
			}else {
				if (a[i].r < a[j].r){
					a[j].cnt++;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++){
		cout << a[i].cnt << ' ';
	}
	return 0;
}

