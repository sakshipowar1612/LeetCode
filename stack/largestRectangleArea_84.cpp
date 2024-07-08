#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int max = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int m = i - 1, n = i + 1, area = 0;
        int leftSide = 0, rightSide = 0;
        while (m >= 0 && heights[m] >= heights[i])
        {
            leftSide++;
            m--;
        }
        while (n < heights.size() && heights[n] >= heights[i])
        {
            rightSide++;
            n++;
        }
        area = heights[i] * (rightSide + leftSide + 1);
        if (area > max)
        {
            max = area;
        }
    }
    return max;
}


int main(){
    vector<int>vec = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(vec);
}