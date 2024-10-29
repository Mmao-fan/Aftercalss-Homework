#include<bits/stdc++.h>

using namespace std;

int t, dis;
double cost;

int main(){
	cin >> t >> dis;
	cost = t * dis;
	if (dis >= 3000){
		cost *= 0.85;
	} else {
		if (dis >= 2000){
			cost *= 0.9;
		} else {
			if (dis >= 1000){
				cost *= 0.92;
			} else {
				if (dis >= 500){
					cost *= 0.95;
				} else {
					if (dis >= 250){
						cost *= 0.98;
					}
				}
			}
		}
	}
	cout << cost;
	return 0;
}

