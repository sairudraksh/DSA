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
    vector<Node*>v;
    void dfs(Node* node,Node* clone){
        for(auto x:node->neighbors){
            if(v[x->val]==NULL){
                Node *newNode=new Node(x->val);
                clone->neighbors.push_back(newNode);
                v[x->val]=newNode;
                dfs(x,newNode);
            }
            else{
                clone->neighbors.push_back(v[x->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone=new Node(node->val);
        v.resize(101,NULL);
        v[clone->val]=clone;
        dfs(node,clone);
        return clone;
    }
};