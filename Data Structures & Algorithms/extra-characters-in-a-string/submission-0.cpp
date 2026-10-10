struct Node{

    Node* links[26] = {nullptr};
    bool flag = false;

    bool containsLetter(char c){
        return (links[c-'a']!=nullptr);
    }

    void put (char c, Node* node){
        links[c-'a'] = node;
    }

    Node* get (char c){
        return links[c-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }


};

class Trie{
private:


public:
    Node* root;
    Trie(){
        root = new Node;
    }

    void insert(string& s){
        Node* node = root;
        for (char c: s){
            if (!node->containsLetter(c)){
                node->put(c, new Node);
            }
            node = node->get(c);
        }
        node->setEnd();
    }

    // bool search(string& s){
    //     Node* node = root;
    //     for (char c: s){
    //         if (!node->containsLetter(c)){
    //             return false;
    //         }
    //         node = node->get(c);
    //     }
    //     return node->isEnd();
    // }


};


class Solution {
private:
    int n;
public:

    int solve(int i, string& s, vector<int>& dp, Node* root){

        if (dp[i]!=-1) return dp[i];

        int temp1 = 1 + solve(i+1, s, dp, root); //assuming skip

        Node* node = root;
        int temp2 = INT_MAX;
        int j;
        for (j=i; j<n; j++){
            if (!node->containsLetter(s[j])) break;
            node = node->get(s[j]);
            if (node->isEnd()) temp2 = min(temp2,solve(j+1, s, dp, root));
        }
        

        return dp[i] = min(temp1, temp2); 

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        
        n = s.length();
        vector<int> dp(n+1, -1);
        dp[n] = 0;

        Trie* t = new Trie;
        for (auto& word : dictionary) t->insert(word);

        return solve(0,s,dp,t->root);



    }
};