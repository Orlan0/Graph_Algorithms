// graph_generator.hpp
#pragma once
#include <vector>
#include <limits>
#include <random>

using matrixvalue = unsigned;
const matrixvalue empty = std::numeric_limits<matrixvalue>::max();

class GraphGenerator {
private:
    int n; 
    double p; 
    std::mt19937 gen;
    std::uniform_real_distribution<> dist_r;
    std::uniform_int_distribution<matrixvalue> weight_dist;
public:
    GraphGenerator(int nodes, double probability, int seed=42) 
        : n(nodes), p(probability), gen(seed), dist_r(0.0,1.0), weight_dist(1,100) {}

    std::vector<std::vector<matrixvalue>> generate_adjacency_matrix() {
        std::vector<std::vector<matrixvalue>> adjacency((size_t)n, std::vector<matrixvalue>((size_t)n, empty));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dist_r(gen) < p) {
                    adjacency[i][j] = weight_dist(gen);
                }
            }
        }
        return adjacency;
    }
};
