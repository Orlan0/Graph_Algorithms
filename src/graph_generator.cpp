#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <string>
#include <cstdlib>

// If you rely on these definitions:
using matrixvalue = unsigned;
const matrixvalue empty = std::numeric_limits<matrixvalue>::max();

class GraphGenerator {
private:
    int n; // number of nodes
    double p; // probability of edge
    std::mt19937 gen;
    std::uniform_real_distribution<> dist;
    std::uniform_int_distribution<matrixvalue> weight_dist;

public:
    GraphGenerator(int nodes, double probability, int seed=42) 
        : n(nodes), p(probability), gen(seed), dist(0.0,1.0), weight_dist(1,100) {}

    std::vector<std::vector<matrixvalue>> generate_adjacency_matrix() {
        std::vector<std::vector<matrixvalue>> adjacency((size_t)n, std::vector<matrixvalue>((size_t)n, empty));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    // no self loops
                    adjacency[i][j] = empty;
                } else {
                    double r = dist(gen);
                    if (r < p) {
                        matrixvalue w = weight_dist(gen);
                        adjacency[i][j] = w;
                    } else {
                        adjacency[i][j] = empty;
                    }
                }
            }
        }
        return adjacency;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <n> <p>\n";
        std::cerr << "  n: number of nodes (integer)\n";
        std::cerr << "  p: edge probability (0 <= p <= 1)\n";
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

    // Print the generated adjacency matrix for debugging (optional)
    // For large n, consider removing or redirecting this output.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjacency[i][j] == empty) {
                std::cout << ". ";
            } else {
                std::cout << adjacency[i][j] << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
