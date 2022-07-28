#ifndef ALGO_CPP_BAG_HPP
#define ALGO_CPP_BAG_HPP

#include <iterator>
#include <list>

namespace algo::cpp::ds {


    template<typename T>
    class Bag {
    private:
        std::list<T> items_;

    public:
        explicit Bag() {}

        void add(T item) {
            items_.emplace_front(std::move(item));
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
