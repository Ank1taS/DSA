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
};