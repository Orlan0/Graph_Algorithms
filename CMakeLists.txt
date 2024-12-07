cmake_minimum_required(VERSION 3.10)
project(GraphAlgorithmsProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenMP if available
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# Include the src directory for headers
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add executables based on which .cpp files have main()
# Adjust these as needed for your project. If some files are just libraries, 
# use add_library instead, and then link them to the executables.

add_executable(dijkstral       src/dijkstral.cpp)
add_executable(queuelevel      src/queuelevel.cpp)
add_executable(queuedijkstra   src/queuedijkstra.cpp)
add_executable(graphmvp        src/graphmvp.cpp)
add_executable(graphmvpdijkstra src/graphmvpdijkstra.cpp)
add_executable(graphsparse     src/graphsparse.cpp)
add_executable(graph_generator src/graph_generator.cpp)

# Link OpenMP if found
if(OpenMP_CXX_FOUND)
    target_link_libraries(dijkstral PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(queuelevel PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(queuedijkstra PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(graphmvp PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(graphmvpdijkstra PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(graphsparse PUBLIC OpenMP::OpenMP_CXX)
    target_link_libraries(graph_generator PUBLIC OpenMP::OpenMP_CXX)
endif()
