/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0)
        return "";
    int flag = 0;
    for (int i = 0;i < strlen(strs[0]);i++){
        for (int j = 1;j < strsSize;j++){
            if(strs[j][i] != strs[0][i]){
                strs[0][i] = '\0';
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            return strs[0];
        }
    }
    return strs[0];
}