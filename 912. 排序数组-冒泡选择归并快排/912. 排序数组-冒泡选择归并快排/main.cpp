//
//  main.cpp
//  排序
//
//  Created by 邱俊荣 on 2021/3/16.
//

/*
 给你一个整数数组 nums，请你将该数组升序排列。
 输入：nums = [5,2,3,1]
 输出：[1,2,3,5]
 */

#include <iostream>
#include <vector>
using namespace std;

// 冒泡排序1
void bubbleSort1(vector<int>& nums) {
    for (int end = nums.size()-1; end > 0; end--) {
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] < nums[begin-1]) {
                int tmp = nums[begin];
                nums[begin] = nums[begin-1];
                nums[begin-1] = tmp;
            }
        }
    }
}
// 冒泡排序2--优化--排除本来就是有序的数组
void bubbleSort2(vector<int>& nums) {
    bool sorted = true;
    for (int end = nums.size()-1; end > 0; end--) {
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] < nums[begin-1]) {
                int tmp = nums[begin];
                nums[begin] = nums[begin-1];
                nums[begin-1] = tmp;
                sorted = false;
            }
        }
        if (sorted) {
            break;
        }
    }
}
// 冒泡排序3--优化--记录交换的最后一次位置，排除掉末尾已经排序的地方
void bubbleSort3(vector<int>& nums) {
    for (int end = nums.size()-1; end > 0; end--) {
        int sortedIndex = 1;
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] < nums[begin-1]) {
                int tmp = nums[begin];
                nums[begin] = nums[begin-1];
                nums[begin-1] = tmp;
                sortedIndex = begin;
            }
        }
        end = sortedIndex;
    }
}
// 选择排序--对比冒泡法减少了交换次数，但是没法独立优化。可以配合使用二叉堆进行优化
void selectionSort(vector<int>& nums) {
    for (int end = nums.size()-1; end > 0; end--) {
        int maxIndex = 0;
        for (int begin = 1; begin <= end; begin++) {
            if (nums[begin] > nums[maxIndex]) {
                maxIndex = begin; // 内层循环先记录最大值下标，到外层交换
            }
        }
        int tmp = nums[end];
        nums[end] = nums[maxIndex];
        nums[maxIndex] = tmp;
    }
}

// 归并排序
class Solution {
    vector<int> leftArr;
    vector<int> numsArr;
public:
    
    vector<int> sortArray(vector<int>& nums) {
        numsArr = nums;
        leftArr.resize(nums.size() >> 1);
        mergeSort(0, (int)nums.size());
        return numsArr;
    }
    
    void mergeSort(int begin, int end) {
        if (end - begin < 2) { // 至少要有两个元素才可以排序
            return;
        }
        
        int mid = (begin + end) >> 1;
        mergeSort(begin, mid);
        mergeSort(mid, end);
        // 此处begin到mid以及mid到end下标应该都是有序了。且begin-mid-end在原数组中就是相邻的元素
        //接下来合并两个有序数组
        merge(begin, mid, end);
    }
    
    void merge(int begin, int mid, int end) {
        
        int li = 0, le = mid - begin; //基于左边备份出来的数组leftArr
        int ri = mid, re = end; //基于原数组右边部分
        int ai = begin; //基于原数组索引
        for (int i = 0; i < le; i++) {
            leftArr[i] = numsArr[begin+i]; // 备份出左边数组
        }
        
        while (li < le) {//leftArr用完了，直接使用右边元素覆盖剩下位置,因为右边元素本来就是在剩下位置，直接退出就行
            if (ri < re && numsArr[ri] < leftArr[li]) { // 这个判断的位置不要反过来，否则会失去排序后的稳定性
                numsArr[ai++] = numsArr[ri++];
            } else {
                numsArr[ai++] = leftArr[li++];
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {10,9,8,7,5,1,1,2,0,0};
//    bubbleSort1(nums);
//    bubbleSort2(nums);
//    bubbleSort3(nums);
//    selectionSort(nums);
    
    Solution solu;
    nums = solu.sortArray(nums);
    
    for (int num : nums) {
        cout << num << "->";
    }
    
    cout << endl;
    
    return 0;
}
