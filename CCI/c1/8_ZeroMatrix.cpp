#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
	Time: O(mn)
	Space: O(1) --  Use line 0 and column 0 as cache!

	AWESOME idea of use the structure itself as cache.
*/
void zeroMatrixBest(vector< vector<int> > &M, int m, int n) {
	bool rowHasZero = false, colHasZero = false;
	for (int i = 0; i < m; ++i)
		if(M[i][0] == 0) colHasZero = true;
	for (int i = 0; i < n; ++i)
		if(M[0][i] == 0) rowHasZero = true;

	// Cache
	for (int i = 1; i < m; ++i)
		for (int j = 1; j < n; ++j)
			if(!M[i][j]) 
				M[0][j] = M[i][0] = 0;
	// Fill with zeros!
	for (int i = 0; i < m; ++i)
			if(!M[i][0]) 
				for (int j = 0; j < n; ++j)
					M[i][j] = 0;
	for (int i = 0; i < n; ++i)
			if(!M[0][i]) 
				for (int j = 0; j < m; ++j)
					M[j][i] = 0;

	if(colHasZero) // Check if line 0 should be zero
		for (int i = 0; i < m; ++i)
				M[i][0] = 0;
	if(rowHasZero) // Check if column 0 should be zero
		for (int i = 0; i < n; ++i)
				M[0][i] = 0;
}

int main() {
	int x,y,aux;
	vector< vector<int> > M;
	while(1) {
		M.clear();
		cin >> x >> y;

		for (int i = 0; i < x; ++i) {
			vector<int> v;
			for (int j = 0; j < y; ++j) {
				cin >> aux;
				v.push_back(aux);
			}
			M.push_back(v);
		}
		zeroMatrixBest(M,x,y);

		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j)
				cout << M[i][j];

			cout << endl;
		}
	}
	return 0;
}