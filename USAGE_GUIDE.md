# 🎲 Rubik's Cube Solver - Complete Usage Guide

## 📖 Table of Contents
1. [Quick Start](#quick-start)
2. [Main.cpp Structure](#maincpp-structure)
3. [How to Enable/Disable Sections](#how-to-enabledisable-sections)
4. [Configuration Options](#configuration-options)
5. [Examples](#examples)
6. [Troubleshooting](#troubleshooting)

---

## 🚀 Quick Start

### Build and Run
```bash
cd /Users/siddhantwani/DEV/RubiksCube/build
make
./rubiks_cube_solver
```

### After Making Changes to main.cpp
```bash
cd /Users/siddhantwani/DEV/RubiksCube/build
make
./rubiks_cube_solver
```

---

## 📐 Main.cpp Structure

Your `main.cpp` is organized into **6 independent sections**. Each section can be enabled/disabled by commenting/uncommenting.

### Current Status

| Section | Lines | Status | Description |
|---------|-------|--------|-------------|
| **Section 1** | 19-125 | ✅ **ACTIVE** | Multi-solver demo (all 4 algorithms) |
| **Section 2** | 128-148 | 💤 Commented | Generate pattern database (run once) |
| **Section 3** | 151-182 | 💤 Commented | Quick IDA* test |
| **Section 4** | 185-244 | 💤 Commented | Basic cube operations test |
| **Section 5** | 247-275 | 💤 Commented | Cube equality & assignment test |
| **Section 6** | 278-305 | 💤 Commented | Unordered map test |

---

## 🔧 How to Enable/Disable Sections

### Method 1: Enable/Disable Entire Section

**To Disable (Comment Out):**
```cpp
/*
{
    // ... entire section code ...
}
// END SECTION X
*/
```

**To Enable (Uncomment):**
```cpp
{
    // ... entire section code ...
}
// END SECTION X
```

### Method 2: Individual Solvers (Section 1)

Each solver in Section 1 is in its own `{ }` block. Comment out the entire block to disable:

```cpp
// Disable DFS (lines 48-59)
/*
{
    cout << "\n1️⃣  DFS SOLVER...\n";
    // ... DFS code ...
}
*/

// Disable BFS (lines 63-87)
/*
{
    cout << "\n2️⃣  BFS SOLVER...\n";
    // ... BFS code ...
}
*/

// Disable IDDFS (lines 91-100)
/*
{
    cout << "\n3️⃣  IDDFS SOLVER...\n";
    // ... IDDFS code ...
}
*/

// Disable IDA* (lines 104-116)
/*
{
    cout << "\n4️⃣  IDA* SOLVER...\n";
    // ... IDA* code ...
}
*/
```

---

## ⚙️ Configuration Options

### Section 1: Multi-Solver Demo (Lines 24-27)

```cpp
int SHUFFLE_MOVES = 5;      // Number of random moves to shuffle
int DFS_MAX_DEPTH = 8;      // Maximum search depth for DFS
int IDDFS_MAX_DEPTH = 8;    // Maximum search depth for IDDFS
```

#### Recommended Settings

| Use Case | SHUFFLE_MOVES | DFS_MAX_DEPTH | IDDFS_MAX_DEPTH | Expected Time |
|----------|---------------|---------------|-----------------|---------------|
| Quick test | 3 | 6 | 6 | < 10 seconds |
| Normal use | 5 | 8 | 8 | < 30 seconds |
| Challenging | 7 | 10 | 10 | 1-2 minutes |
| Very hard | 10 | 12 | 12 | 5+ minutes |
| Stress test | 13 | 15 | 15 | 10+ minutes |

---

## 📚 Section Details

### Section 1: Multi-Solver Demo ✅ (Currently Active)

**What it does:**
- Creates a solved Rubik's Cube
- Shuffles it with random moves
- Solves it using 4 different algorithms:
  1. **DFS** - Fast, may not be optimal
  2. **BFS** - Slower, always optimal
  3. **IDDFS** - Balanced approach
  4. **IDA*** - Fast with heuristics (requires database)
- Verifies the solution works
- Shows comparison summary

**When to use:**
- Comparing algorithm performance
- General testing and demonstrations
- Learning how different algorithms work

---

### Section 2: Generate Pattern Database 📦 (Commented)

**What it does:**
- Generates `cornerDepth5V1.txt` database file
- Required for IDA* solver to work efficiently
- Takes **several hours** to complete

**When to use:**
- First time setup for IDA* solver
- **Only run ONCE** - the database is reusable

**How to enable:**
1. Remove `/*` before line 132
2. Remove `*/` after line 145
3. Run the program
4. Wait for completion (be patient!)
5. After completion, comment it out again

**⚠️ WARNING:** This is a one-time operation. Don't run repeatedly!

---

### Section 3: Quick IDA* Test 🚀 (Commented)

**What it does:**
- Quick test of IDA* solver only
- Shuffles with 7 moves
- Solves and displays result

**When to use:**
- Testing IDA* performance
- Quick solve without other algorithms

**Prerequisites:**
- Database file must exist (run Section 2 first)

**How to enable:**
1. Ensure database exists
2. Remove `/*` before line 155
3. Remove `*/` after line 179

---

### Section 4: Basic Cube Operations Test 🔧 (Commented)

**What it does:**
- Tests all 6 basic moves: U, L, F, R, B, D
- Tests all 6 inverse moves: U', L', F', R', B', D'
- Verifies cube returns to solved state

**When to use:**
- Debugging cube mechanics
- Verifying cube implementation
- Learning cube move notation

**How to enable:**
1. Remove `/*` before line 189
2. Remove `*/` after line 241

---

### Section 5: Cube Equality & Assignment Test ⚖️ (Commented)

**What it does:**
- Tests `==` operator between cubes
- Tests assignment operator (`cube2 = cube1`)
- Verifies copy semantics

**When to use:**
- Testing cube comparison logic
- Debugging equality checks
- Verifying assignment works correctly

**How to enable:**
1. Remove `/*` before line 251
2. Remove `*/` after line 272

---

### Section 6: Unordered Map Test 🗺️ (Commented)

**What it does:**
- Tests using cubes as keys in `unordered_map`
- Verifies hash function works correctly

**When to use:**
- Testing hash function implementation
- Debugging visited state tracking in BFS/DFS
- Performance testing

**How to enable:**
1. Remove `/*` before line 282
2. Remove `*/` after line 302

---

## 🎯 Common Examples

### Example 1: Run Only BFS Solver (Optimal Solution)

**Goal:** Get the shortest solution without other algorithms

**Steps:**
1. Open `main.cpp`
2. In Section 1, comment out lines 48-59 (DFS)
3. Comment out lines 91-100 (IDDFS)
4. Comment out lines 104-116 (IDA*)
5. Keep lines 63-87 (BFS) uncommented

**Result:** Only BFS will run, giving you the optimal solution

---

### Example 2: Test with Harder Shuffle

**Goal:** Increase difficulty to 10 moves

**Steps:**
1. Open `main.cpp`
2. Go to line 26
3. Change `int SHUFFLE_MOVES = 5;` to `int SHUFFLE_MOVES = 10;`
4. Change `int DFS_MAX_DEPTH = 8;` to `int DFS_MAX_DEPTH = 12;`
5. Change `int IDDFS_MAX_DEPTH = 8;` to `int IDDFS_MAX_DEPTH = 12;`
6. Save and recompile

**Result:** Cube will shuffle with 10 moves, making it harder to solve

---

### Example 3: Setup IDA* for First Time

**Goal:** Generate database and enable IDA* solver

**Steps:**
1. Comment out Section 1 (add `/*` at line 19, `*/` at line 125)
2. Uncomment Section 2 (remove `/*` at line 132, `*/` at line 145)
3. Compile and run: `make && ./rubiks_cube_solver`
4. Wait for database generation (hours)
5. After completion:
   - Comment Section 2 again
   - Uncomment Section 1
   - IDA* solver will now work in Section 1

**Result:** Database file created, IDA* solver ready to use

---

### Example 4: Test Basic Cube Operations

**Goal:** Verify cube mechanics work correctly

**Steps:**
1. Comment out Section 1 (add `/*` at line 19, `*/` at line 125)
2. Uncomment Section 4 (remove `/*` at line 189, `*/` at line 241)
3. Compile and run

**Result:** Tests all moves and verifies cube returns to solved state

---

### Example 5: Compare DFS vs IDDFS Only

**Goal:** See difference between DFS and IDDFS

**Steps:**
1. In Section 1, comment out lines 63-87 (BFS)
2. Comment out lines 104-116 (IDA*)
3. Keep DFS and IDDFS uncommented
4. Run program

**Result:** Direct comparison of DFS vs IDDFS performance

---

## 🐛 Troubleshooting

### Problem: Compilation errors after uncommenting

**Solution:**
- Check you have matching `/*` and `*/`
- Make sure you didn't break the `{ }` structure
- Verify all sections still have their closing braces

---

### Problem: IDA* solver fails

**Possible causes:**
1. Database file doesn't exist
2. Wrong file path

**Solution:**
- Run Section 2 to generate database first
- Check file path at line 108: `/Users/siddhantwani/DEV/RubiksCube/Databases/cornerDepth5V1.txt`

---

### Problem: BFS takes forever

**Cause:** Shuffle depth too high

**Solution:**
- Reduce `SHUFFLE_MOVES` to 5-7
- Use IDDFS or IDA* for harder shuffles
- BFS is exponentially slower with deeper shuffles

---

### Problem: DFS returns empty solution

**Cause:** Max depth too low for the shuffle

**Solution:**
- Increase `DFS_MAX_DEPTH` to 10-12
- Or reduce `SHUFFLE_MOVES`

---

### Problem: Want to see intermediate steps

**Solution:**
Add print statements in the verification section (around line 75):

```cpp
for (auto move: bfs_moves) {
    cubeBFS.move(move);
    cout << "After " << cubeBFS.getMove(move) << ":\n";
    cubeBFS.print();
}
```

---

## 📊 Algorithm Comparison

| Algorithm | Speed | Memory | Solution Quality | Best For |
|-----------|-------|--------|------------------|----------|
| **DFS** | ⚡⚡⚡ Very Fast | ✅ Low | ⭐⭐ Good | Quick solutions, limited depth |
| **BFS** | 🐌 Slow | ❌ High | ⭐⭐⭐ Optimal | Finding shortest path |
| **IDDFS** | ⚡⚡ Medium | ✅ Low | ⭐⭐⭐ Optimal | Best balance overall |
| **IDA*** | ⚡⚡⚡ Very Fast | ✅ Low | ⭐⭐⭐ Optimal | Complex cubes (needs DB) |

---

## 🎓 Learning Path

1. **Start with Section 1** - See all algorithms in action
2. **Experiment with configuration** - Change shuffle depth
3. **Test individual solvers** - Comment out others
4. **Generate database** - Use Section 2 once
5. **Try Section 4** - Understand cube mechanics
6. **Use Sections 5 & 6** - If modifying code

---

## 📝 Quick Reference

### File Locations
- Main executable: `/Users/siddhantwani/DEV/RubiksCube/build/rubiks_cube_solver`
- Source code: `/Users/siddhantwani/DEV/RubiksCube/main.cpp`
- Database: `/Users/siddhantwani/DEV/RubiksCube/Databases/cornerDepth5V1.txt`

### Line Numbers
- Section 1: 19-125 (Multi-solver)
- Section 2: 128-148 (Database generation)
- Section 3: 151-182 (IDA* test)
- Section 4: 185-244 (Basic operations)
- Section 5: 247-275 (Equality test)
- Section 6: 278-305 (Map test)

### Configuration Lines
- Line 26: SHUFFLE_MOVES
- Line 27: DFS_MAX_DEPTH
- Line 28: IDDFS_MAX_DEPTH

---

## 🎉 You're All Set!

Your main.cpp is now perfectly organized with:
- ✅ 6 independent, self-contained sections
- ✅ Easy comment/uncomment structure
- ✅ Clear configuration options
- ✅ Individual solver control
- ✅ No code duplication
- ✅ Clean, maintainable structure

Happy solving! 🎲✨
