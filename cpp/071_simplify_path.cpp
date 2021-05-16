#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	string simplifyPath(string path)
	{
		string result;
		stack<string> pathStack;
		string subPath;
		int indexI = 0, indexJ = 0;

		path += "/";
		while(indexI < path.size())	{
			indexJ = path.find("/", indexI);
			subPath = path.substr(indexI, indexJ-indexI);

			if(subPath == "..") {
				if(!pathStack.empty())
					pathStack.pop();
			}
			else if(subPath != "." && subPath != "") {
				pathStack.push(subPath);
			}
			indexI = indexJ + 1;
		}

		while(!pathStack.empty()) {
			subPath = "/";
			subPath += pathStack.top();
			pathStack.pop();
			result = subPath + result;
		}

		if(result.empty()) {
			result = "/";
		}
		return result;
	}
};

class Solution1 {
public:
	string simplifyPath(string path)
	{
		string result;
		vector<string> pathVector;
		string subPath;
		int indexI = 0, indexJ = 0;

		path += "/";
		while(indexI < path.size())	{
			indexJ = path.find("/", indexI);
			subPath = path.substr(indexI, indexJ-indexI);

			if(subPath == "..") {
				if(!pathVector.empty())
					pathVector.pop_back();
			}
			else if(subPath != "." && subPath != "") {
				pathVector.push_back(subPath);
			}
			indexI = indexJ + 1;
		}

		for(int i=0; i<pathVector.size(); i++)
		{
			result += "/";
			result += pathVector[i];
		}

		if(result.empty()) {
			result = "/";
		}
		return result;
	}
};

int main()
{
	Solution1 solution;
	string path;
	while(cin>>path)
	{
		cout<< solution.simplifyPath(path) << endl;
	}
	return 0;
}