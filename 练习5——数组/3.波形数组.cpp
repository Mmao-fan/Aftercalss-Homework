#include<bits/stdc++.h>

using namespace std;

int T, n;

int main(){
	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> n;
		vector <int> a(n+1);
		bool judge = true;
		for (int j = 1; j <= n; j++){
			cin >> a[j];
		}
		for (int j = 2; j < n; j++){
			if ((a[j] > a[j-1] && a[j] > a[j+1]) 
				|| (a[j] < a[j-1] && a[j] < a[j+1])){
				;
			}else {
				judge = false;
				break;
			}
		}
		if (judge){
			cout << "Yes\n";
		}else {
			cout << "No\n";
		}
	}
	return 0;
}

