/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, map<Node*, Node*>& m){

        if (node == nullptr) return node;

        if (m.count(node)) return m[node];

        Node* temp = new Node(node->val);
        m[node] = temp;

        for (Node* it : node->neighbors){
            temp->neighbors.push_back(dfs(it, m));
        }

        return temp;

    }


    Node* cloneGraph(Node* node) {
        if (node == nullptr)  return node;

        map<Node*, Node*> m;

        return dfs(node, m);




    }
};
