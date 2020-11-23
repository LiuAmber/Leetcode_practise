/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* prev = head;
    int length = 0;
    while(prev!=NULL){
        prev = prev->next;
        length++;
    }
    if(length == n){
        return head->next;
    }
    struct ListNode *myhead = head,*mytail = head;
    prev = head;
    for(int i = 0;i<n;i++){
        mytail = mytail->next;
    }
    while(mytail!=NULL){
        prev = myhead;
        myhead = myhead->next;
        mytail = mytail->next;
    }
    prev->next = myhead->next;
    return head;
}