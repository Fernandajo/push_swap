# ⚙️ Push_Swap  
>_Efficient stack sorting in C_

Push-Swap is a compact sorting program designed as part of the 42 school curriculum, that seamlessly combines algorithmic thinking, data structure manipulation, and performance tuning under tight constraints. The algorithm written in C outputs a sequence of stack operations that sort a list of integers using only two stacks and a restricted set of moves, all with the goal of minimizing the number of operations.

---
## Demo
<p align="center">
  <img src="assets/push_swap_visualizer.gif" alt="push_swap in action" width="600"/>  
</p>

---

## 🔍 Project Overview

The aim is simple yet challenging: sort a collection of integers using only two stacks (A and B) and a constrained command set (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). `Push_swap`, calculates and prints the optimal sequence of operations to reorder stack A in ascending order.

---

## 🧠 Key Features

- ⚙️ **Strict stack-based sorting** using only allowed operations  
- 📉 **Optimized move sequences** to minimize total operations  
- 🚫 Detects and reports input errors: non-numeric data, duplicates, overflows  
- ✅ Identity cases handled gracefully: zero or already sorted inputs output nothing  

The algorithmic strategy uses cost calculation for each candidate move.

---

## 🛠️ Build & Usage

Clone and compile the project:

```bash
git clone https://github.com/Fernandajo/push_swap.git
cd push_swap
make
```
To sort numbers:
```bash
./push_swap 4 2 3 1 5
```
