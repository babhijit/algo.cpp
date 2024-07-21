#include "lowest_common_ancestor.hpp"

#include <vector>

namespace algo::interview::medium::tree::lowest_common_ancestor_3 {

    std::vector<Node*> getHierarchy(Node* node) {
        std::vector<Node*> parents;
        for(; node; node = node->parent) {
            parents.push_back(node);
        }
        return parents;
    }

    Node *LowestCommonAncestor::lowestCommonAncestor(Node *p, Node *q) {
        auto parentP = getHierarchy(p);
        auto parentQ = getHierarchy(q);

        auto itP = parentP.rbegin();
        auto itQ = parentQ.rbegin();

        Node* lastCommonAncestor {};
        while ((itP != parentP.rend()) and (itQ != parentQ.rend())) {
            if (*itP == *itQ) {
                lastCommonAncestor = *itP;
            }
            ++itP;
            ++itQ;
        }

        return lastCommonAncestor;
    }
}