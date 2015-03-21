#include<iostream>
#include<vector>
using namespace std;

struct Recipe{
	Recipe(int a, int b, int c){
		A = a;
		B = b;
		C = c;
		count = 0;
	}

	int A, B, C;
	int count;
};

bool Try(vector<Recipe> recipe, Recipe target){
	int sum=0;
	for (int i = 0; i < recipe.size(); i++){
		sum = sum + recipe[i].A*recipe[i].count;
	}
	if (sum != target.A) return false;
	sum = 0;
	for (int i = 0; i < recipe.size(); i++){
		sum = sum + recipe[i].B*recipe[i].count;
	}
	if (sum == target.B) return true;
	else return false;
}

bool foo(vector<Recipe> &recipe, Recipe target,int tar, int i){
	if (i<0){
		return false;
	}
	if (tar%recipe[i].C == 0){
		recipe[i].count = tar / recipe[i].C;
		if (Try(recipe, target) == true) return true;
	}
	for (int j = tar / recipe[i].C; j >= 0; j--){
		recipe[i].count = j;
		if (foo(recipe, target,tar-recipe[i].C*j, i - 1) == true) return true;
	}
	return false;
}

int main(){
	int N;
	int a, b, c;
	while (true){
		cin >> N;
		if (N == 0) break;
		vector<Recipe> recipe;
		cin >> a >> b >> c;
		recipe.push_back(Recipe(a, b, c));
		for (int i = 1; i < N; i++){
			cin >> a >> b >> c;
			Recipe New(a, b, c);
			for (int j = 0; j < recipe.size(); j++){
				if (c<=recipe[j].C){
					recipe.insert(recipe.begin() + j, New);
					break;
				}
				if (j == recipe.size() - 1){
					recipe.push_back(New);
				}
			}
		}
		cin >> a >> b >> c;
		Recipe target(a, b, c);
		if (foo(recipe, target, target.C, recipe.size() - 1) == true){
			cout << "Recipe 1\nPossible\n\n";
		}
		else{
			cout << "Recipe 1\nImpossible\n\n";
		}
	}
	return 0;
}
