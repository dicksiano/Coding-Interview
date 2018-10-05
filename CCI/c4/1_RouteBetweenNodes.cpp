#include <bits/stdc++.h>
using namespace std;

/* 
  Time: O(V+E)
  Space: O(V) - Worst case: recursion stack would have all vertex. 
                Best case: must have at least a array of visited vertex
*/
void dfs(vector< vector<int> > g, int x, vector<int> &visited) {
  visited[x] = true;
  for (int i = 0; i < g[x].size(); ++i) {
    if(visited[g[x][i]] == 0)
      dfs(g, g[x][i], visited);
  }
}

bool routeBetweenNode(int x, int y, vector< vector<int> > g) {
  vector<int> visited(g.size(), 0);
  dfs(g, x, visited);
  return visited[y];
}

int main() {
  int n, m,x,y,aux;
  cin >> n;
  vector<int> v;
  vector< vector<int> > g;

  for (int i = 0; i < n; ++i) {
    cin >> m;
    v.clear();
    for (int j = 0; j < m; ++j) {
      cin >> aux;
      v.push_back(aux);
    }
    g.push_back(v);
  }

  for (int i = 0; i < n; ++i) {
      cout << endl << i << ": "; 
      for (int j = 0; j < g[i].size(); ++j)
        cout << g[i][j] << " ";
  }
  cin >> m;

  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    cout << routeBetweenNode(x,y, g) << endl;
  }
  return 0;
}