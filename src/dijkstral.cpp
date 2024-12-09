#include <iostream>
#include <chrono>
#include "graph_generator.hpp" // Include the header we created
// Include headers for your Dag or Dijkstra implementations if needed

// Placeholder for your Dijkstra code:
std::vector<matrixvalue> run_dijkstra(const std::vector<std::vector<matrixvalue>> &adj, int source) {
    int n = static_cast<int>(adj.size());
    std::vector<matrixvalue> dist(n, empty);
    dist[source] = 0;
    // ... implement Dijkstra here ...
    return dist;
}

// Function to calculate memory usage of a vector of vectors
size_t calculate_memory_usage(const std::vector<std::vector<matrixvalue>> &adj) {
    size_t total = sizeof(adj); // Size of the outer vector
    for (const auto &row : adj) {
        total += sizeof(row); // Size of each inner vector object
        total += row.capacity() * sizeof(matrixvalue); // Memory allocated for elements
    }
    return total;
}

// Function to calculate memory usage of a single vector
size_t calculate_memory_usage(const std::vector<matrixvalue> &vec) {
    return sizeof(vec) + vec.capacity() * sizeof(matrixvalue);
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

    // Calculate memory usage of the adjacency matrix
    size_t adjacency_memory = calculate_memory_usage(adjacency);
    std::cout << "Memory used by adjacency matrix: " 
              << adjacency_memory / (1024.0 * 1024.0) << " MB\n";

    auto start = std::chrono::steady_clock::now();
    auto dist = run_dijkstra(adjacency, 0);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Dijkstra on " << n << " nodes (p=" << p 
              << ") took " << elapsed.count() << " s\n";

    // Calculate memory usage of the distance vector
    size_t dist_memory = calculate_memory_usage(dist);
    std::cout << "Memory used by distance vector: " 
              << dist_memory / (1024.0 * 1024.0) << " MB\n";

    // Total estimated memory usage
    double total_memory_mb = (adjacency_memory + dist_memory) / (1024.0 * 1024.0);
    std::cout << "Total estimated memory usage: " 
              << total_memory_mb << " MB\n";

    return 0;
}
