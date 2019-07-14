class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n - 1,max_area = 0;
        while (left < right) {
            max_area = max(max_area,min(height[left],height[right]) * (right - left));
            if (height[left] > height[right])
                right--;
            else
                left++;
        }
        return max_area;
    }
};
1.双指针为什么没有漏掉最优解？
反向思考，双指针做了剪枝，并且剪掉的都必定是不可能是最优解的结点，所以没有漏掉最优解。
2.left和right指向的点如果长度一样，不同方向的缩进会不会对结果产生影响？
不会。题目的意思是当前为最优值，存不存在另外一个比当前最优值还要大的值并且其中有一边是left或right。
不存在。想想就知道了。