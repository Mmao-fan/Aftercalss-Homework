#include<bits/stdc++.h>

using namespace std;

int n, a[25], Aug;
bool summer, leap;

int main(){
	cin >> n;
//	cout << cin.rdbuf();
	cin >> a[1];
	for(int i = 2; i <= n; i++){
		cin >> a[i];
		if (a[i-1] <= 30){
			if (a[i-1] == 29){
				if (leap){
					cout << "No";
					return 0;
				}else {
					leap = 1;
				}
			}
			if (a[i] != 31){
				cout << "No";
				return 0;
			}
		}else {
			if (a[i] == 31){
				if (!summer){
					summer = 1;
					Aug = i;
				}else {
					if (i - Aug != 12 && i - Aug != 5){
						cout << "No";
						return 0;
					}
				}
			}
		}
	}
	cout << "Yes";
	return 0;
}

