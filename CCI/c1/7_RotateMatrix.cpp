#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 1000

/* 
	Time: O(n²)
	Space: O(1) - In place
*/
void rotateMatrix( int mtx[][MAX], int n ) {
	for (int layer = 0; layer < n/2; ++layer) {
		for (int j = layer ; j < n -1 - layer; ++j) {
			
			int aux = mtx[layer][j];

			mtx[layer][j] = mtx[n -1 - j][layer]; // top <- left
			mtx[n -1 - j][layer] = mtx[n-1-layer][n -1 - j]; // left <- bottom
			mtx[n-1-layer][n -1 - j] = mtx[j][n-1-layer]; // bottom <- right
			mtx[j][n -1 -layer] = aux; // right <- top
		}
	}
}

void readMatrix(int &n, int mtx[][MAX]) {
	cin >> n;

	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j)
			cin >> mtx[i][j];	
}

int main() {
	int n, mtx[MAX][MAX];

	while(1) {
		readMatrix(n, mtx);

		// In place!
		rotateMatrix(mtx,n);

		for (int i = 0; i < n; ++i) { 
			for (int j = 0; j < n; ++j)
				cout << mtx[i][j];
			cout << endl;
		}

	}
	return 0;
}