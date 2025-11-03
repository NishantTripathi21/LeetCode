class Trie {
public:
    class TrieNode {
        public:
        TrieNode* children[26];
        bool isTerminal;

        TrieNode() {
            isTerminal = false;

            for(int i= 0; i< 26; i++) {
                children[i] = NULL;
            }
        }
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* crawler = root;
        for(int i= 0; i< word.size();  i++) {
            char ch = word[i];
            if(crawler->children[ch-'a'] != nullptr) {
                crawler= crawler->children[ch-'a'];
            }
            else {
                auto newTrieNode =  new TrieNode();
                crawler->children[ch-'a']= newTrieNode;
                crawler = crawler->children[ch-'a'];
            }
        }
        crawler->isTerminal = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(char ch: word) {
            int idx = ch - 'a';
            if(crawler->children[idx] == nullptr) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        if(crawler->isTerminal)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        for(char ch: prefix) {
            int idx= ch - 'a';
            if(crawler->children[idx] == nullptr)return false;
            crawler= crawler->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
