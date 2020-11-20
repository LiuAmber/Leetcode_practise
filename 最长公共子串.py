
"""
题目描述
给定两个字符串str1和str2,输出两个字符串的最长公共子串，如果最长公共子串为空，输出-1。
示例1
输入

"1AB2345CD","12345EF"
返回值

"2345"
"""

class Solution:
    def LCS(self , str1 , str2 ):
        str_list = []
        lens = 0
        mystr = []
        for i in range(len(str1)):
            temp_list = [0 for i in range(len(str2))]
            str_list.append(temp_list)
        for i in range(len(str1)):
            for j in range(len(str2)):
                if str1[i] == str2[j]:
                    str_list[i][j] = str_list[i-1][j-1]+1

                    if str_list[i][j] > lens:
                        x = i
                        y = j
                        lens = str_list[i][j]
        j = 0
        for i in range(x+1 ):
            if j >x- lens:
                mystr.append(str1[i])
            j += 1
        return  "".join(mystr)