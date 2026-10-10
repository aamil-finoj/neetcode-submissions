struct Node{

    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsLetter(char c){
        if (links[c-'a'] != NULL) return true;
        else return false;
    }

    Node* get (char c){
        return links[c-'a'];
    }

    void put(char c, Node* node){
        links[c-'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

};



class PrefixTree {
private:
    Node* root;

public:
    PrefixTree() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i=0; i<word.size(); i++){
            char c = word[i];
            if (!node->containsLetter(c)){
                node->put(c, new Node);
            }
            node = node->get(c);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for (char c : word){

            if (!node->containsLetter(c)) return false;
            node = node->get(c);

        }
        return node->flag;

    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (char c : prefix){

            if (!node->containsLetter(c)) return false;
            node = node->get(c);

        }

        return true;

    }
};
