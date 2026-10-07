/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

 

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2
示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1
示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4*/

/*题意概括：
返回 nums 中的第一个（最左边的）大于或等于 target 的数的下标。如果所有数都小于 target，返回 nums 的长度。*/

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize; // 左闭右开区间 [left, right)
    while (left < right) { // 区间不为空
        // 循环不变量：
        // nums[left-1] < target
        // nums[right] >= target
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1; // 范围缩小到 [mid+1, right)
        } else {
            right = mid; // 范围缩小到 [left, mid)
        }
    }
    return left; // 或者 right
}
