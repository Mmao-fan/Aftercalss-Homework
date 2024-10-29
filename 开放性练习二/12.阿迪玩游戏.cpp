#include<bits/stdc++.h>

using namespace std;

int n, m, sum;

int main(){
	int a;
	//cout << cin.rdbuf();
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		cin >> a;
		sum += a;
	}
	//cout << (int)ceil(sum/(float)(n-1))<< endl;
	if ((int)ceil(sum/(float)(n-1)) % 2 == 0){
		cout << n-sum%(n-1);
	}else{
		cout <<	sum%(n-1)+1;
	}
	return 0;
}

