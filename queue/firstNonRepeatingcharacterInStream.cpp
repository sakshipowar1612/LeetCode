#include <iostream>
#include <queue>
#include <vector>
using namespace std;

string FirstNonRepeating(string A)
{
    queue<char> q;
    int frequency[26] = {0};
    string ans;
    for (int index = 0; index < A.length(); index++)
    {
        char ch = A[index];
        q.push(ch);
        frequency[ch - 'a']++;

        while (!q.empty())
        {
            if (frequency[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string s = "aabc";
    string ans = FirstNonRepeating(s);
    cout << ans << endl;

}