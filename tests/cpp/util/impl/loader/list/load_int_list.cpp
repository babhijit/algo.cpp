#include "load_int_list.hpp"

#include <algorithm>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>


namespace algo::cpp::ds::tests::utils {
    ListNode* LoadIntList::operator()(std::string input) {
        boost::trim(input);

        std::vector<std::string> values;
        boost::split(values, input, boost::is_any_of(","));

        std::vector<int> integers;
        std::transform(std::begin(values), std::end(values),
                       std::back_inserter(integers),
                       [](std::string s) {return boost::lexical_cast<int>(s);});

        return load_list(std::move(integers));
    }

    ListNode *LoadIntList::load_list(std::vector<int> values) {
        ListNode* root = new ListNode();
        ListNode* node = root;

        for(auto value: values) {
            node->next = new ListNode(value);
            node = node->next;
        }

        auto head = root->next;
        delete root;
        return head;
    }
} // utils