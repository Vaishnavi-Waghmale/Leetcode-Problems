class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        n=n/2;
        while(n--){
            head=head->next;
        }
        return head;
    }
};
