#include "grumpy_bookstore_owner.hpp"

#include <stdexcept>

namespace algo::problems::leetcode::array::grumpy_bookstore_owner_1052 {

    int GrumpyBookstoreOwner::maxSatisfied(std::vector<int> &customers, std::vector<int> &grumpy, int minutes) {
        int unsatisfiedCustomers {};
        int satisfiedCustomers {};

        for(int i = 0; i < minutes; ++i) {
            unsatisfiedCustomers += customers[i] * grumpy[i];
            satisfiedCustomers += customers[i] * (1 - grumpy[i]);
        }

        // max unsatisfied customers within the given period when bookstore keeper may be persuaded to remain un-grumpy
        int maxUnsatisfiedCustomers = unsatisfiedCustomers;
        for (int i = minutes; i < customers.size(); ++i) {
            // remove previous unsatisfied customers as we slide the window
            unsatisfiedCustomers -= customers[i - minutes] * grumpy[i - minutes];
            // add the newly visible unsatisfied customers
            unsatisfiedCustomers += customers[i] * grumpy[i];

            maxUnsatisfiedCustomers = std::max(maxUnsatisfiedCustomers, unsatisfiedCustomers);

            satisfiedCustomers += customers[i] * (1 - grumpy[i]);
        }

        // keeping the storekeeper happy for this alloted minutes
        satisfiedCustomers += maxUnsatisfiedCustomers;

        return satisfiedCustomers;
    }

}