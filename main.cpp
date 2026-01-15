//
// Created by Lakshya Mittal on 17-12-2021.
// Modified by Pranav Harresh on 25-07-2025.
//

#include <bits/stdc++.h>
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main() {

// ============================================================================================================
// SECTION 1: MULTI-SOLVER DEMO (Comment/Uncomment this entire block)
// ============================================================================================================
{
    cout << "========================================\n";
    cout << "  RUBIK'S CUBE MULTI-SOLVER DEMO\n";
    cout << "========================================\n\n";

    // Configuration
    int SHUFFLE_MOVES = 5;      // Change this to increase difficulty (3-12 recommended)
    int DFS_MAX_DEPTH = 8;      // Max depth for DFS
    int IDDFS_MAX_DEPTH = 8;    // Max depth for IDDFS

    // Create and shuffle cube
    RubiksCubeBitboard cube;
    cout << "Initial (Solved) Cube:\n";
    cube.print();

    cout << "\n🎲 Shuffling cube with " << SHUFFLE_MOVES << " random moves...\n";
    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(SHUFFLE_MOVES);
    cout << "Shuffle moves: ";
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n\nShuffled Cube:\n";
    cube.print();

    cout << "\n========================================\n";
    cout << "  Testing Different Solving Algorithms\n";
    cout << "========================================\n";

    // ----------------------------------------
    // Solver 1: DFS (Comment out if not needed)
    // ----------------------------------------
    {
        cout << "\n1️⃣  DFS SOLVER (Depth-First Search, max depth: " << DFS_MAX_DEPTH << ")\n";
        cout << "   Finding a solution (may not be optimal)...\n";
        RubiksCubeBitboard cubeDFS = cube;
        DFSSolver<RubiksCubeBitboard, HashBitboard> dfsSolver(cubeDFS, DFS_MAX_DEPTH);
        vector<RubiksCube::MOVE> dfs_moves = dfsSolver.solve();
        cout << "   ✓ Solution found: " << dfs_moves.size() << " moves\n";
        cout << "   Moves: ";
        for (auto move: dfs_moves) cout << cube.getMove(move) << " ";
        cout << "\n";
    }

    // ----------------------------------------
    // Solver 2: BFS (Comment out if not needed)
    // ----------------------------------------
    {
        cout << "\n2️⃣  BFS SOLVER (Breadth-First Search)\n";
        cout << "   Finding optimal solution...\n";
        RubiksCubeBitboard cubeBFS = cube;
        BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cubeBFS);
        vector<RubiksCube::MOVE> bfs_moves = bfsSolver.solve();
        cout << "   ✓ Optimal solution: " << bfs_moves.size() << " moves\n";
        cout << "   Moves: ";
        for (auto move: bfs_moves) cout << cube.getMove(move) << " ";
        cout << "\n";

        // Verify BFS solution
        cout << "\n   Verifying BFS solution...\n";
        for (auto move: bfs_moves) {
            cubeBFS.move(move);
        }
        if (cubeBFS.isSolved()) {
            cout << "   ✅ Cube successfully solved!\n";
        } else {
            cout << "   ❌ Solution verification failed\n";
        }
    }

    // ----------------------------------------
    // Solver 3: IDDFS (Comment out if not needed)
    // ----------------------------------------
    {
        cout << "\n3️⃣  IDDFS SOLVER (Iterative Deepening DFS, max depth: " << IDDFS_MAX_DEPTH << ")\n";
        cout << "   Finding solution iteratively...\n";
        RubiksCubeBitboard cubeIDDFS = cube;
        IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cubeIDDFS, IDDFS_MAX_DEPTH);
        vector<RubiksCube::MOVE> iddfs_moves = iddfsSolver.solve();
        cout << "   ✓ Solution found: " << iddfs_moves.size() << " moves\n";
        cout << "   Moves: ";
        for (auto move: iddfs_moves) cout << cube.getMove(move) << " ";
        cout << "\n";
    }

    // ----------------------------------------
    // Solver 4: IDA* (Comment out if database doesn't exist)
    // ----------------------------------------
    {
        cout << "\n4️⃣  IDA* SOLVER (A* with Iterative Deepening)\n";
        cout << "   Using pattern database for heuristic search...\n";
        string dbFileName = "/Users/siddhantwani/DEV/RubiksCube/Databases/cornerDepth5V1.txt";
        RubiksCubeBitboard cubeIDAStar = cube;
        IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cubeIDAStar, dbFileName);
        vector<RubiksCube::MOVE> idastar_moves = idAstarSolver.solve();
        cout << "   ✓ Solution found: " << idastar_moves.size() << " moves\n";
        cout << "   Moves: ";
        for (auto move: idastar_moves) cout << cube.getMove(move) << " ";
        cout << "\n";
    }

    cout << "\n========================================\n";
    cout << "✨ All solvers completed successfully!\n";
    cout << "========================================\n\n";
}
// END SECTION 1
// ============================================================================================================


// ============================================================================================================
// SECTION 2: GENERATE PATTERN DATABASE (Comment/Uncomment this entire block)
// WARNING: This takes several minutes to hours! Only run once to create the database file.
// ============================================================================================================
/*
{
    cout << "========================================\n";
    cout << "  GENERATING PATTERN DATABASE\n";
    cout << "========================================\n\n";
    cout << "⚠️  WARNING: This will take a long time (several minutes to hours)!\n";
    cout << "Creating cornerDepth5V1.txt database...\n\n";

    string fileName = "/Users/siddhantwani/DEV/RubiksCube/Databases/cornerDepth5V1.txt";
    CornerDBMaker dbMaker(fileName, 0x99);
    dbMaker.bfsAndStore();

    cout << "\n✅ Database generation complete!\n";
    cout << "Database saved to: " << fileName << "\n\n";
}
// END SECTION 2
*/
// ============================================================================================================


// ============================================================================================================
// SECTION 3: QUICK TEST - Shuffle and Solve with IDA* (Comment/Uncomment this entire block)
// ============================================================================================================
/*
{
    cout << "========================================\n";
    cout << "  QUICK IDA* TEST\n";
    cout << "========================================\n\n";

    RubiksCubeBitboard cube;
    cout << "Initial Cube:\n";
    cube.print();

    auto shuffleMoves = cube.randomShuffleCube(7);
    cout << "\nShuffle moves: ";
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n\nShuffled Cube:\n";
    cube.print();

    cout << "\nSolving with IDA*...\n";
    string fileName = "/Users/siddhantwani/DEV/RubiksCube/Databases/cornerDepth5V1.txt";
    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    cout << "\nSolution moves (" << moves.size() << "): ";
    for (auto move: moves) cout << cube.getMove(move) << " ";
    cout << "\n\nSolved Cube:\n";
    idaStarSolver.rubiksCube.print();
}
// END SECTION 3
*/
// ============================================================================================================


// ============================================================================================================
// SECTION 4: BASIC CUBE OPERATIONS TEST (Comment/Uncomment this entire block)
// ============================================================================================================
/*
{
    cout << "========================================\n";
    cout << "  TESTING BASIC CUBE OPERATIONS\n";
    cout << "========================================\n\n";

    // Test with RubiksCubeBitboard (change to other implementations if needed)
    RubiksCubeBitboard cube;

    cout << "Initial cube:\n";
    cube.print();
    cout << (cube.isSolved() ? "✅ SOLVED\n\n" : "❌ NOT SOLVED\n\n");

    // Test all basic moves
    cout << "Testing U move:\n";
    cube.u();
    cube.print();

    cout << "Testing L move:\n";
    cube.l();
    cube.print();

    cout << "Testing F move:\n";
    cube.f();
    cube.print();

    cout << "Testing R move:\n";
    cube.r();
    cube.print();

    cout << "Testing B move:\n";
    cube.b();
    cube.print();

    cout << "Testing D move:\n";
    cube.d();
    cube.print();

    cout << (cube.isSolved() ? "✅ SOLVED\n\n" : "❌ NOT SOLVED\n\n");

    // Test inverse moves
    cout << "Testing inverse moves (should return to solved state):\n";
    cube.dPrime();
    cube.bPrime();
    cube.rPrime();
    cube.fPrime();
    cube.lPrime();
    cube.uPrime();
    cube.print();

    cout << (cube.isSolved() ? "✅ SOLVED\n\n" : "❌ NOT SOLVED\n\n");
}
// END SECTION 4
*/
// ============================================================================================================


// ============================================================================================================
// SECTION 5: TEST CUBE EQUALITY AND ASSIGNMENT (Comment/Uncomment this entire block)
// ============================================================================================================
/*
{
    cout << "========================================\n";
    cout << "  TESTING CUBE EQUALITY & ASSIGNMENT\n";
    cout << "========================================\n\n";

    RubiksCubeBitboard cube1;
    RubiksCubeBitboard cube2;

    cout << "Created two cubes. Are they equal? ";
    if(cube1 == cube2) cout << "✅ Equal\n";
    else cout << "❌ Not Equal\n";

    cout << "\nShuffling cube1 with 1 move...\n";
    cube1.randomShuffleCube(1);

    cout << "Are they equal now? ";
    if(cube1 == cube2) cout << "✅ Equal\n";
    else cout << "❌ Not Equal\n";

    cout << "\nAssigning cube1 to cube2...\n";
    cube2 = cube1;

    cout << "Are they equal now? ";
    if(cube1 == cube2) cout << "✅ Equal\n";
    else cout << "❌ Not Equal\n";
}
// END SECTION 5
*/
// ============================================================================================================


// ============================================================================================================
// SECTION 6: TEST UNORDERED MAP WITH CUBES (Comment/Uncomment this entire block)
// ============================================================================================================
/*
{
    cout << "========================================\n";
    cout << "  TESTING UNORDERED_MAP WITH CUBES\n";
    cout << "========================================\n\n";

    unordered_map<RubiksCubeBitboard, bool, HashBitboard> cubeMap;

    RubiksCubeBitboard cube1;
    RubiksCubeBitboard cube2;

    cubeMap[cube1] = true;
    cube2.randomShuffleCube(8);

    cout << "Is cube1 in map? ";
    if (cubeMap[cube1]) cout << "✅ Yes\n";
    else cout << "❌ No\n";

    cout << "Is cube2 in map? ";
    if (cubeMap[cube2]) cout << "✅ Yes\n";
    else cout << "❌ No\n";
}
// END SECTION 6
*/
// ============================================================================================================

    return 0;
}