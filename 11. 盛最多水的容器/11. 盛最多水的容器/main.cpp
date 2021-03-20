//
//  main.cpp
//  11. 盛最多水的容器
//
//  Created by 邱俊荣 on 2021/3/20.
//
/*
 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 说明：你不能倾斜容器。
 // leetcode链接里有图表直观解释题意
 输入：[1,8,6,2,5,4,8,3,7]
 输出：49
 解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/container-with-most-water
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <iostream>
#include <vector>
using namespace std;


int maxArea(vector<int>& height) {
    if (height.size() == 0) return 0;

    int begin = 0, end = (int)height.size() - 1, water = 0;
    while (begin < end) {
        if (height[begin] <= height[end]) {
            water = max(water, (end - begin) * height[begin]);
            begin++;
        } else {
            water = max(water, (end - begin) * height[end]);
            end--;
        }
    }
    return water;
    
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    
    return 0;
}
