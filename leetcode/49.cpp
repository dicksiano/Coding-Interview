class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> sol;
        if(strs.size() == 0) return sol;
        
        unordered_map<string, vector<string>> hash;
        for(string s : strs) {
            string aux = s;
            sort(aux.begin(), aux.end());
            if(hash.find(aux) == hash.end()) hash[aux] = vector<string>();
            hash[aux].push_back(s);            
        }
        for(unordered_map<string, vector<string>>::iterator it = hash.begin(); it != hash.end(); it++)
            sol.push_back(it->second);
        return sol;
    }
};
