#include<bits/stdc++.h>

using namespace std;

int n, m;
long long a[101];

int main(){
	cin >> m >> n;
	for (int j = 1; j <= m; j++){	
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a+1,a+n+1);
		cout << a[1] << endl;
	}
	return 0;
}
