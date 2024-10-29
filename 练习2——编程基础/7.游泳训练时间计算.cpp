#include<bits/stdc++.h>
using namespace std;

int a[2], be[3], en[3], hh, mm, ss;
int i = 0, j = 0;
char c;

int main(){
	
	while (1) 
	{					
		cin>>c;	
			if (c == ':')
			{
				j++;
				if (i == 1)
				{
					be[j] = a[1];
				} else {
					be[j] = 10*a[1] + a[2];
				}
				i = 0;
			} else {
				a[++i] = c-'0';
			}
		if (j == 2 && i == 2)
		{
			be[3] = 10*a[1] + a[2];
			break;
		}
	}
	i = j = 0;
	while (1) 
	{					
		cin>>c;	
			if (c == ':')
			{
				j++;
				if (i == 1)
				{
					en[j] = a[1];
				} else {
					en[j] = 10*a[1] + a[2];
				}
				i = 0;
			} else {
				a[++i] = c-'0';
			}
		if (j == 2 && i == 2)
		{
			en[3] = 10*a[1] + a[2];
			break;
		}
	}
	hh = en[1] - be[1];
	mm = en[2] - be[2];
	ss = en[3] - be[3];
	if (ss < 0){
		ss += 60;
		mm--;
	}
	if (mm < 0){
		mm += 60;
		hh--;
	}
	printf("%d:%02d:%02d", hh, mm, ss);
	return 0;
}
