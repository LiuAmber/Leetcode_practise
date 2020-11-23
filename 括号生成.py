"""
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
"""

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        cur_str = ""
        def dfs(cur_str,right,left):
            if right == 0 and left == 0:
                res.append(cur_str)
                return
            if right < left:
                return 
            if (left > 0):
                dfs(cur_str+'(',right,left-1)
            if right > 0:
                dfs(cur_str+')',right-1,left)

        dfs(cur_str,n,n)
        return res