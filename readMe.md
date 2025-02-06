# Computer Systems 2 - Project 1

**Author:** Tyler Ward  
**Platform:** Mac OS


---

## Bugs
None that I am aware of.

---

## Overview
This program takes in a file of random words and sorts them alphabetically. 
---

## Notes
At the top of the random file needs to be a number that says how many words are in the file that need to be sorted. 
---

## How I solved the problem 

Started making bubble sort becasue its the simplest. Moved on to merge and quick. Added a line in main for system sort and moved on to heap. Heap was difficult but not too bad. I then ran all of the test cases and created a graph for the random test cases. I then moved on to sorted test cases and created the graph for that. 

---
## How to Use
1. **Compile:**  
   ```bash
   g++ main.cpp sort.cpp

2. **Run:**  
   Execute the program with an input file:  
   ```bash
   ./a.out <input_file> <algorithm> [-print]