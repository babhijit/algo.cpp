//
// Created by abhijit on 27/7/22.
//

#ifndef ALGO_CPP_BAG_HPP
#define ALGO_CPP_BAG_HPP

#include <iterator>
#include <vector>

namespace algo::cpp::ds {


    template<typename T>
    class Bag {
        static constexpr int DEFAULT_CAPACITY = 8;

    private:
        std::vector<T> items_;

    public:
        explicit Bag(const int capacity = DEFAULT_CAPACITY) {
            items_.reserve(capacity);
        }

        void add(T item) {
            items_.push_back(std::move(item));
        }

        std::size_t size() const {
            return items_.size();
        }

        bool empty() const {
            return items_.empty();
        }

        auto begin() {
            return items_.begin();
        }

        auto end() {
            return items_.end();
        }

        auto rbegin() {
            return items_.rbegin();
        }

        auto rend() {
            return items_.rend();
        }

        auto begin() const {
            return items_.cbegin();
        }

        auto end() const {
            return items_.cend();
        }

        auto rbegin() const {
            return items_.crbegin();
        }

        auto rend() const {
            return items_.crend();
        }

    };

}

#endif //ALGO_CPP_BAG_HPP
