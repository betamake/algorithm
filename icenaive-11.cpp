 /**
 * 2019:10:28不在更新日期
 * leetcode-cn-11
 * icenaive
 */
//暴力是一切美学的起点
class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        for(int i = 0;i < height.length() - 1;i++) {
            for(int j = i + 1;j < height.length();j++) {
                area = max(area, min(height[i], height[j]) * (j - i));
            }
        }
        return area;
    }
};
//双指针 从两头向中间遍历 每次移动较短的线段向内
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, area = 0;
        while(l < r) {
            area = max(area, min(height[l], height[r]) * (r - l));
            if(height[l] < height[r]) ++l;
            else --r;
        }
        return area;
    }
};
