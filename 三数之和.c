/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/

int comp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int** returnArray = (int**)malloc(sizeof(int*) * (numsSize)*(numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize));
    qsort(nums, numsSize, sizeof(int), comp);
    *returnSize = 0;
    for (int i =0;i < numsSize;i++){
        if(nums[i] > 0){
            return returnArray;
        }
        if(i > 0 && nums[i] == nums [i -1]){
            continue;
        }
        int L = i +1;
        int R = numsSize -1;
        while(L < R){
            if(nums[i] + nums[L] + nums[R] == 0){
                 returnArray[*returnSize] = (int*)malloc(sizeof(int) * 3); 
                (*returnColumnSizes)[*returnSize] = 3; 
                returnArray[*returnSize][0] = nums[i];
                returnArray[*returnSize][1] = nums[L];
                returnArray[*returnSize][2] = nums[R];
                (*returnSize)++;
                while(L <R && nums[L] == nums[L + 1]){
                    L++;
                }
                while(L < R && nums[R] == nums[R - 1]){
                    R--;
                }
                L++;
                R--;
            }
            else if(nums[i] + nums[L] + nums[R] > 0){
                R--;
            }
            else if(nums[i] + nums[L] + nums[R] < 0){
                L++;
            }
        }

    }
    return returnArray;
}