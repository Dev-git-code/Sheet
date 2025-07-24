```embed
title: "Sorting Algorithms - GeeksforGeeks"
image: "https://media.geeksforgeeks.org/wp-content/cdn-uploads/gfg_200x200-min.png"
description: "Your All-in-One Learning Portal: GeeksforGeeks is a comprehensive educational platform that empowers learners across domains-spanning computer science and programming, school education, upskilling, commerce, software tools, competitive exams, and more."
url: "https://www.geeksforgeeks.org/dsa/sorting-algorithms/"
favicon: ""
aspectRatio: "100"
```


## ✅ Core Comparison-Based Sorts – Frequent in Interviews

You should be very comfortable with these—common in interviews:

- **Selection Sort**, **Bubble Sort**, **Insertion Sort**  
    – Great for explaining basic logic and time complexity (O(n²))
    
- **Merge Sort**, **Quick Sort**, **Heap Sort**  
    – Crucial to understand divide‑and‑conquer, in‑place vs external sorting, recursion, stability, and complexity trade-offs (average O(n log n), worst-case O(n²) for Quick Sort)
    

**Why these matter:**

- Represent key algorithm design paradigms
- Common whiteboard questions: implement, analyze, discuss trade-offs
- Merge Sort (stable, external), Quick Sort (fast on average), Heap Sort (in-place O(n log n))
    

---

## 🧩 Non-Comparison Sorts – Be Familiar

Useful to know when the context is numbers with limited range:
Get the basic idea, useful in other questions but directly implementing them, don't bother.

- **Counting Sort**, **Radix Sort**, **Bucket Sort**  
    – Showcases linear-time sorting under constraints (Counting: O(n+k), Radix: O(w·n), Bucket: depends)
    
**When to mention:**

- When interviewer asks about sorting integers or strings beyond comparison limits
- For demnstrating understanding of time-space optimizations
    

---

## 🔀 Hybrid Algorithms – Know Their Role

Often under the hood in standard libraries:
Good to understand.

- **IntroSort**  
    – Hybrid of Quick + Heap + Insertion — used by C++ `std::sort`
    
- **Tim Sort**  
    – Python/Java/Android’s default; merges runs using merge+insertion
    

**Why this matters:**

- Shows awareness of library internals and real-world performance
- Good conversation point if interviewer asks about default sorts or hybrid strategies

| Algorithm      | Best Case  | Average Case | Worst Case | Space Complexity |
| -------------- | ---------- | ------------ | ---------- | ---------------- |
| Selection Sort | O(n²)      | O(n²)        | O(n²)      | O(1) in-place    |
| Bubble Sort    | O(n)       | O(n²)        | O(n²)      | O(1) in-place    |
| Insertion Sort | O(n)       | O(n²)        | O(n²)      | O(1) in-place    |
| Merge Sort     | O(n log n) | O(n log n)   | O(n log n) | O(n) extra       |
| Quick Sort     | O(n log n) | O(n log n)   | O(n²)      | O(log n) stack   |
| Heap Sort      | O(n log n) | O(n log n)   | O(n log n) | O(1) in-place    |
| Radix Sort     | O(n·k)     | O(n·k)       | O(n·k)     | O(n + k) extra   |

## List of sorting I must be able to implement in less than 5 mins

| Algorithm      | Time |
| -------------- | ---- |
| Selection Sort |      |
| Bubble Sort    |      |
| Insertion Sort |      |
| Merge Sort     |      |
| Quick Sort     |      |
| Heap Sort      |      |
| Radix Sort     |      |
