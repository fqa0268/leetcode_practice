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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = 0;
        ListNode *head = new ListNode{(l1->val + l2->val)%10}; // extract the first(ones) digit
        ListNode *node1 = head;
        temp = (l1->val + l2->val)/10;  // temp is the second(tens) digit to be added on the next node.
        
        // move to the next nodes until one of the linked list is all done.
        while(l1->next != nullptr && l2->next != nullptr){ 
            l1 = l1->next; // l1, l2 is used for marking the nodes whose value will be added. 
            l2 = l2->next;
            ListNode *node2 = new ListNode{(l1->val + l2->val + temp)%10}; // create new node for the target linked list.
            node1->next = node2;
            temp = (l1->val + l2->val + temp)/10;
            node1 = node2;
        }
        
        // Since one linked list is all done, we'll handle the rest nodes of the other one, and make it as the l2.
        if(l1->next != nullptr)
            l2 = l1;
        while(l2->next != nullptr){
            l2 = l2->next;
            ListNode *node2 = new ListNode{(l2->val + temp)%10};
            node1->next = node2;
            temp = (l2->val + temp)/10;
            node1 = node2;
        }
        
        // if the sum of numbers of the last nodes is more than ten, then create the extra node to store the final digit.
        if(temp != 0){
            ListNode *node2 = new ListNode{temp%10};
            node1->next = node2;
        }
        return head;
    }
};
