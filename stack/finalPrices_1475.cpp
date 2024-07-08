#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    stack<int> s;
    s.push(-1);
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() > prices[i])
        {
            s.pop();
        }
        int curr = prices[i];
        if (s.top() != -1)
        {
            prices[i] = prices[i] - s.top();
        }
        s.push(curr);
    }
    return prices;
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
    vector<int>prices = {8, 4, 6, 2, 3};
    printVec(prices);
    prices = finalPrices(prices);
    printVec(prices);
}