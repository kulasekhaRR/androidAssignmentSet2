# Assignment Solutions

This repository contains solutions to the Problem statements given in the Android Assignment Set 2.

Each solution is designed to be clean, efficient, and easily testable via dynamic user input.

---

## Problem Statements

### Q1: N-Queens Puzzle (`ChessQueenPlacer.java`)
Place `n` queens on an `n × n` chessboard such that no two queens attack each other (i.e., no two share the same row, column, or diagonal). Return all possible valid board configurations.

- **Language:** Java  
- **Approach:** Recursive backtracking  
- **File:** `ChessQueenPlacer.java`

**Example Input:**
n = 4

**Example Output:**
.Q..

...Q

Q...

..Q.



..Q.

Q...

...Q

.Q..

---

### Q2: Module Dependency Checker (`circularDependency.cpp`)
Given a list of module dependencies in a large software system, determine whether any **circular dependency** exists. If present, loading the modules would result in an infinite loop.

- **Language:** C++  
- **Approach:** Depth-First Search (DFS) with recursion stack  
- **File:** `circularDependency.cpp`

**Example Input:**
n = 4

edges = {{0, 1}, {1, 2}, {2, 0}}

**Output:**
True

---

## How to Compile & Run

### For Java (N-Queens)

bash

javac ChessQueenPlacer.java

java ChessQueenPlacer

Enter board size when prompted.

For C++ (Cycle Detection)

g++ -o dependency circularDependency.cpp

./dependency

Enter the number of modules and dependency pairs when prompted.

