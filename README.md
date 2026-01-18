# C++ Advanced - SoftUni Solutions

This repository contains my solutions to exercises from the **C++ Advanced** course at SoftUni. The course covers advanced C++ programming concepts, data structures, and algorithms.

## 📚 Course Overview

This course is part of the SoftUni programming curriculum and focuses on advanced C++ topics including:
- Advanced data structures (stacks, queues, trees, graphs, etc.)
- Algorithm implementation and optimization
- STL (Standard Template Library) usage
- Memory management
- Advanced C++ features and best practices

## 📁 Repository Structure

The repository is organized by topics, with each topic containing multiple exercises:

```
CPP Advanced/
├── 01StackAndQueue/
│   ├── 01reverseString/
│   ├── 01reverseString01/
│   ├── 01reverseStringStringOnly/
│   ├── 02stackSum/
│   ├── 02stackSum01/
│   ├── 03simpleCalculator/
│   ├── 04matchingBrakets/
│   ├── 05printEvenNumbers/
│   ├── 06supermarket/
│   ├── 06supermarket01/
│   ├── 07hotPotato/
│   └── 01StackAndQueue.slnx
├── 02StacksAndQueuesEx/
│   ├── 01basicStackOperations/
│   ├── 02basicQueueOperations/
│   ├── 03maximumMinimumElement/
│   ├── 03maximumMinimumElement01/
│   ├── 04fastFood/
│   ├── 05fashionBoutique/
│   ├── 06truckTour/
│   ├── 07balancedParantheses/
│   └── 02StacksAndQueuesEx.slnx
├── 03MapAndSet/
│   ├── 01countSameValuesInArray/
│   ├── 01countSameValuesInArray01/
│   ├── 02averageStudentGrades/
│   ├── 03citiesByContinentAndCountry/
│   ├── 04recordUniqueNames/
│   ├── 05parkingLot/
│   ├── 06uniqueUsernames/
│   ├── 07setsOfElements/
│   ├── 08evenTimes/
│   └── 03MapAndSet.slnx
└── 04MapAndSetEx/
    ├── 01countRealNumbers/
    ├── 02oddOccurrences/
    ├── 03largest3/
    ├── 04shortWords/
    ├── 05sortNumbers/
    ├── 06squares/
    ├── 07miners/
    └── 04MapAndSetEx.slnx
```

Each exercise is contained in its own directory with:
- **Source code** (`.cpp` files)
- **Visual Studio project files** (`.vcxproj`, `.vcxproj.filters`, etc.)

## ✅ Solutions

### 01. Stack and Queue

- [x] **01reverseString** - Reverse a string using a stack
- [x] **01reverseString01** - Alternative implementation for reversing a string
- [x] **01reverseStringStringOnly** - String reversal using string operations only
- [x] **02stackSum** - Calculate sum of elements in a stack
- [x] **02stackSum01** - Alternative implementation for stack sum
- [x] **03simpleCalculator** - Simple calculator implementation using stacks
- [x] **04matchingBrakets** - Find and print content inside matching brackets using a stack
- [x] **05printEvenNumbers** - Print even numbers from a queue
- [x] **06supermarket** - Supermarket queue simulation with customer service
- [x] **06supermarket01** - Alternative implementation for supermarket queue simulation
- [x] **07hotPotato** - Hot potato game simulation using queues

### 02. Stacks and Queues Exercises

- [x] **01basicStackOperations** - Basic stack operations: push N elements, pop S elements, check if X exists or find minimum
- [x] **02basicQueueOperations** - Basic queue operations: push N elements, pop S elements, check if X exists or find minimum
- [x] **03maximumMinimumElement** - Stack operations with commands to push, pop, find maximum, and find minimum elements
- [x] **03maximumMinimumElement01** - Alternative optimized implementation using auxiliary stacks for max/min tracking
- [x] **04fastFood** - Fast food restaurant simulation processing orders from a queue
- [x] **05fashionBoutique** - Fashion boutique rack management using stacks to calculate number of racks needed
- [x] **06truckTour** - Truck tour problem: find the starting petrol pump index to complete a circular tour
- [x] **07balancedParantheses** - Check if parentheses, braces, and brackets are balanced using a stack

### 03. Map and Set

- [x] **01countSameValuesInArray** - Count occurrences of same values in an array using map
- [x] **01countSameValuesInArray01** - Alternative implementation using unordered_map for counting values
- [x] **02averageStudentGrades** - Calculate and display average grades for students using map with vector of grades
- [x] **03citiesByContinentAndCountry** - Organize cities by continent and country using nested maps and sets
- [x] **04recordUniqueNames** - Record unique names in order of first appearance using set and vector
- [x] **05parkingLot** - Parking lot management system tracking cars using set (IN/OUT commands)
- [x] **06uniqueUsernames** - Store and display unique usernames in sorted order using set
- [x] **07setsOfElements** - Find and display common elements between two sets
- [x] **08evenTimes** - Find an element that appears an even number of times using unordered_map

### 04. Map and Set Exercises

- [x] **01countRealNumbers** - Count occurrences of real numbers in input and display sorted by value using map
- [x] **02oddOccurrences** - Find and display words that appear an odd number of times (case-insensitive) using unordered_map
- [x] **03largest3** - Find and display the 3 largest numbers from input using vector sorting
- [x] **04shortWords** - Collect and display words shorter than 5 characters in sorted order (case-insensitive) using set
- [x] **05sortNumbers** - Sort numbers in ascending order and display with " <= " separator using vector
- [x] **06squares** - Find perfect square numbers from input and display them in descending order using vector
- [x] **07miners** - Resource mining simulation tracking resource quantities and displaying in order of first appearance using map

## 🚧 Status

**Work in Progress** - This repository is actively being updated as I progress through the course. New exercises and solutions will be added regularly.

## 💻 Prerequisites

- C++ compiler (Visual Studio, GCC, or Clang)
- Basic understanding of C++ programming
- Familiarity with data structures and algorithms

## 🏃 Running the Solutions

Each exercise can be compiled and run independently:

1. Navigate to the specific exercise directory
2. Compile the `.cpp` file using your preferred C++ compiler
3. Run the executable

### Example (using Visual Studio):
- Open the `.slnx` solution file in Visual Studio
- Build and run the project

### Example (using command line):
```bash
g++ 01reverseString.cpp -o 01reverseString
./01reverseString
```

## 📝 Topics Covered

- [x] Stack and Queue
- [x] Stacks and Queues Exercises
- [x] Map and Set
- [x] Map and Set Exercises
- [ ] (More topics will be added as the course progresses)

## 📖 Notes

- Solutions are implemented as part of my learning journey
- Code may be optimized or refactored as I learn better practices
- Some exercises may be incomplete or have room for improvement

## 🤝 Contributing

This is a personal learning repository. However, suggestions and feedback are welcome!

## 📄 License

This repository is for educational purposes as part of the SoftUni C++ Advanced course.

---

**Note**: This repository is maintained as I progress through the SoftUni C++ Advanced course. Solutions are my own work and are shared for learning and reference purposes.

