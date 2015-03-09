// CodePSU Spring 2014 Problem #6 Trust Your Calculator
// Written by Xiangren Chen 03/07/2015

#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;

int findL(int X){
	int length = 1;
	while (X / 10 > 0){
		length++;
		X /= 10;
	}
	return length;
}

int main(){
	string line;
	int A=0, B=0;
	int sum = 0, N = 0;
	int firstLine, secondLine,width;
	vector<int> a;
	vector<int> b;
	vector<int> r;
	getline(cin, line);
	while (line != "#"){
		int i = 0; 
		A = B = sum = N = firstLine = secondLine = width = 0;
		a.clear();
		b.clear();
		r.clear();
		while (line[i] != ' '){
			a.push_back(line[i]-'0');
			i++;
		}
		while (line[i] == ' '){
			i++;
		}
		while (i < line.size()){
			b.push_back(line[i]-'0');
			i++;
		}
		for (int i = 0; i < a.size(); i++){
			A = a[i]*pow(10, a.size() - i - 1) + A;
		}
		for (int i = 0; i < b.size(); i++){
			B = b[i] * pow(10, b.size() - i - 1) + B;
		}
		if (b.size() == 1){
			sum=b[0] * A;
			firstLine = a.size();
			width = findL(sum);
			if (width < firstLine) width = firstLine;
			cout << setw(width) << A << endl << setw(width) << B << endl;
			cout << setw(width-firstLine+1);
			for (int i = 0; i < firstLine; i++){
				cout << "-";
			}
			cout << endl;
			cout << setw(width)<<sum << endl << endl;
		}
		else {
			if (a.size() >= b.size()) firstLine = a.size();
			else firstLine = b.size();
			for (int i = b.size() - 1; i >= 0; i--){
				N = b[i] * A * pow(10, b.size() - i - 1);
				r.push_back(N);
				sum = sum + N;
			}
			secondLine = findL(r[r.size() - 1]);
			width = findL(sum);
			if (width < firstLine) width = firstLine;
			else if (width < secondLine) width = secondLine;
			cout << setw(width) <<A<<endl<<setw(width)<<B<<endl;
			cout << setw(width-firstLine+1);
			for (int i = 0; i < firstLine; i++){
				cout << "-";
			}
			cout << endl;
			for (int i = 0; i < r.size(); i++){
				cout << setw(width) << r[i] << endl;
			}
			cout << setw(width-secondLine+1);
			for (int i = 0; i < secondLine; i++){
				cout << "-";
			}
			cout << endl;
			cout << setw(width)<<sum << endl << endl;
		}
		getline(cin, line);
	}
}
