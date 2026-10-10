struct Node{

    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsLetter(char c){
        return (links[c-'a'] != nullptr);
    }

    void put (char c, Node* node){
        links[c-'a'] = node;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void setEnd(){
        flag = true;
    }

};



class WordDictionary {
private:

    Node* root;

    bool solve(int i, string& word, Node* node){
        if (i==word.length()) return node->flag;

        char c = word[i];
        if (c!='.'){
            if (!node->containsLetter(c)) return false;
            node=node->get(c);
            return solve(i+1, word, node);
        }
        else{
            bool res = false;
            for (int j=0; j<26; j++){
                if (node->links[j]!=nullptr)
                    res = solve(i+1, word, node->links[j]);

                if (res) return res;
            }
            return false;
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char c : word){
            if (!node->containsLetter(c)){
                node->put(c,new Node);
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        return solve(0, word, node);
    }
};
