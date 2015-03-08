// CodePSU Spring 2014 Problem #2 Study Buddies
// Written by Xiangren Chen 03/07/2015

#include<iostream>
using namespace std;


bool foo(int _num[], int dim, int tar){

	for (int i = _num[dim-1]; i > 0; i--){
		if (i * dim == tar) return true;
		else if (i * dim < tar){
			if (dim == 1) return false;
			if (foo(_num,dim-1, tar - i * dim) == true) return true;
		}
	}
	return foo(_num,dim-1, tar);
}

int main(){
	int count = 1;
	int _num[6];
	cin >> _num[0] >> _num[1] >> _num[2] >> _num[3] >> _num[4] >> _num[5];
	while (_num[0] != 0 || _num[1] != 0 || _num[2] != 0 || _num[3] != 0 || _num[4] != 0 || _num[5] != 0){
		cout << "Assignment #" << count<<endl;
		int sum = _num[0] + _num[1] * 2 + _num[2] * 3 + _num[3] * 4 + _num[4] * 5 + _num[5] * 6;
		if (sum % 2 != 0) cout << "NO";
		else{
			int tar = sum / 2;
			if (foo(_num,6, tar) == true) cout << "Yes";
			else cout << "no";
		}
		cout << "\n\n";
		cin >> _num[0] >> _num[1] >> _num[2] >> _num[3] >> _num[4] >> _num[5];
		count++;
	}
	return 0;
}