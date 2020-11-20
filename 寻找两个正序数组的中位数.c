/*
给定两个大小为 m 和 n 的正序（从小到大）数组?nums1 和?nums2。请你找出并返回这两个正序数组的中位数。

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

?

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：

输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000
?

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

*/


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double result;
    int flag_1=0,flag_2=0,mid_len=(nums1Size+nums2Size)/2+1,is_odd,flag_stop;
    if((nums1Size+nums2Size)%2 == 0){
        is_odd = 0;
    }
    else{
        is_odd = 1;
    }
    for(int i =0;i<=mid_len;i++){
        if(nums1[flag_1] <= nums2[flag_2]){
            flag_1++;
            flag_stop= 1 ;
        }
        else{
            flag_2++;
            flag_stop = 2;
        }   
    }
    if(is_odd==1){
        if(flag_stop==1){
            return (float)nums1[flag_1];
        }
        else if(flag_stop == 2){
            return (float)nums2[flag_2];
        }
    }
    else if(is_odd == 0){
        if(flag_stop == 1){
            if(nums1[flag_1-1]<=nums2[flag_2]){
                return ((float)nums1[flag_1-1]+(float)nums1[flag_1])/2;
            }
            else if(nums1[flag_1-1]> nums2[flag_2]){
                return ((float)nums1[flag_2]+(float)nums1[flag_1])/2;
            }
        }
        else if (flag_2 == 2){
            if(nums1[flag_2-1]<=nums2[flag_1]){
                return ((float)nums1[flag_2-1]+(float)nums1[flag_2])/2;
            }
            else if(nums1[flag_2-1]>nums2[flag_1]){
                return ((float)nums1[flag_1]+(float)nums1[flag_2])/2;
            }            
        }
    }
}