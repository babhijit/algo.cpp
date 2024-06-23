#include "out_of_boundary_paths.hpp"

#include "path_finder.hpp"

namespace algo::interview::medium::dp::out_of_boundary_paths {

    int OutOfBoundaryPaths::findPaths(int m, int n,
                                      int maxMove,
                                      int startRow, int startColumn) {
        detail::PathFinder pathFinder{static_cast<std::uint32_t>(m),
                                      static_cast<std::uint32_t>(n),
                                      static_cast<std::uint32_t>(maxMove)};
        return pathFinder.findPaths(startRow, startColumn);
    }

}
