#include<bits/stdc++.h>

using namespace std;

int n, num, ans;
char c;

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> c;		
		switch (c){
			case 'r':
				cin >> num;
				ans += num;
				break;
			case 'y':
				ans += 2;
				break;
			case 'g':
				ans += 3;
				break;
			case 'c':
				ans += 4;
				break;	
			case 'b':
				ans += 5;
				break;
			case 'p':
				ans += 6;
				break;
			case 'B':
				ans += 7;
				break;
		}	
	}
	cout << ans;
	return 0;
}

