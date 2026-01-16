# Rubik's Cube Solver

A high-performance C++ implementation of a Rubik's Cube solver featuring multiple solving algorithms, different cube representations, and pattern database support for optimal solutions.

![C++](https://img.shields.io/badge/C%2B%2B-14-blue)
![CMake](https://img.shields.io/badge/CMake-3.20+-green)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey)

## 📋 Table of Contents
- [Overview](#-overview)
- [Features](#-features)
- [Algorithms Implemented](#-algorithms-implemented)
- [Cube Representations](#-cube-representations)
- [Prerequisites](#-prerequisites)
- [Installation & Build](#-installation--build)
- [Usage](#-usage)
- [Project Structure](#-project-structure)
- [How It Works](#-how-it-works)
- [Performance](#-performance)
- [Customization](#-customization)
- [Future Enhancements](#-future-enhancements)

## 🎯 Overview

This project implements a complete Rubik's Cube solver with four different search algorithms (DFS, BFS, IDDFS, IDA*) and three internal cube representations. It demonstrates classic AI search algorithms applied to a real-world puzzle, with optimizations for both memory and speed.

Perfect for:
- Learning search algorithms and data structures
- Understanding heuristic functions and pattern databases
- Benchmarking different algorithmic approaches
- Solving actual Rubik's Cube configurations

## ✨ Features

- **4 Solving Algorithms**: DFS, BFS, IDDFS, and IDA* with pattern databases
- **3 Cube Representations**: 3D Array, 1D Array, and Bitboard implementations
- **Pattern Database Support**: Pre-computed heuristics for IDA* solver
- **Modular Design**: Easy to enable/disable algorithms and test different configurations
- **Performance Optimized**: Bitboard representation for maximum efficiency
- **No External Dependencies**: Pure C++ implementation using only STL
- **Cross-Platform**: Builds and runs on Linux, macOS, and Windows

## 🧮 Algorithms Implemented

### 1. **DFS (Depth-First Search)**
- **Type**: Uninformed search
- **Optimality**: Not guaranteed
- **Memory**: Low
- **Best for**: Quick solutions with limited depth (3-8 moves)
- **Time Complexity**: O(b^d) where b=18 moves, d=depth

### 2. **BFS (Breadth-First Search)**
- **Type**: Uninformed search
- **Optimality**: ✅ Optimal (shortest path)
- **Memory**: High
- **Best for**: Finding the shortest solution for simple shuffles
- **Time Complexity**: O(b^d)

### 3. **IDDFS (Iterative Deepening DFS)**
- **Type**: Uninformed search
- **Optimality**: ✅ Optimal
- **Memory**: Low (combines DFS memory with BFS optimality)
- **Best for**: Balance between memory and optimality
- **Time Complexity**: O(b^d)

### 4. **IDA\* (Iterative Deepening A\*)**
- **Type**: Informed search (heuristic-based)
- **Optimality**: ✅ Optimal with admissible heuristic
- **Memory**: Low
- **Best for**: Complex shuffles (8+ moves) with pattern database
- **Time Complexity**: Much better than uninformed search with good heuristic
- **Requires**: Pre-computed pattern database file

## 🎯 Cube Representations

The project includes three different internal representations:

| Representation | Memory | Access Speed | Best Use Case |
|---------------|--------|--------------|---------------|
| **3D Array** | High | Fast | Learning & debugging |
| **1D Array** | Medium | Fast | General purpose |
| **Bitboard** | Low | Very Fast | Production & performance |

**Recommended**: `RubiksCubeBitboard` for best performance

## 📦 Prerequisites

- **CMake**: Version 3.20 or higher
- **C++ Compiler**: Supporting C++14 standard
  - GCC 5.0+
  - Clang 3.4+
  - MSVC 2015+
- **Make**: For building (or Ninja)

### Check Your System

```bash
cmake --version    # Should be 3.20+
g++ --version      # Or clang++ --version
```

## 🚀 Installation & Build

### Option 1: Command Line Build

```bash
# Clone the repository
git clone https://github.com/yourusername/RubiksCube.git
cd RubiksCube

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build the project
make

# Run the executable
./rubiks_cube_solver
```

### Option 2: CLion IDE

1. Open CLion
2. Select `File > Open` and choose the project directory
3. CLion will automatically detect `CMakeLists.txt`
4. Click the green play button (▶️) or press `Shift+F10` to build and run

### Common Build Issues

**Issue**: `CMake Error: The source directory does not appear to contain CMakeLists.txt`
```bash
# Make sure you're in the build directory when running cmake
cd build
cmake ..  # Note the ".." pointing to parent directory
```

**Issue**: Compiler not found
```bash
# Install build tools (macOS)
xcode-select --install

# Install build tools (Ubuntu/Debian)
sudo apt-get install build-essential cmake
```

## 💻 Usage

### Quick Start

The `main.cpp` file is organized into **6 independent sections** that can be easily enabled/disabled:

| Section | Description | Default State |
|---------|-------------|---------------|
| **Section 1** | Multi-Solver Demo (all 4 algorithms) | ✅ Active |
| **Section 2** | Generate Pattern Database | ⏸️ Commented |
| **Section 3** | Quick IDA* Test | ⏸️ Commented |
| **Section 4** | Basic Cube Operations Test | ⏸️ Commented |
| **Section 5** | Cube Equality & Assignment Test | ⏸️ Commented |
| **Section 6** | Unordered Map Test | ⏸️ Commented |

### Running Different Sections

**To enable a section**, remove the `/*` and `*/` around it:
```cpp
// SECTION 3: QUICK TEST
/*   <- Remove this line
{
    // ... code ...
}
*/   <- Remove this line
```

**To disable a section**, add `/*` and `*/`:
```cpp
// SECTION 1: MULTI-SOLVER DEMO
/*   <- Add this line
{
    // ... code ...
}
*/   <- Add this line
```

### Example Output

```
========================================
  RUBIK'S CUBE MULTI-SOLVER DEMO
========================================

Initial (Solved) Cube:
Rubik's Cube:
       W W W 
       W W W 
       W W W 
G G G  R R R  B B B  O O O 
G G G  R R R  B B B  O O O 
G G G  R R R  B B B  O O O 
       Y Y Y 
       Y Y Y 
       Y Y Y 

🎲 Shuffling cube with 5 random moves...
Shuffle moves: L U D B2 U' 

1️⃣  DFS SOLVER: 8 moves
2️⃣  BFS SOLVER: 5 moves (optimal)
3️⃣  IDDFS SOLVER: 5 moves
4️⃣  IDA* SOLVER: 5 moves
```

## 📁 Project Structure

```
RubiksCube/
├── CMakeLists.txt           # Build configuration
├── main.cpp                 # Main entry point with demos
├── README.md                # This file
├── USAGE_GUIDE.md           # Detailed usage instructions
├── bits/
│   └── stdc++.h            # Precompiled header
├── Model/
│   ├── RubiksCube.h        # Base class
│   ├── RubiksCube.cpp      # Shared implementation
│   ├── RubiksCube3dArray.cpp   # 3D array representation
│   ├── RubiksCube1dArray.cpp   # 1D array representation
│   └── RubiksCubeBitboard.cpp  # Bitboard representation
├── Solver/
│   ├── DFSSolver.h         # Depth-First Search
│   ├── BFSSolver.h         # Breadth-First Search
│   ├── IDDFSSolver.h       # Iterative Deepening DFS
│   └── IDAstarSolver.h     # IDA* with heuristic
├── PatternDatabases/
│   ├── PatternDatabase.h/.cpp      # Base pattern DB
│   ├── CornerPatternDatabase.h/.cpp # Corner heuristic
│   ├── CornerDBMaker.h/.cpp        # DB generator
│   ├── PermutationIndexer.h        # Indexing utility
│   ├── NibbleArray.h/.cpp          # Compact storage
│   └── math.h/.cpp                 # Math utilities
└── Databases/
    └── cornerDepth5V1.txt   # Pre-computed corner database
```

## 🔍 How It Works

### Cube Moves
The cube supports 18 moves (6 faces × 3 types):
- **Basic moves**: L, R, U, D, F, B (90° clockwise)
- **Prime moves**: L', R', U', D', F', B' (90° counter-clockwise)
- **Double moves**: L2, R2, U2, D2, F2, B2 (180°)

### Pattern Database
The IDA* solver uses a **corner pattern database** that pre-computes the minimum number of moves needed to solve just the corners from any position. This serves as an admissible heuristic:

1. **Generation** (Section 2): Takes ~30 minutes, creates `cornerDepth5V1.txt`
2. **Usage**: IDA* loads this file and uses it to prune the search tree
3. **Benefit**: Can solve 12+ move shuffles in seconds instead of hours

### Hash Functions
Each cube representation has a corresponding hash function:
- `Hash3d`: For `RubiksCube3dArray`
- `Hash1d`: For `RubiksCube1dArray`
- `HashBitboard`: For `RubiksCubeBitboard`

These enable efficient state tracking in BFS and IDDFS algorithms using `unordered_map`.

## ⚡ Performance

Approximate solving times on modern hardware (2020+ CPU):

| Shuffle Depth | DFS | BFS | IDDFS | IDA* |
|--------------|-----|-----|-------|------|
| 3 moves | <1s | <1s | <1s | <1s |
| 5 moves | <1s | <1s | <1s | <1s |
| 7 moves | ~2s | ~5s | ~3s | <1s |
| 10 moves | N/A | ~60s | ~40s | ~2s |
| 12+ moves | N/A | N/A | N/A | ~10s |

**Note**: BFS and IDDFS become impractical beyond 8-9 moves due to exponential growth.

## 🎨 Customization

### Changing Shuffle Difficulty

In `main.cpp` Section 1:
```cpp
int SHUFFLE_MOVES = 5;  // Change to 3-12
```

### Using Different Cube Representation

Replace `RubiksCubeBitboard` with:
```cpp
RubiksCube3dArray cube;   // or
RubiksCube1dArray cube;   // or
RubiksCubeBitboard cube;
```

### Adjusting Algorithm Depth

```cpp
int DFS_MAX_DEPTH = 8;     // Increase for deeper search
int IDDFS_MAX_DEPTH = 8;   // Increase for harder problems
```

### Enabling Only Specific Solvers

Comment out unwanted solver blocks in Section 1:
```cpp
/*
{
    cout << "\n1️⃣  DFS SOLVER...\n";
    // ... DFS code ...
}
*/
```

### Generating Your Own Pattern Database

Uncomment Section 2 in `main.cpp`:
```cpp
{
    string fileName = "/path/to/your/database.txt";
    CornerDBMaker dbMaker(fileName, 0x99);
    dbMaker.bfsAndStore();
}
```
**Warning**: This takes 30+ minutes and creates a ~100MB file.

## 🚀 Future Enhancements

Potential improvements and features:
- Edge pattern database for better heuristics
- Kociemba's two-phase algorithm
- GUI visualization of cube and solution
- Further bitboard optimizations
- Unit testing framework
- Support for 2×2 and 4×4 cubes
- Move sequence optimizer
- Web-based demo

## 📊 Tech Stack

- **Language**: C++14
- **Build System**: CMake 3.20+
- **Data Structures**: Hash maps, queues, vectors
- **Algorithms**: DFS, BFS, IDDFS, IDA*
- **Optimization**: Bitwise operations, pattern databases

---

**Created by Siddhant Wani** • January 2026

*A demonstration of search algorithms and data structures applied to solving the classic Rubik's Cube puzzle.*

