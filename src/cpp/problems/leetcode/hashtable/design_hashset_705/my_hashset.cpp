#include "my_hashset.hpp"

#include <functional>
#include <stdexcept>

namespace algo::cpp::problems::hashtable::design_hashset_705 {

    constexpr std::size_t DEFAULT_SIZE = 8;

    MyHashSet::MyHashSet() : capacity_{DEFAULT_SIZE}, size_{0} {
        load_factor_ = 0.75;
        hashtable_ = std::vector<std::set<int>>(capacity_, std::set<int>());
    }


    void MyHashSet::add(int key) {
        if (contains(key)) {
            return;
        }

        if (((double) size_ / (double) capacity_) > load_factor_) {
            rehash();
        }

        auto &bucket = this->bucket(key);
        bucket.insert(key);
        ++size_;
    }

    const std::set<int> &MyHashSet::bucket(int key) const {
        return hashtable_[hash(key)];
    }

    std::set<int> &MyHashSet::bucket(int key) {
        return hashtable_[hash(key)];
    }

    void MyHashSet::remove(int key) {
        auto &bucket = this->bucket(key);
        const std::set<int>::iterator &itr = bucket.find(key);
        if (itr != bucket.end()) {
            bucket.erase(itr);
            --size_;
        }
    }

    bool MyHashSet::contains(int key) const {
        auto& bucket = this->bucket(key);
        return bucket.find(key) != bucket.end();
    }

    void MyHashSet::clear() {
        auto new_hashtable = std::vector<std::set<int>>(capacity_, std::set<int>());
        std::swap(hashtable_, new_hashtable);
        size_ = 0;
    }

    std::string MyHashSet::str() const {
        throw std::runtime_error("Not implemented");
    }

    std::size_t MyHashSet::hash(int key) const {
        std::size_t hash = std::hash<int>{}(key);
        return hash % capacity_;
    }

    void MyHashSet::rehash() {
        auto new_capacity = capacity_ * 2;
        std::vector<std::set<int>> new_hashtable(new_capacity, std::set<int>());

        auto hasher = std::hash<int>{};
        for (auto& bucket: hashtable_) {
            for (auto& key: bucket) {
                auto index = hasher(key) % new_capacity;
                auto& new_bucket = new_hashtable[index];
                new_bucket.insert(key);
            }
        }

        std::swap(hashtable_, new_hashtable);
        std::swap(capacity_, new_capacity);
    }
}