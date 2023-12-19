#pragma once

#include <string>

namespace algo::cpp::design::flood_rating_system_2353 {

    class RatedFood {
    public:
        RatedFood(std::string name, int rating) :
                name_(std::move(name)),
                rating_(rating) {
        }

        [[nodiscard]] std::string const& name() const noexcept {
            return name_;
        }

        [[nodiscard]] int rating() const noexcept {
            return rating_;
        }

        bool operator==(RatedFood const& other) const {
            return (rating_ == other.rating_) and (name_ == other.name_);
        }

        bool operator>(RatedFood const& other) const {
            if (rating_ == other.rating_) {
                return name_ < other.name_;
            }
            return rating_ > other.rating_;
        }

    private:
        const std::string name_;
        const int rating_;
    };

} // algo::cpp::design::flood_rating_system_2353

