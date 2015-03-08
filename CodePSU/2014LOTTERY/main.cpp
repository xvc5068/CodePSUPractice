// CodePSU Spring 2014 Problem #1 Lottery
// Written by Xiangren Chen 03/07/2015

#include <iostream>
#include <vector>

using namespace std;
#define MAX 20


int main(){
	int deck[MAX];
	int x, N,index=0;
	int current = 0;
	vector<int> employ;
	while (1){
		index = 0;
		current = 0;
		cin >> x >> N;
		for (int i = 0; i < MAX; i++){
			cin >> deck[i];
		}
		for (int i = 1; i <= x; i++){
			employ.push_back(i);
		}
		for (int i = 0; i < x - N && index <= 19; i++){
			int del = deck[index] - 1 + current;
			if (del < employ.size()){
				employ.erase(employ.begin() + del);
				current = del;
			}
			else{
				current = 0;
				index++;
				i--;
			}
		}

		for (int i = 0; i < employ.size(); i++){
			cout << employ[i] << " ";
		}
		cout << endl;
		employ.clear();
	}
	return 0;
}