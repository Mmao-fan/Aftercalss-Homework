#include<bits/stdc++.h>

using namespace std;

long long sal, dis, re[4];
char h;

int main(){
	for(int i=1;i<=3;i++){
		cin >> sal >> h >> dis;
		re[i] = (sal / 5000)  * 100;
		if (h == 'y') re[i] += 20;
		if (dis <= 2000) {
			re[i] += 100;
			cout<< '&' << endl;
		} else if (dis <= 3800){
					re[i] += 100 - ceil((dis - 2000) / 200.0) * 10;
					cout<<'&'<<endl;
				}				
	}
	if (re[1] >= re[2] && re[1] >= re[3]){
		cout << 'A';
	}else{
		if (re[2] >= re[3])
			cout << 'B';
		else 
			cout << 'C';
	}
	return 0;
}

