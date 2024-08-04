#pragma once

#include <string>


namespace algo::interview::medium::string::count_n_say {

    class CountAndSay {
    public:
        std::string countAndSay(int n);

    private:
        static std::string countAndSay(std::string const& s, int n);
    };
}