// CodePSU Spring 2014 Problem #4 Fun With Parking
// Written by Xiangren Chen 03/08/2015

#include<iostream>
#include<vector>
#include<string>
#define MAX 20
using namespace std;

struct myPair{
	myPair(int id){
		ID = id;
		lot = 0;
	}
	int ID;
	int lot;
};


int main(){
	int wait[MAX] = { 0 };
	int space[MAX] = { 0 };
	fill_n(space, MAX, 1);
	int move = 0,init=0;
	string line;
	vector<int> leave;
	vector<myPair> waitCar;
	int num,N;
	cin >> N;
	getline(cin, line);
	for (int x = 0; x < N; x++){
		move = 0;
		waitCar.clear();
		leave.clear();
		fill_n(wait, MAX, 0);
		fill_n(space, MAX, 1);
		cin >> num;
		while (num != 999){
			waitCar.push_back(myPair(num));
			wait[num - 1]++;
			cin >> num;
		}
		getline(cin, line);
		getline(cin, line);
		while (!line.empty()){
			leave.push_back(stoi(line));
			getline(cin, line);
		}
		for (int i = 0; i < leave.size(); i++){
			int index = leave[i] - 1;
			space[index] = 0;
			while (wait[index] == 0){
				int temp = wait[MAX - 1];
				for (int i = MAX - 1; i > 0; i--){
					wait[i] = wait[i - 1];
				}
				wait[0] = temp;
				move++;
			}
			wait[index]--;
			space[index] = 1;
			init = index + 1 - move;
			while (init <= 0) init += MAX;
			for (int j = 0; j < waitCar.size(); j++){
				if (waitCar[j].ID == init) waitCar[j].lot = index + 1;
			}
		}
		for (int i = 0; i < waitCar.size(); i++){
			cout << waitCar[i].ID << " " << waitCar[i].lot << endl;
		}
		cout << "\n";
	}
	return 0;
}