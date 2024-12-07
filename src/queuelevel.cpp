#include <iostream>
#include <chrono>
#include "graph_generator.hpp"

// Placeholder for unweighted SSSP (BFS) logic:
std::vector<matrixvalue> run_unweighted_sssp(const std::vector<std::vector<matrixvalue>> &adj, int source) {
    int n = (int)adj.size();
    std::vector<matrixvalue> dist(n, empty);
    // For unweighted, assume edges have implicit weight=1.
    // BFS approach:
    dist[source] = 0;
    // ... implement BFS level-set logic here ...
    return dist;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <p>\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    double p = std::stod(argv[2]);
    if (n <= 0 || p < 0.0 || p > 1.0) {
        std::cerr << "Invalid parameters. Ensure n > 0 and 0 <= p <= 1.\n";
        return 1;
    }

    GraphGenerator gen(n, p);
    auto adjacency = gen.generate_adjacency_matrix();

    auto start = std::chrono::steady_clock::now();
    auto dist = run_unweighted_sssp(adjacency, 0);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Unweighted SSSP on " << n << " nodes (p=" << p 
              << ") took " << elapsed.count() << " s\n";

    return 0;
}
