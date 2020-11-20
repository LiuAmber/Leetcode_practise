/*
题目描述
判断给定的链表中是否有环
扩展：
你能给出空间复杂度的解法么？
*/

bool hasCycle(struct ListNode* head ) {
    // write code here
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast && slow && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
        
    }
    return false;
}