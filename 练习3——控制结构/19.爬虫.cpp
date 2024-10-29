#include<bits/stdc++.h>

using namespace std;

int n, u, d, t;

int main(){
	while (1) {
		cin >> n >> u >> d;
		if (n == 0) 
			break;
		else{
			t = ceil((n-u)/(double)(u-d))*2+1;
			cout << t << endl;
		} 
	}
	return 0;
}

