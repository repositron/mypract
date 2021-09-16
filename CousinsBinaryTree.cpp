//
// Created by ljw on 13/06/21.
//

#include "CousinsBinaryTree.h"
#include <vector>

namespace CousinsBinaryTree {
    TreeNode* populate(const std::vector<int>& nodeList, std::size_t i) {

        return (i < nodeList.size()) ?
            new TreeNode(nodeList[i],
                populate(nodeList, 2*i + 1),
                populate(nodeList, 2*i + 2)) : nullptr;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        return false;
    }
}
