#include "longest_uniq_substr.hpp"

#include <cstring>

namespace algo::problems::leetcode::strings::longest_uniq_substr {

    class SlidingWindow {
        static constexpr unsigned RADIX = 128;

        std::string &str;
        int left = 0;
        int right = 0;

        int char_indices[RADIX];

    public:
        explicit SlidingWindow(std::string &s) : str(s) {
            memset(char_indices, -1, sizeof(char_indices));
        }

        [[nodiscard]] int prev_index(char ch) const {
            return char_indices[radix(ch)];
        }

        [[nodiscard]] int window_size() const {
            return right - left;
        }

        void expand_window_to_right() {
            set_char_index(str[right], right);
            ++right;
        }

        void adjust_window_from_left(char duplicate) {
            auto old_left = char_indices[radix(duplicate)];

            while(left <= old_left) {
                clear_char_index(str[left++]);
            }
        }

    private:
        static unsigned radix(char ch) {
            return ch;
        }

        void set_char_index(char ch, int index) {
            char_indices[radix(ch)] = index;
        }

        void clear_char_index(char ch) {
            set_char_index(ch, -1);
        }

    };


    int LongestUniqueSubstring::lengthOfLongestSubstring(std::string s) {
        int max_substr_length = 0;
        SlidingWindow sliding_window(s);

        for (auto ch: s) {
            auto prev_index = sliding_window.prev_index(ch);
            if (prev_index != -1) {
                auto substr_len = sliding_window.window_size();
                max_substr_length = std::max(max_substr_length, substr_len);
                sliding_window.adjust_window_from_left(ch);
            }
            sliding_window.expand_window_to_right();
        }

        auto substr_len = sliding_window.window_size();
        max_substr_length = std::max(max_substr_length, substr_len);
        return max_substr_length;
    }

}
