# Coding-Interview

Someday I'll write a nice introduction text. Someday.

## C++ tricks
* Vector
``` cpp
vector<int> v;
v.push_back(value);
v.insert(v.begin() + i, value); // insert(v.begin()+2,4): {1, 5, 10, 15} => {1, 5, 4, 10, 15} 
v.erase(v.begin()+i, v.begin()+j); // erase(v.begin()+3,v.begin()+5): {0, 1, 2, 3, 4, 5, 6} => {0, 1, 2, 5, 6}
  ```
* Sorting
``` cpp
sort(v.begin(), v.end()); // Sort the whole array

struct Comparator {
  Comparator(int r, int c) : x(r), y(c) {}
  bool operator ()(const vector<int> &a, const vector<int> &b) {
	  return (abs(a[0]-x) + abs(a[1]-y)) < (abs(b[0]-x) + abs(b[1]-y));
  }
  int x, y;
};
sort(res.begin(), res.end(), Comparator(r,c));

/* C++11 Lambda*/
sort( v.begin( ), v.end( ), []( const MyStruct& a, const MyStruct& b )
				{
   					return a.key < b.key;
				});
  ```
  
* Substring
``` cpp
s.substr(i, size);      // begin, size
s.substr(i, j - i + 1); // begin, end
  ```
  
* Unordered map
``` cpp
unordered_map<string, int> ht;
ht["key"] = value;
if (ht.find("key") == ht.end()) { /* ... */ }

 unordered_map<string, int> ht({
				  { "a", 1 },
				  { "b", 2 }
  	  	  	       });
  ```
* Unordered set
``` cpp
unordered_set<int> hs;
hs.insert(value);
if (hs.find(value) == hs.end()) { /* ... */ }
 
/* Initialization from Vector */
unordered_set<int>(v.begin(), v.end());
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
 
 * Priority Queue 
 ``` cpp
 pritority_queue<int> heap; /* Max Heap */
 heap.push(value);
 int x = heap.top(); // Max element
 heap.pop();

 priority_queue <Type, vector<Type>, ComparisonType > pq;
 priority_queue <int, vector<int>, greater<int> > min_heap; /* Min Heap */
 
 /* C++11 Lambda*/
 auto cmp = [](int a, int b) { return (a ^ 1) < (b ^ 1); };
 priority_queue<int, std::vector<int>, decltype(cmp)> pq(cmp); /* decltype evaluates the type of a expression */
  
 ```
