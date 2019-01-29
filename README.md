# Coding-Interview

## C++ tricks
* Vector
``` cpp
vector<int> v;
v.push_back(value);
v.insert(v.begin() + delta);
v.erase(v.begin() + i, v.begin() + j);
  ```
* Sorting
``` cpp
sort(v.begin(), v.end()); // Sort the whole array
  ```
* Unordered map
``` cpp
unordered_map<string, int> ht;
ht["key"] = value;
ht.find("key") == ht.end();
  ```
* Unordered set
``` cpp
unordered_set<int> hs;
hs.insert(value);
hs.find(value) == hs.end();
  ```
* Pair
``` cpp
pair<int, int> p;
p = make_pair(v1, v2);
p.first = v1, p.second = v2;
  ```
 * Queue
 ``` cpp
queue<int> q;
q.push(value);
int x = q.front();
q.pop();
  ```
 * Stack
 ``` cpp
stack<int> s;
s.push(value)
int x = s.top();
s.pop();
 ```
