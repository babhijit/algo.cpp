#include "food_rating_system.hpp"


#include <stdexcept>
#include <cassert>


namespace algo::cpp::design::flood_rating_system_2353 {
    FoodRatingSystem::FoodRatingSystem(std::vector<std::string> foods,
                                         std::vector<std::string> cuisines,
                                         std::vector<int> ratings) {
        assert(foods.size() == cuisines.size() and "size of foods and cuisines must match");
        assert(foods.size() == ratings.size() and "size of foods and ratings must match");

        for (int i = 0; i < foods.size(); ++i) {
            auto& cuisine = cuisines[i];
            auto& foodRatings = cuisineRatings_[cuisine];
            auto& food = foods[i];
            foodRatings.emplace(food, ratings[i]);
            foodRatings_[food] = ratings[i];
            foodCuisines_[food] = cuisine;
        }
    }

    void FoodRatingSystem::changeRating(const std::string &food, int newRating) {
        auto cuisineIt = foodCuisines_.find(food);
        if (cuisineIt == foodCuisines_.end()) {
            return;
        }
        auto& ratedFoods = cuisineRatings_[cuisineIt->second];
        auto foodRatingsIt = foodRatings_.find(food);
        if (foodRatingsIt != foodRatings_.end()) {
            auto  it = ratedFoods.find({food, foodRatingsIt->second});
            if (it != ratedFoods.end()) {
                ratedFoods.erase(it);
            }
        }
        ratedFoods.emplace(food, newRating);
        foodRatings_[food] = newRating;
    }

    std::string FoodRatingSystem::highestRated(const std::string &cuisine) {
        auto& foodRatings = cuisineRatings_[cuisine];
        if (foodRatings.empty()) {
            return {};
        }
        auto it = foodRatings.begin();
        return it->name();
    }
} // // algo::cpp::problems::hashtable::flood_rating_system_2353
