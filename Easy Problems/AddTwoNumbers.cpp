class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         l1 = l1 ? l1 : new ListNode(0);
    l2 = l2 ? l2 : new ListNode(0);
    
    int x = l1 ? l1->val : 0;
    int y = l2 ? l2->val : 0;
    
    l1->val = x + y;
    
    if(l1->val > 9) {
        l1->val = l1->val - 10;
        if(l1->next){
            l1->next->val = l1->next->val + 1;
        } else {
            l1->next = new ListNode(1);
        }
    }
    
    if(l1->next == NULL && l2->next == NULL) { return l1; }
    
    l1->next = addTwoNumbers(l1->next, l2->next);
    return l1;

    }
};
