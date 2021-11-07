#include <iostream>
using namespace std;


//test if a given position x, y is safe in terms of other queens
bool isSafe(int **arr, int x, int y, int n){
	//test if the given column x is free of queens
	for(int row = 0; row < x; row++){
		if(arr[row][y] == 1){
			return false;
		}
	}
	int row = x; //actual row
	int col = y; //? uninitialized?
	//test for the left upper diagonal
	while(row >= 0 && col >= 0){
		if(arr[row][col] == 1)
			return false;
		row--;
		col--;
	}
	row = x;
	col = y;
	//test for the right upper diagonal
	while(row >= 0 && col < n){
		if(arr[row][col] == 1)
			return false;
		row--;
		col++;
	}
	return true;
}

bool nQueen(int **arr, int x, int n){
	if (x >= n)
		//if wee want to know all the posibilities what wee need to do 
		//is not returning nothing, and appending the actual solution to alist of solutions
		//and deleting the "if(nQueen(arr, x+1, n))" and put only nQueen(arr, x+1, n)
		//and thats all for collecting all the posibilities
		return true;
	for(int col = 0; col < n; col++){
		if(isSafe(arr, x, col, n)){
			arr[x][col] = 1; //try with these
			if(nQueen(arr, x+1, n)) //backtrack
				return true;
			arr[x][col] = 0; //if youre here something needs to revert...
		}
	}	
	return false;
}

int main(){
	int n;
	cin >> n;
	int** arr = new int*[n];
	for(int i=0; i < n; i++){
		arr[i] = new int[n];
		for(int j = 0; j < n; j++)
			arr[i][j] = 0; //initialize the matrix
	}
	//if there is any solution printit
	if(nQueen(arr, 0, n)){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if (arr[i][j] == 1){
					cout << "IXI" << " ";
				}
				else{
					cout << "***" << " ";
				}
			}
			cout << endl << endl;
		}
	}
}
