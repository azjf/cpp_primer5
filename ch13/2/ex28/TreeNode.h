#ifndef TREENODE_H
#define TREENODE_H
#include <string>

class TreeNode
{
public:
    TreeNode() : value(""), count(0), left(nullptr), right(nullptr) {}

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
#endif
