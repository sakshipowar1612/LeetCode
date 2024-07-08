#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// TIME LIMIT EXCEEDED

// int largestRectangleArea(vector<int> &heights)
// {
//     int max = 0;
//     for (int i = 0; i < heights.size(); i++)
//     {
//         int m = i - 1, n = i + 1, area = 0;
//         int leftSide = 0, rightSide = 0;
//         while (m >= 0 && heights[m] >= heights[i])
//         {
//             leftSide++;
//             m--;
//         }
//         while (n < heights.size() && heights[n] >= heights[i])
//         {
//             rightSide++;
//             n++;
//         }
//         area = heights[i] * (rightSide + leftSide + 1);
//         if (area > max)
//         {
//             max = area;
//         }
//     }
//     return max;
// }

vector<int> prevSmallerEle(vector<int>vec){
    stack<int>s;
    vector<int>ans;
    s.push(-1);
    for (int i = 0; i < vec.size(); i++)
    {
        while (s.top()!=-1 && vec[s.top()]>vec[i])
        {
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i); 
    }
    return ans;
}

vector<int> nextSmallerEle(vector<int>&vec){
    stack<int>s;
    vector<int>ans;
    s.push(-1);
    for (int i = vec.size()-1; i >= 0; i--)
    {
        while (s.top()!=-1  && vec[s.top()]>vec[i])
        {
           s.pop();
        }
        if (s.top()==-1)
        {
            ans.push_back(vec.size());
        }
        else{
            ans.push_back(s.top());
        }
        
        s.push(i); 
    }
    int m = 0, n = ans.size()-1;
    while (m<n){
        swap(ans[m], ans[n]);
        m++;
        n--;
    }
    return ans;   
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int>prevSmall = prevSmallerEle(heights);
    vector<int>nextSmall = nextSmallerEle(heights);
    int max = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = nextSmall[i]-prevSmall[i]-1;
        int area = heights[i]*width;
        if (max < area)
        {
            max = area;
        }
        
    }
    return max;
}

void printVec(vector<int> vec)
{
    for (int ele : vec)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {2, 1, 4, 7, 2, 3};
    cout << largestRectangleArea(vec);
    // printVec(prevSmall);
    // printVec(nextSmall);
    // cout << largestRectangleArea(vec);
}