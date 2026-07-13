/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode*reverse(ListNode*head){
    if (head==nullptr||head->next==nullptr){
        return head;
    }
    ListNode*current = head;
    ListNode*front = nullptr;
    ListNode*previous = nullptr;
    while (current!=nullptr){
        front = current->next;
        current->next = previous;
        previous = current;
        current = front; 
    }
    return previous;
}
    bool isPalindrome(ListNode* head) {
            if (head==nullptr||head->next==nullptr){
        return head;
    }
        ListNode*fast = head;
        ListNode*slow=head;
        ListNode*previous=nullptr;
        while(fast!=nullptr&&fast->next!=nullptr){
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast!=nullptr){
            slow=slow->next;
        }
        previous->next=nullptr;
        ListNode*second = reverse(slow);
        ListNode*first=head;
        while(first!=nullptr&&second!=nullptr){
            if (first->val!=second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
