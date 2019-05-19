class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](vector<int> &a, vector<int> &b) { return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]); };
        sort(people.begin(), people.end(), comp);
        
        vector<vector<int>> sol(people.size(), vector<int>());
        for(int i = 0; i < people.size(); i++)
            for(int j = 0, k = 0; j < people.size(); j++) {
                if(k == people[i][1] && sol[j].size() == 0) {
                    sol[j] = people[i]; 
                    j = people.size();
                } else if(sol[j].size() == 0 || sol[j][0] == people[i][0]) k++;
            }
        return sol;
    }
};
