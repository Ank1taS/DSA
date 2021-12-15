// Given a generic tree, find and return the node with second largest value in given tree.
// Note: Return NULL if no node with required value is present.


#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

class NodePair {
public:
    TreeNode<int>* max;
    TreeNode<int>* secondMax;

    NodePair(TreeNode<int>* max, TreeNode<int>* secondMax) {
        this->max = max;
        this->secondMax = secondMax;
    }
};


// ===================================================================================================================

// #include<queue>
// TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    
//     if(root == NULL || !root->children.size()) return NULL;
// TreeNode<int>* F;
// TreeNode<int>* S;
// queue<TreeNode<int>*> Q;
// F=root;
// S=NULL;
// Q.push(root);
//     while(Q.size()){
//         for(int i=0;i<Q.front()->children.size();i++){
//                 TreeNode<int>* T=(Q.front()->children[i]);
//             Q.push(T);
//             if(S==NULL || T->data>S->data){
//                 if(T->data>F->data){
//                     S=F;
//                     F=T;
//                 }
//                 else{
//                     S=T;
//                 }
//             }
//         }
//         Q.pop();
//     }
//     if(F->data == S->data) return NULL;
//     return S;
// }


// ===========================================================================================================================



// void helper(TreeNode<int> *root,TreeNode<int> **first,TreeNode<int> **second){
//     if(root==NULL)
//     {
//         return;
    
//     }
//     if(!(*first)){
//         *first=root;
//     }
//     else if(root->data>(*first)->data){
//         *second=*first;
//         *first=root;
//     }
//     else if(!(*second)|| root->data>(*second)->data)
//         *second=root;
  
    
    
//     for(int i=0;i<root->children.size();i++)
//         helper(root->children[i],first,second);
// }
// TreeNode <int>* getSecondLargestNode(TreeNode<int> *root) {
//     TreeNode<int> *second=NULL;
//     TreeNode<int> *first=NULL;
//     helper(root,&first,&second);
        
//           if(second==NULL)
//             return NULL;
//     if(first->data==second->data)
//         return NULL;
    
//     return second;
//     // Write your code here

// }

// ===========================================================================================================================


class NodePair {
public:
    TreeNode<int>* max;
    TreeNode<int>* secondMax;

    NodePair(TreeNode<int>* max, TreeNode<int>* secondMax) {
        this->max = max;
        this->secondMax = secondMax;
    }
};


void helper(TreeNode<int>* root,NodePair * nodeSet) {
		
    if(root == NULL) return;
    	
    if(!(nodeSet->max))
    {
        nodeSet->max = root;
    }
    
    else if (nodeSet->max->data < root->data) {
        nodeSet->secondMax = nodeSet->max;
        nodeSet->max = root;
    }
	else if(!(nodeSet->secondMax)|| root->data > (nodeSet->secondMax->data)) {	
        nodeSet->secondMax = root;
        }  

    for (auto child : root->children) {
        helper(child,nodeSet);

    }  
}



TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if (!root || !root->children.size()) {
        return NULL;
    }

    // NodePair *nodeSet {helper(root)};
    NodePair *nodeSet = new NodePair(NULL,NULL);
    helper(root,nodeSet);
	
    if(nodeSet->max->data == nodeSet->secondMax->data)
    {
        return NULL;
    }
    
    return nodeSet->secondMax;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

    return 0;
}