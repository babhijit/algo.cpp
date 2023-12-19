#pragma once

#include "rated_food.hpp"

#include <unordered_map>
#include <set>
#include <string>
#include <vector>

namespace algo::cpp::design::flood_rating_system_2353 {

    /**
     * Your FoodRatings object will be instantiated and called as such:
     * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
     * obj->changeRating(food,newRating);
     * string param_2 = obj->highestRated(cuisine);
     */


    class FoodRatingSystem {
    public:
        explicit FoodRatingSystem(std::vector<std::string> foods,
                                  std::vector<std::string> cuisines,
                                  std::vector<int> ratings);

        void changeRating(std::string const& food, int newRating);

        std::string highestRated(std::string const& cuisine);

    private:
        std::unordered_map<std::string, std::set<RatedFood, std::greater<>>> cuisineRatings_;
        std::unordered_map<std::string, int> foodRatings_;
        std::unordered_map<std::string, std::string> foodCuisines_;
    };

} // algo::cpp::problems::hashtable::flood_rating_system_2353
