/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

*/

int GetTargetFirstPosition(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == target) {
            high = mid - 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        }
    }
    if (low == numsSize || nums[low] != target) {
        return -1;
    }

    return low;
}

int GetTargetLastPosition(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] == target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
            
        }
    }
    if (low == 0 || nums[high] != target) {
        return -1;
    }

    return high;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int *)malloc(2 * sizeof(int));
    memset(res, -1, 2 * sizeof(int));
    *returnSize = 2;
    /* 特判 */
    if (nums == NULL || numsSize < 1) {        
        return res;
    }    
    
    int firstPos = GetTargetFirstPosition(nums, numsSize, target);
    /* 左边界没找到，右边界肯定也找不到 */
    if (firstPos == -1) {
        return res;
    }
    res[0] = firstPos;
    int lastPos = GetTargetLastPosition(nums, numsSize, target);
    res[1] = lastPos;

    return res;    
}
