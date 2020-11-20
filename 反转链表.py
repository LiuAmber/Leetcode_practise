"""
题目描述
输入一个链表，反转链表后，输出新链表的表头。
示例1
输入

{1,2,3}
返回值

{3,2,1}
"""

class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        last=None
        while pHead!=None:
            tmp=pHead.next
            pHead.next=last
            last=pHead
            pHead=tmp
        return last