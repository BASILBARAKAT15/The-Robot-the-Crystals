# The Robot & the Crystals - Dynamic Programming Project

**Author:** Basil Barakat  
**ID:** 12217132

## Introduction
The "Robot and Energy Crystals" problem is a classic algorithmic optimization challenge. The goal is to guide a robot through a tunnel containing a series of energy stations. Each station contains energy crystals that either increase (positive) or decrease (negative) the robot's energy. The objective is to maximize the total collected energy without exceeding the tunnel boundaries.

**Special Rules:**
* The robot can move 1 or 2 steps forward at a time.
* The robot collects the energy of each station it lands on.
* The robot can use a special power to skip (ignore) the energy of **at most one** station during its journey, negating its impact completely.

## Project Overview
This project explores and compares two advanced algorithmic techniques to solve the problem:

### Part 1: Divide & Conquer
The problem is initially approached using a recursive Divide and Conquer strategy. At each station, the algorithm explores the choices available: move 1 or 2 steps, and collect the energy or use the special skip power to bypass it. 
* **Pros:** Explores all combinations and guarantees the correct maximum energy value. It helps clarify the initial logical structure and branching nature of the problem.
* **Cons:** It has an exponential time complexity (O(2^N)) because it recomputes the same states multiple times. This makes it impractical and slow for large inputs.

### Part 2: Dynamic Programming
To overcome the inefficiency of the Divide and Conquer approach, a Dynamic Programming (DP) solution is implemented. A 2D matrix is constructed to cache subproblems, tracking the maximum energy reachable from a given station based on whether the special skip power is still available (Row 0) or has already been spent (Row 1).
* **Mechanism:** The algorithm starts from the last stop and works backward to the first stop (bottom-up approach). It solves smaller sub-problems first, records the results in the table, and uses them to build solutions for larger problems.
* **Pros:** Eliminates unnecessary recalculations, significantly reducing the time complexity from exponential to linear (O(N)). It avoids stack overflow issues and is highly efficient in terms of memory and execution speed.

## Conclusion
Dynamic programming is an effective, scalable methodology suitable for complex engineering applications. While the Divide & Conquer strategy is useful for understanding the mechanism of decision branching, the DP approach is necessary to safely and efficiently handle large amounts of data without causing processor overload or excessive memory consumption.
