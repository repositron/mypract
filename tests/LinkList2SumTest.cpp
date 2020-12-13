//
// Created by ljw on 9/12/20.
//

#include "../LinkList2Sum.h"
#include "gtest/gtest.h"
#include <vector>

namespace {
    LinkList2Sum::ListNode* toLinkList(std::vector<int> v) {
        LinkList2Sum::ListNode* root = nullptr;
        LinkList2Sum::ListNode* next = nullptr;
        for (int i: v) {
            if (!root)
                next = root = new LinkList2Sum::ListNode(i);
            else {
                next = next->next =  new LinkList2Sum::ListNode(i);
            }

        }
        return root;
    }
    std::vector<int> toVect(LinkList2Sum::ListNode* l) {
        std::vector<int> v;
        while (l) {
            v.push_back(l->val);
            l = l->next;
        }
        return v;
    }
    using namespace std;
    TEST(linkList2Sume, Test1) {

        std::vector<int> input1{2,4,3};
        std::vector<int> input2{5,6, 4};
        std::vector<int> answer{7, 0, 8};
        LinkList2Sum::ListNode* a = LinkList2Sum::addTwoNumbers(toLinkList(input1), toLinkList(input2));
        EXPECT_EQ(toVect(a), answer);
    }
}