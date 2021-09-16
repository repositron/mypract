//
// Created by ljw on 13/06/21.
//

#ifndef MYPRACT_COUSINSBINARYTREE_H
#define MYPRACT_COUSINSBINARYTREE_H

#include <vector>

namespace CousinsBinaryTree {
    struct TreeNode {
        int val = 0;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;

        TreeNode(int x) : val(x)  {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    bool isCousins(TreeNode* root, int x, int y);
    TreeNode* populate(const std::vector<int>& nodeList, std::size_t i);
};


#endif //MYPRACT_COUSINSBINARYTREE_H
