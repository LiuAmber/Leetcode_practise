"""
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

"""


class Solution(object):
	def letterCombinations(self, digits):
		if not digits:
			return []
		d = [" ","*","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
		res = []
		def dfs(tmp,index):
			if index==len(digits):
				res.append(tmp)
				return
			c = digits[index]
			letters = d[ord(c)-48]
			for i in letters:
				dfs(tmp+i,index+1)
		dfs("",0)
		return res