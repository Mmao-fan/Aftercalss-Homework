#include<bits/stdc++.h>

using namespace std;

long int x, y, cnt;
string a, b; 

int main(){
	cin >> x >> y;
	a = bitset<31>(x).to_string();
	b = bitset<31>(y).to_string();
	char *p = &a[0], *q = &b[0];
	do{
		if (*(p++) != *(q++)) cnt++;	
	}while(p != (&a[31]));//p++的副作用，向后移动一位 
	cout << cnt;
	return 0;
}

