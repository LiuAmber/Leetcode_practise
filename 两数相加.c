/*
给出两个非空 链表用来表示两个非负的整数。其中，它们各自的位数是按照?逆序?的方式存储的，并且它们的每个节点只能存储一位数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0?开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
int i=0;
struct ListNode* p1,*p,*q,*head,*r;
head=(struct ListNode*)malloc(sizeof(struct ListNode));
head->next=NULL;
p1=head;
p=l1;
q=l2;
while(p!=NULL||q!=NULL){
    if(p!=NULL&&q!=NULL){
        r=(struct ListNode*)malloc(sizeof(struct ListNode));
        r->next=NULL;
        p1->next=r;
        p1=r;
        if(p->val+q->val>=10){
            r->val=(p->val+q->val)%10;
            if(p->next!=NULL)
            p->next->val+=1;
            else {p->next=(struct ListNode*)malloc(sizeof(struct ListNode));p->next->val=1;p->next->next=NULL;}
        }
        else r->val=p->val+q->val;
        p=p->next;
        q=q->next;
    }
    else if(p!=NULL&&q==NULL){
        r=(struct ListNode*)malloc(sizeof(struct ListNode));
         r->next=NULL;
        p1->next=r;
        p1=r;
        if(p->val>=10){
         r->val=p->val%10;
        if(p->next!=NULL)
            p->next->val+=1;
            else {p->next=(struct ListNode*)malloc(sizeof(struct ListNode));p->next->val=1;p->next->next=NULL;}
        } 
        else r->val=p->val;
        p=p->next;

    }
        else if(p==NULL&&q!=NULL){
        r=(struct ListNode*)malloc(sizeof(struct ListNode));
        r->next=NULL;
        p1->next=r;
        p1=r;
        r->val=q->val;       
        q=q->next; 
    }

}
head=head->next;
return head;

}