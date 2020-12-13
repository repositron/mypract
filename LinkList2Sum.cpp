//
// Created by ljw on 9/12/20.
//

#include "LinkList2Sum.h"




namespace LinkList2Sum {


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;

        ListNode* next = nullptr;
        ListNode* root = next;
        auto append = [&next, &root](int val) {
            if (!root)
                next = root = new ListNode(val);
            else
                next = next->next = new ListNode(val);
        };
        while (l1 || l2) {

            int add = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
            int add2 = add % 10;
            c = add > 9 ? 1 : 0;

            append(add2);

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        if (c)
            append(c);
        return root;
    }
};
/*ListNode* rem = l1 == nullptr ? l2 : l1;
while (rem) {
    int add = l1->val + l2->val + c;
    int add2 = add % 10;
    c = add > 9 ? 1 : 0;

    append(add2);

    rem = rem->next;

}*/