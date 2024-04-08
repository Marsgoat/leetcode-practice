#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, const string& word) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (dfs(board, i, j, word, 0)) return true;
      }
    }
    return false;
  }

 private:
  bool dfs(vector<vector<char>>& board, int i, int j, const string& word,
           int index) {
    if (index == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != word[index])
      return false;

    char cur = board[i][j];
    board[i][j] = '*';
    bool exists = dfs(board, i + 1, j, word, index + 1) ||
                  dfs(board, i - 1, j, word, index + 1) ||
                  dfs(board, i, j + 1, word, index + 1) ||
                  dfs(board, i, j - 1, word, index + 1);
    board[i][j] = cur;
    return exists;
  }
};

int main() {
  Solution solution;
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";

  bool result = solution.exist(board, word);

  cout << "Exist: " << (result ? "true" : "false") << endl;

  return 0;
}