// CodePSU Spring 2014 Problem #1 Lottery
// Written by Xiangren Chen 03/07/2015
#include<iostream>
using namespace std;

bool Try(int count, int need, int c, int u, int d, int t){
	int start = 1;
	int current = 1;
	bool change;
	while (current != t && (count >0 || need>0)){
		change = false;
		while (current - d >= 1 && count > 0){
			current -= d;
			count--;
			change = true;
		}
		if (current + u < c && need>0){
			current += u;
			need--;
			change = true;
		}
		if (count == 0 && current + u < c && need>0){
			current += u*need;
			need = 0;
		}
		if (change == false) return false;
	}
	if (current == t) return true;
	else return false;
}

int foo(int c, int t, int u, int d){
	int current = 1;
	int count = 0;
	while ((t-1 + count*d) % u != 0 && count < u){
		count++;
	}
	if (count == t) return -1;
	int need = /*count*d / u + 1*/ + (t-1 + count*d) / u;
	if (Try(count, need, c, u, d, t)==true) return count+need;
	else return -1;
}

int main(){
	int c, d, u, t;
	int num;
	cin >> num;
	for (int i = 0; i<num; i++){
		cin >> c >> d >> u >> t;
		if ((t - 1) % u == 0) cout << (t - 1) % u << endl;
		else if (u == d) cout << "Try Nexflix!"<<endl;
		else if ((u > d && u%d == 0 && (t - 1) % d != 0) || (u < d && d%u == 0 && (t - 1) % u != 0)) cout << "Try Nexflix!"<<endl;
		else{
			int r = foo(c, t, u, d);
			if (r == -1) cout << "Try Nexflix!"<<endl;
			else cout << r << endl;
		}
	}
	return 0;
}