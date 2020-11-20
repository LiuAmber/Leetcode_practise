"""
题目描述
给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。
示例1
输入

"["
返回值

false
示例2
输入

"[]"
返回值

true
"""
class Solution:
    def isValid(self , s ):
        my_stack = []
        my_stack_ =[]
        for i in range(len(s)):
            if s[i]=='"':
                my_stack_.append()
            if s[i]=='{' or s[i]=='(' or s[i]=='[':
                my_stack.append(s[i])
            if   s[i]=='}' or s[i]==')' or s[i]==']':
                if len(my_stack) == 0:
                    return False
                temp = my_stack.pop(-1)
                if temp == '{' and s[i] == '}':
                    continue
                elif temp == '(' and s[i] == ')':
                    continue
                elif temp == '[' and s[i] == ']':
                    continue
                else:
                    return False
        if len(my_stack_)%2 == 1:
            return False
        if len(my_stack)!=0:
            return False
        return True
        # write code here