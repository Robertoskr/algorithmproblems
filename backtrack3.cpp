#include <iostream>
using namespace std;


class nQueens{
	public:
	int n; //this is the length of the table
	bool **table; // the table
	int y; //the current row
	int solutions = 0;
	bool debug = false;
	nQueens(int N, bool Debug = false){
		n = N;
		y = 0;
		debug = Debug;
		table = new bool*[n];
		for(int i = 0; i < n; i++){
			table[i] = new bool[n];
		}
		backtrack();
	}

	void printtable(){
		for(int row = 0; row < n; row++){
			cout << "{" ;
			for(int col = 0; col < n; col++){
				cout << table[row][col] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	bool isvalid(int col){
		for(int row = 0; row < y; row++){
			//is the column used by a queen?
			if(table[row][col])
				return false;
			//lets check the diagonals
			int leftdiagonal = col - (y - row);
			int rightdiagonal = col + (y - row);
			if(table[row][leftdiagonal] || table[row][rightdiagonal])
				return false;
		}
		return true;
	}

	bool issol(){
		//return if the table is a solution to the problem
		return y == n;
	}

	void backtrack(){
		if(issol()){
			solutions++;
			if(debug == true)
				printtable();
			return;
		}
		for(int col = 0; col < n; col++){
			if(isvalid(col)){
				//if this position is valid continue here
				table[y][col] = true;
				y++;
				backtrack();
				y--;
				table[y][col] = false;
			}
		}
	}

};


int main(){
	int n;
	cin >> n;
	nQueens solution(n, true);
	cout << solution.solutions << endl;
}
