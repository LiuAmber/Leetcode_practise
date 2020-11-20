"""
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设?s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

"""





class Solution:
    def longestPalindrome(self, s: str) -> str:
        s_len = len(s)
        s_add_len = s_len * 2 + 1
        s_add = []
        p = []
        j = 0
        for i in range(s_add_len):
            if i % 2 == 1:
                s_add.append(s[j])
                j += 1
            else:
                s_add.append('#')
        for i in range(s_add_len):
            j=1
            lens = 0
            while i-j >= 0 and i+j < s_add_len :

                if s_add[i-j] == s_add[i+j]:
                    j += 1
                    lens += 1
                else:
                    break
            p.append(lens)

        max_len_index, max_len = p.index(max(p)), max(p)
        real_max_len_index = int((max_len_index-1)/2-(max_len-1)/2)
        s_pip = []
        for i in range(real_max_len_index,real_max_len_index+max_len):
            s_pip.append(s[i])
        return ''.join(s_pip)