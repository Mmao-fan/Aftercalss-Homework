#include<bits/stdc++.h>

using namespace std;

long double in, s;

int main(){
	cin  >> in >> s;
	in -= 5000 + s;
	if (in < 0) in = 0;
	if (in <= 3000){
		in *= 0.03;
	} else {
		if (in <= 12000){
			in = in * 0.1 - 210;
		} else {
			if (in <= 25000){
				in = in * 0.2 - 1410;
			} else {
				if (in <= 35000){
					in *= 0.25;
					in -= 2660;
				} else {
					if (in <= 55000){
						in *= 0.3;
						in -= 4410;
					} else {
						if (in <= 80000){
							in *= 0.35;
							in -= 7160;
						} else {
							in *= 0.45;
							in -= 15160;
						}
					}
				}
			}
		}
	}
	cout << in;
	return 0;
}

