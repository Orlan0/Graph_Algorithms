# Graph_Algorithms


This project implements and benchmarks graph algorithms, including Single Source Shortest Path (SSSP) algorithms (weighted and unweighted), matrix-based operations, sparse matrix optimizations, and parallelism using OpenMP. The project allows users to test the algorithms on custom-generated graphs of varying sizes and densities.

## Table of Contents
1. [Features](#features)
2. [Requirements](#requirements)
3. [Setup Instructions](#setup-instructions)
4. [Running the Code](#running-the-code)
5. [Code Structure](#code-structure)
6. [Example Usage](#example-usage)
7. [Acknowledgments](#acknowledgments)

---

## Features
- Implementation of graph algorithms such as:
  - Unweighted SSSP
  - Weighted SSSP with priority queues
  - Sparse Matrix-based SSSP
  - Matrix-vector multiplication optimizations
- Random graph generation with configurable size and edge density.
- Caching for shortest path results and matrix operations to optimize performance.
- OpenMP parallelization for faster execution on large datasets.

---

## Requirements
To compile and run the project, ensure the following are installed on your system:
- **C++ Compiler** with C++20 support (e.g., GCC 10.2+, Clang 11.0+)
- **CMake** (minimum version 3.10)
- **OpenMP** library for parallel processing
- **Git** (optional, for cloning the repository)

---

## Setup Instructions
1. Clone the Repository:
   ```bash
   git clone https://github.com/username/graph-algorithms.git
   cd graph-algorithms
   ```

2. Build the Project:
   Create a build directory and compile the code using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Verify Installation:
   Ensure the executables are created in the `build/` directory:
   ```bash
   ls
   # Outputs: dijkstral, queuelevel, queuedijkstra, graphmvp, graphmvpdijkstra, graphsparse, graph_generator
   ```

---

## Running the Code
Each executable corresponds to a specific graph algorithm or functionality. Here's how to run them:

1. Graph Generator:
   Generate a random graph with specified nodes (`n`) and edge probability (`p`):
   ```bash
   ./graph_generator <n> <p>
   ```
   Example:
   ```bash
   ./graph_generator 100 0.1
   ```

2. Dijkstra's Algorithm:
   Test Dijkstra's algorithm on the generated graph:
   ```bash
   ./dijkstral <n> <p>
   ```

3. Queue-Level Algorithm:
   Run the queue-level implementation for SSSP:
   ```bash
   ./queuelevel <n> <p>
   ```

4. Matrix-Based Algorithms:
   Execute matrix-based SSSP or Dijkstra implementations:
   ```bash
   ./graphmvp <n> <p>
   ./graphmvpdijkstra <n> <p>
   ```

5. Sparse-Based Algorithms:
   Run the sparse matrix-based SSSP:
   ```bash
   ./graphsparse <n> <p>
   ```

6. Weighted Queue Implementation:
   Run the weighted queue-based algorithm:
   ```bash
   ./queuedijkstra <n> <p>
   ```

---

## Code Structure
The repository structure is as follows:

```
graph-algorithms/
├── src/
│   ├── dijkstral.cpp          # Dijkstra's algorithm implementation
│   ├── queuelevel.cpp         # Queue-based level implementation
│   ├── queuedijkstra.cpp      # Weighted queue-based implementation
│   ├── graphmvp.cpp           # Matrix-based SSSP implementation
│   ├── graphmvpdijkstra.cpp   # Matrix-vector Dijkstra implementation
│   ├── graphsparse.cpp        # Sparse matrix-based SSSP
│   ├── graph_generator.cpp    # Random graph generator
│   ├── Dag.hpp                # Directed Acyclic Graph (DAG) structure
│   ├── AdjacencyMatrix.hpp    # Dense graph representation
│   ├── SparseMatrix.hpp       # Sparse matrix representation
│   ├── Vector.hpp             # Distance vector utility
│   └── Cache.hpp              # Caching utilities
├── CMakeLists.txt             # Build system configuration
└── README.md                  # Project documentation
```

---

## Example Usage
### Generate a Graph
```bash
./graph_generator 100 0.1
```

### Run Dijkstra's Algorithm
```bash
./dijkstral 100 0.1
```

### Test Matrix-Based SSSP
```bash
./graphmvp 100 0.1
```

### Analyze Sparse-Based SSSP
```bash
./graphsparse 100 0.1
