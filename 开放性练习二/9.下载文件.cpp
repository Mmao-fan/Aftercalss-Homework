#include<bits/stdc++.h>

using namespace std;

int T, n , k, t, d, co;

int main(){
	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> n >> k;//cout << n <<' '<< k<<' ';
		co = 0;
		for (int j = 1; j <= n; j++){
			cin >> t >> d;//cout << t << ' '<<d<<' ';
			if (k < t){
				co += (t - k) * d;
				k = 0;
			}else {
				k -= t;
			}
		}
		cout << co << endl;
	}
	return 0;
}

