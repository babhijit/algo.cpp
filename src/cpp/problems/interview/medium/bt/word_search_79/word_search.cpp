#include "word_search.hpp"

/**
 * Space Complexity: O(M * N)
 * Time Complexity: O (M * N * 3^len(Word) )
 *      Why 3?
 *          We do not have to go backwards from where we came from.
 *          This effectively means we can only go only for 3 directions instead of the usual 4.
 */

namespace algo::interview::medium::bt::word_search {

    class Impl {
    public:
        explicit Impl(Matrix<char> &_board, std::string const &_word) :
                board(_board),
                word(_word),
                ROWS(board.size()),
                COLUMNS(board[0].size()),
                visited(board.size(), std::vector<bool>(board[0].size(), false)) {

            for (int row = 0; row < ROWS; ++row) {
                for (int col = 0; col < COLUMNS; ++col) {
                    if (dfs(row, col, 0)) {
                        foundWord = true;
                        return;
                    }
                }
            }
        }

        bool exists() const {
            return foundWord;
        }

    private:
        bool dfs(int row, int col, int wordIndex) {
            // bounds check
            if ((row < 0) or (row >= ROWS) or
                (col < 0) or (col >= COLUMNS)) {
                return false;
            }

            // already visited
            if (visited[row][col]) {
                return false;
            }

            // current node not part of word
            if (board[row][col] != word[wordIndex]) {
                return false;
            }

            // have we picked up the full word
            if (wordIndex == (word.size() - 1)) {
                return true;
            }

            // mark current node as visited
            visited[row][col] = true;

            // continue to check if we can find the remaining part of the word
            ++wordIndex;
            auto matchResult = dfs(row - 1, col, wordIndex)  // top
                               or dfs(row + 1, col, wordIndex) // bottom
                               or dfs(row, col - 1, wordIndex) // left
                               or dfs(row, col + 1, wordIndex); // right

            // clear the visited flag as we are done matching at current level
            // this will enable searching for next possible match should the current match flow fails
            visited[row][col] = false;

            return matchResult;

        }

    private:
        Matrix<char> &board;
        std::string const &word;

        Matrix<bool> visited;
        bool foundWord{false};
        std::size_t const ROWS, COLUMNS;
    };


    bool WordSearch::exist(Matrix<char> &board, std::string word) {
        Impl impl(board, word);
        return impl.exists();
    }
}
