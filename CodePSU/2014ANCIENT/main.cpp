// CodePSU Spring 2014 Problem #7 Ancient Language
// Written by Xiangren Chen 03/08/2015

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct order{
	order(char a, char b){
		A = a;
		B = b;
	}
	char A;
	char B;
};

void fillList(vector<order> &list,vector<string> word, int i){
	for (int j = 0; j < word[i - 1].size(); j++){
		string currentWord = word[i];
		string lastWord = word[i - 1];
		if (currentWord[j] != lastWord[j]){
			list.push_back(order(lastWord[j], currentWord[j]));
			break;
		}
	}
}

void cleanUp(vector<char> r, vector<order> &list){
	for (int i = 0; i < r.size()-1; i++){
		for (int j = i+1; j < r.size(); j++){
			for (int k = 0; k < list.size(); k++){
				if (list[k].A == r[i] && list[k].B == r[j]){
					list.erase(list.begin() + k);
					break;
				}
			}
		}
	}
}

void combineList(vector<char> &r, vector<order> list){
	int index;
	r.push_back(list[0].A);
	r.push_back(list[0].B);
	list.erase(list.begin());
	char temp;
	bool change = true;
	while (change == true){
		change = false;
		for (int j = 0; j < r.size(); j++){
			for (int i = 0; i < list.size(); i++){
				if (list[i].A == r[j]){
					temp = list[i].B;
					index = j + 1;
					if (index == r.size()){
						r.push_back(temp);
						change = true;
					}
					while (index < r.size()){
						for (int k = 0; k < list.size(); k++){
							if (list[k].A == temp && list[k].B==r[index]) {
								r.insert(r.begin() + index,temp);
								list.erase(list.begin() + k);
								if (k < i) i--;
								change = true;
								break;
							}
							else if (list[k].B == temp && list[k].A == r[index]){
								if (k == list.size() - 1){
									r.insert(r.begin() + index+1, temp);
									change = true;
								}
								list.erase(list.begin() + k);
								if (k < i) i--;
								index++;
								break;
							}
						}
						if (change == true) break;
					}
					if (change == true){
						list.erase(list.begin() + i);
						break;
					}
				}
				else if (list[i].B == r[j]){
					temp = list[i].A;
					index = j - 1;
					if (index == -1){
						r.insert(r.begin(),temp);
						change = true;
					}
					while (index >= 0){
						for (int k = 0; k < list.size(); k++){
							if (list[k].B == temp && list[k].A == r[index]) {
								r.insert(r.begin() + index, temp);
								list.erase(list.begin() + k);
								if (k < i) i--;
								change = true;
								break;
							}
							else if (list[k].A == temp && list[k].B == r[index]){
								if (k == 0){
									r.insert(r.begin(), temp);
									change = true;
								}
								list.erase(list.begin() + k);
								if (k < i) i--;
								index--;
								break;
							}
						}
						if (change == true) break;
					}
					if (change == true){
						list.erase(list.begin() + i);
						break;
					}
				}
			}
			if (change == true) break;
		}
		cleanUp(r, list);
	}
}

void cleanupList(vector<order> &list){
	for (int i = 0; i < list.size()-1; i++){
		if (list[i].A == list[i + 1].A&&list[i].B == list[i + 1].B){
			list.erase(list.begin() + i);
			i--;
		}
	}
}

int main(){
	string line;
	vector<order> list;
	vector<string> word;
	vector<char> r;
	while (1){
		list.clear();
		r.clear();
		word.clear();
		getline(cin, line);
		while (line != "%"){
			word.push_back(line);
			getline(cin, line);
		}
		for (int i = 1; i < word.size(); i++){
			fillList(list, word, i);
		}
		cleanupList(list);
		combineList(r, list);
		for (int i = 0; i < r.size(); i++){
			cout << r[i];
		}
		cout << endl;
	}
	return 0;
}