class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        for(int j = 0; j < 30; j++) child[j] = nullptr;
        isFinal = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *p = this;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            
            if(p->child[index] == nullptr) p->child[index] = new WordDictionary();
            p = p->child[index];
        }        
        p->isFinal = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary *p = this;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] == '.') {
                for(int j = 0; j < 30; j++) 
                    if(p->child[j] && p->child[j]->search(&word[i+1])) return true;
                return false;
            } else {                
                int index = word[i] - 'a';
                p = p->child[index];
                if(p == nullptr) return false;
            }
        }     
        return p->isFinal;
    }
    
private:
    WordDictionary *child[30];
    bool isFinal;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
