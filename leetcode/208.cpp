class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        for(int i = 0; i < 30; i++) child[i] = nullptr;
        isFinal = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.size() == 0) return;
        
        int index = word[0]-'a';
        if(child[index] == nullptr) child[index] = new Trie();
        
        if(word.size() > 1) child[index]->insert(&word[1]);
        else child[index]->setIsFinal();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {        
        if(word.size() == 0) return true;
        
        int index = word[0]-'a';
        if(!child[index]) return false;
        
        if(word.size() > 1) return child[index]->search(&word[1]);
        return child[index]->getIsFinal(); 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        cout << "search: ";
        if(prefix.size() == 0) return true;
        
        int index = prefix[0]-'a';
        if(!child[index]) return false;
        
        if(prefix.size() > 1) return child[index]->startsWith(&prefix[1]);
        return true;         
    }
    
    void setIsFinal() {
        isFinal = true;
    }
    
    bool getIsFinal() {
        return isFinal;
    }
    
private:
    Trie *child[30];
    bool isFinal;
};
