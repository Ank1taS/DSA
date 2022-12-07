#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    std::vector<TreeNode<T>*> children; 

    // constructor
    TreeNode(T data) 
     : data{data} {}

    //  destructor 
    ~TreeNode() {
        for(int i {0}; i < children.size(); i++) { 
            delete children.at(i); // delete on all its children which will invoke corresponding destructor and ultimately delete the root node itself.
        } 
    }

};