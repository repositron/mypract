//
// Created by ljw on 9/12/20.
//

#ifndef MYPRACT_LINKLIST2SUM_H
#define MYPRACT_LINKLIST2SUM_H


namespace LinkList2Sum {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};


#endif //MYPRACT_LINKLIST2SUM_H
