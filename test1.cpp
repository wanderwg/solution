#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		//入栈和出栈的元素必须相等
		if (pushV.size() != popV.size())
			return false;
		//用s来模拟入栈与出栈的过程
		stack<int> s;
		size_t outIdx = 0;
		size_t inIdx = 0;
		while (outIdx < popV.size()) {
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size()) {
					s.push(pushV[inIdx]);
					inIdx++;
				}
				else
					return false;
			}
			s.pop();
			outIdx++;
		}
		return true;

	}
};

int main()
{
	Solution a;
	vector<int> v1{ 1,2,3,4,5 };
	vector<int> v2{ 4,5,3,2,1 };
	string s;
	bool ret=a.IsPopOrder(v1, v2);
	cout << ret << endl;
	return 0;
}