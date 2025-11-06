class Node{
    public:
    vector<Node*>childs;
    bool isEnd;
    Node() {
        isEnd = false;
        childs.resize(26,NULL);
    }
    
};
class Trie {
public:
    Node* root;
    Trie() {
        this->root = new Node();
    }
    
    void insert(string word) {
        auto temp = root;
        for(char ch: word) {
            if(temp->childs[ch-'a']) {
                temp = temp->childs[ch-'a'];
            }
            else {
                temp->childs[ch-'a'] = new Node();
                temp = temp->childs[ch-'a'];
            }
        }
        temp-> isEnd = true;
    }
    
    bool search(string word) {
        auto temp = root;
        for(char ch: word) {
            if(temp->childs[ch-'a']) {
                temp = temp->childs[ch-'a'];
            }
            else {
                return false;
            }
        }
        return temp-> isEnd;
    }
    
    bool startsWith(string word) {
        auto temp = root;
        for(char ch: word) {
            if(temp->childs[ch-'a']) {
                temp = temp->childs[ch-'a'];
            }
            else {
                return false;
            }
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
