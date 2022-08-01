#ifndef ALGO_CPP_MY_HASHSET_HPP
#define ALGO_CPP_MY_HASHSET_HPP

#include <set>
#include <string>
#include <vector>

namespace algo::cpp::problems::hashtable::design_hashset_705 {

    class MyHashSet {
    public:
        explicit MyHashSet();

        void add(int key);

        void remove(int key);

        bool contains(int key) const;

        std::string str() const;

        void clear();

    private:
        std::size_t hash(int key) const;

        void rehash();

        const std::set<int>& bucket(int key) const;
        std::set<int>& bucket(int key);

    private:
        double load_factor_;
        std::size_t size_;
        std::size_t capacity_;
        std::vector<std::set<int>> hashtable_;
    };

}

#endif //ALGO_CPP_MY_HASHSET_HPP
