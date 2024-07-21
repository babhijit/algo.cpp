#pragma once

#include <vector>
#include <stdexcept>
#include <variant>


namespace algo::interview::medium::array::nested_list_weighted_sum {

    class NestedInteger {
    public:
        NestedInteger() : data(std::vector<NestedInteger>()) {}

        explicit NestedInteger(int value) : data(value) {}

        bool isInteger() const {
            return std::holds_alternative<int>(data);
        }

        int getInteger() const {
            if (isInteger()) {
                return std::get<int>(data);
            }
            throw std::logic_error("This NestedInteger does not hold an integer");
        }

        void setInteger(int value) {
            data =  value;
        }

        void add(NestedInteger const& ni) {
            if (isInteger()) {
                throw std::logic_error("Can not add NestedInteger that holds an integer");
            }
            auto& niList = std::get<std::vector<NestedInteger>>(data);
            niList.push_back(ni);
        }

        // Return the nested list that this NestedInteger holds, if it holds nested list
        // The result is undefined if this NestedInteger holds a single integer
        std::vector<NestedInteger> const &getList() const {
            if (isInteger()) {
                throw std::logic_error("Can not add NestedInteger that holds an integer");
            }
            return std::get<std::vector<NestedInteger>>(data);
        }

    private:
        std::variant<int, std::vector<NestedInteger>> data;
    };

}