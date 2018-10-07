#include <bits/stdc++.h>
using namespace std;

/* 
  Time: O(V + E) - DFS
  Space: O(V) - array to mark that the Vertex has been already visited

  Topological Sort - Visit each node using DFS. After visit a vertex, add it in the vector

  1. It's not equal to the classic DFS, because the edge (u,v) implies that v deppends of u
        - During the implementation, I do a inversion: the pair (u,v) becomes the edge u <- v
        - Instead of the inversion, I could do pair (u,v) becomes edge u -> v and use a Stack
  2. Instead of using a stack, use a vector for the same reason

*/
void dfs(int i, vector<int> adjList[], vector<int> &vis, vector<char> &ans, map<int, char> intToStr) {
  
  vis[i] = 1;
  for (int j = 0; j < adjList[i].size(); ++j) {
    if (vis[ adjList[i][j] ] == 1) {
      cout << "ERROR" << endl;
      return;
    }
    if (vis[ adjList[i][j] ] == 0) {
      dfs(adjList[i][j], adjList,vis,ans, intToStr);
    }
  }
  vis[i] = 2;
  ans.push_back(intToStr[i]);
}

/* 
  Auxiliar function to build the graph
  Also, build the auxiliary arrays to run the DFS
*/
vector<char> topSort(vector<char> p, vector< pair<char,char> > d) {
  map<char, int> strToInt;
  map<int, char> intToStr;

  for(int i = 0; i < p.size(); i++) {
    strToInt[ p[i] ] = i;
    intToStr[i] = p[i];
  }
  vector<int> adjList[p.size()];
  vector<char> ans;

  for(vector< pair<char,char> >::iterator it = d.begin(); it != d.end(); it++)
    adjList[ strToInt[it->second] ].push_back( strToInt[it->first] );


  vector<int> visited(p.size(),0); 

  for (int i = 0; i < p.size(); ++i) 
    if(!visited[i])
      dfs(i, adjList, visited, ans, intToStr);

  return ans;
}

int main() {
  vector<char> p;
  p.push_back('a');
  p.push_back('b');
  p.push_back('c');
  p.push_back('d');
  p.push_back('e');
  p.push_back('f');

  vector< pair<char,char> > d;
  d.push_back(make_pair('a','d'));
  d.push_back(make_pair('f','b'));
  d.push_back(make_pair('b','d'));
  d.push_back(make_pair('f','a'));
  d.push_back(make_pair('d','c'));

  vector<char> ans = topSort(p,d);

  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << endl;

  cout << endl << endl; p.clear(); d.clear();

  p.push_back('a');
  p.push_back('b');
  p.push_back('c');
  p.push_back('d');
  p.push_back('e');
  p.push_back('f');
  p.push_back('g');

  d.push_back(make_pair('f','a'));
  d.push_back(make_pair('f','b'));
  d.push_back(make_pair('f','c'));
  d.push_back(make_pair('c','a'));
  d.push_back(make_pair('b','a'));
  d.push_back(make_pair('a','e'));
  d.push_back(make_pair('b','e'));
  d.push_back(make_pair('d','g'));

  ans = topSort(p,d);

  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << endl;

  return 0;
}