// CodePSU Spring 2014 Problem #5 The Lorax
// Written by Xiangren Chen 03/07/2015

#include<iostream>
#include<math.h>
using namespace std;

struct myTri{
	myTri(){
		X = 0;
		Y = 0;
	}
	double X;
	double Y;
};

void swap(myTri &A, myTri &B){
	myTri Temp;
	Temp.X = A.X;
	Temp.Y = A.Y;
	A.X = B.X;
	A.Y = B.Y;
	B.X = Temp.X;
	B.Y = Temp.Y;
}

double endPointD(int i, myTri A, myTri B, myTri C){
	if (B.X > C.X){
		return ((i - C.Y) / (B.Y - C.Y) * (B.X - C.X) + C.X);
	}
	else{
		return (C.X - (i - C.Y) / (A.Y - C.Y) * (C.X - A.X));
	}
}

double startPointD(int i, myTri A, myTri B, myTri C){
	if (B.X < C.X){
		return ((i - C.Y) / (B.Y - C.Y) * (B.X - C.X) + C.X);
	}
	else{
		return (C.X - (i - C.Y) / (A.Y - C.Y) * (C.X - A.X));
	}
}

double endPointU(int i, myTri A, myTri B, myTri C){
	if (B.X > C.X){
		return (B.X-(i-B.Y)/(A.Y-B.Y)*(B.X-A.X));
	}
	else{
		return (C.X - (i - C.Y) / (A.Y - C.Y) * (C.X - A.X));
	}
}

double startPointU(int i, myTri A, myTri B, myTri C){
	if (B.X < C.X){
		return (B.X - (i - B.Y) / (A.Y - B.Y)*(B.X - A.X));
	}
	else{
		return (C.X - (i - C.Y) / (A.Y - C.Y) * (C.X - A.X));
	}
}

int main(){
	 
	myTri A, B, C;
	int sum = 0;
	cin >> A.X >> A.Y >> B.X >> B.Y >> C.X >> C.Y;
	while (A.X != 0 || A.Y != 0 || B.X != 0 || B.Y != 0 || C.X != 0 || C.Y != 0){
		sum = 0;
		if (A.Y < B.Y){
			swap(A, B);
		}
		if (A.Y < C.Y){
			swap(A, C);
		}
		if (B.Y < C.Y){
			swap(B, C);
		}
		for (int i = ceil(C.Y); i <= floor(B.Y); i++){
			int end = floor(endPointD(i, A, B, C));
			int start = ceil(startPointD(i, A, B, C));
			sum = sum + end - start + 1;
		}
		for (int i = ceil(B.Y); i <= floor(A.Y); i++){
			int end = floor(endPointU(i, A, B, C));
			int start = ceil(startPointU(i, A, B, C));
			sum = sum + end - start + 1;
		}
		cout << sum<<endl;
		cin >> A.X >> A.Y >> B.X >> B.Y >> C.X >> C.Y;
	}
	return 0;
}