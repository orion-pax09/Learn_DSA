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
    ListNode*curr = head;
    ListNode*previous = nullptr;
    ListNode*next = nullptr;
    while(curr!=nullptr){
        next = curr->next;
        curr->next = previous;
        previous = curr;
        curr = next;
    }
    return previous;
}

    int pairSum(ListNode* head) {
        ListNode*fast = head;
        ListNode*slow = head;
        ListNode*previous = nullptr;
        ListNode*front = nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        previous->next = nullptr;
        ListNode*temp1 = head;
        ListNode*temp2 = reverse(slow);
        int max = 0;
        while(temp1!=nullptr&&temp2!=nullptr){
            int sum = temp1->val+temp2->val;
            if (max < sum){
                max = sum;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return max;
    }
};
