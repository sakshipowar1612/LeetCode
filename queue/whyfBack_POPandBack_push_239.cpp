#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> q;
    vector<int> ans;

    for (int index = 0; index < k; index++)
    {
        int ele = nums[index];
        while (!q.empty() && ele > nums[q.front()])
        {
            q.pop_front();
        }
        q.push_back(index);
    }

    for (int index = k; index < nums.size(); index++)
    {
        ans.push_back(nums[q.front()]);
        if (!q.empty() && index - q.front() >= k)
        {
            q.pop_front();
        }
        while (!q.empty() && nums[q.front()] < nums[index])
        {
            q.pop_front();
        }
        q.push_back(index);
    }
    ans.push_back(nums[q.front()]);
    return ans;
}

void printVec(vector<int> vec)
{
    for (int ele : vec)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main(){
    vector<int>nums = {1, 3, 1, 2, 0, 5};
    int k = 3;
    vector<int>ans = maxSlidingWindow(nums,k);
    printVec(ans);

}