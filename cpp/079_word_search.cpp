// Word Search Total Accepted: 41321 Total Submissions: 202943 My Submissions Question Solution
// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (word[0] == board[i][j]) {
					if (DFS(board, i, j, word, 0)) {
						return true;
					}
				}
			}
		}

		return false;
	}

	bool DFS(vector<vector<char> > &board, int i, int j, string &word, int start) {
		if (start == word.size()) {
			return true;
		}
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[start] != board[i][j]) {
			return false;
		}


		board[i][j] = '#'; //已经遍历过的字符做标记
		if (DFS(board, i-1, j, word, start+1)) {
			return true;
		}
		if (DFS(board, i+1, j, word, start+1)) {
			return true;
		}
		if (DFS(board, i, j-1, word, start+1)) {
			return true;
		}
		if (DFS(board, i, j+1, word, start+1)) {
			return true;
		}
		board[i][j] = word[start]; //发现不对，撤销标记
		return false;
	}
};

int main() {
	vector<vector<char> > board;
	string word;
	char value;
	int n, m;
	Solution solution;

	while(cin>>n>>m) {
		for (int i = 0; i < n; i++) {
			vector<char> temp;
			for (int j = 0; j < m; j++) {
				cin >> value;
				temp.push_back(value);
			}
			board.push_back(temp);
		}
		cin>>word;
		cout << boolalpha <<solution.exist(board, word) << endl;
		board.clear();
	}
	return 0;
}