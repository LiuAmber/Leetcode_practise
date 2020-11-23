/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/

bool isValid(char * s){
    int length = 0;
    while(s[length]!='\0'){
        length++;
    }
    char *stack = (char*)malloc(sizeof(char)*length);
    char temp;
    int top = -1;
    int index = 0;
    while(s[index] != '\0'){
        if(s[index] == '{'|| s[index] == '[' || s[index] == '('){
            top++;
            stack[top] = s[index];
            index++;
        }
        else if(s[index] == '}' || s[index] == ']' || s[index] == ')'){
            if (top < 0){
                return false;
            }
            temp = stack[top];
            top--;
            if(temp != '{' && s[index] == '}'){
                return false;
            }
            else if(temp != '[' && s[index] == ']'){
                return false;
            }
            else if(temp != '(' && s[index] == ')'){
                return false;
            }
            else{
                index++;
            }
        }
    }
    if(top >= 0){
        return false;
    }
    return true;
}