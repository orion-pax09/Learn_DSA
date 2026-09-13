I am learning LeetCode 1004 — Max Consecutive Ones III.

I have written this C++ solution:

```cpp
class Solution { 
public: 
    int longestOnes(vector<int>& nums, int k) { 
        int max_length = 0; 
        int left = 0; 
        int count = 0; 

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) {
                count++;
            }

            while (count > k) {
                if (nums[left] == 0) {
                    count--;
                }
                left++;
            }

            if (count <= k) {
                int window_size = i - left + 1;
                max_length = max(max_length, window_size);
            }
        }

        return max_length;
    }
};
```

I want you to act as my **DSA trainer + visual debugger + personal code reference**.

My goal is to understand the code deeply enough that when I revisit this problem weeks later, I can understand every line immediately.

Do NOT rewrite my solution into another solution.

---

# PART 1 — Interactive HTML Visualizer

Create an interactive HTML page that I can open in my browser.

Show the array as boxes:

```text
[1] [1] [1] [0] [0] [0] [1] [1] [1] [1] [0]
 ↑
left
```

and:

```text
i / right
    ↓
```

Visually show:

* `left`
* `i`
* current window
* zeros inside the window
* elements outside the window
* `count`
* `k`
* `window_size`
* `max_length`

Have buttons:

* ▶ Next Step
* ⏮ Previous Step
* ▶ Auto Play
* 🔄 Reset

Each "Next Step" should perform ONE logical operation.

Do not skip important operations.

---

# PART 2 — Exact Line-by-Line Explanation

Create a permanent section called:

# LINE-BY-LINE MEMORY GUIDE

For EVERY line of my code, explain:

1. The exact line
2. What it does
3. Why we need it
4. What changes in memory/state
5. A tiny example
6. A short "remember this" sentence

For example:

### Line

```cpp
int max_length = 0;
```

### What it does

Creates a variable that stores the largest VALID window we have found so far.

### Why?

We need to remember the best answer while scanning the array.

### Example

If we previously found valid windows of sizes:

```text
3
4
6
5
```

then:

```text
max_length = 6
```

### Remember

**max_length = best valid window found so far.**

---

Do this for EVERY line, including:

```cpp
int left = 0;
```

```cpp
int count = 0;
```

```cpp
for (int i = 0; i < nums.size(); i++)
```

```cpp
if (nums[i] == 0)
```

```cpp
count++;
```

```cpp
while (count > k)
```

```cpp
if (nums[left] == 0)
```

```cpp
count--;
```

```cpp
left++;
```

```cpp
if (count <= k)
```

```cpp
int window_size = i - left + 1;
```

```cpp
max_length = max(max_length, window_size);
```

```cpp
return max_length;
```

---

# PART 3 — Make a "WHAT DOES EACH VARIABLE MEAN?" PANEL

Create a permanent visual cheat sheet:

```text
left
↓
START of current window

i
↓
END of current window

count
↓
NUMBER OF ZEROS inside current window

k
↓
MAXIMUM number of zeros we're allowed to flip

window_size
↓
SIZE OF CURRENT WINDOW
i - left + 1

max_length
↓
LARGEST VALID WINDOW FOUND SO FAR
```

Make this panel visible while using the visualizer.

---

# PART 4 — VERY IMPORTANT: CURRENT WINDOW VS BEST ANSWER

I keep confusing `window_size` and `max_length`.

Make a dedicated visual explanation.

Show:

```text
Current window:
[1][1][0][1][0]
 ↑           ↑
left         i

window_size = 5
```

Then show:

```text
Previously found best:
max_length = 7
```

Explain:

`window_size` can change every time `left` or `i` changes.

`max_length` should NEVER shrink just because the current window becomes invalid.

Show this visually.

---

# PART 5 — Explain WHY `i - left + 1`

Make an animation explaining this:

```text
left = 2
i = 5

indices:

0   1   2   3   4   5
        ↑           ↑
       left         i
```

Current window:

```text
[2] [3] [4] [5]
```

There are 4 elements.

Show:

```text
i - left
= 5 - 2
= 3
```

which is NOT the number of elements.

Then:

```text
i - left + 1
= 5 - 2 + 1
= 4
```

Explain why the `+1` is necessary.

---

# PART 6 — Explain THE WHILE LOOP VISUALLY

Focus heavily on:

```cpp
while (count > k)
```

Explain:

```text
count = zeros currently inside window

k = zeros we're allowed to have
```

Therefore:

```text
count > k
        ↓
too many zeros
        ↓
window INVALID
        ↓
shrink from LEFT
```

Show this with multiple examples.

---

# PART 7 — Explain `count--` vs `left++`

This is something I struggled with.

Explain this exact code:

```cpp
if (nums[left] == 0) {
    count--;
}

left++;
```

Show an example where:

```text
nums[left] == 0
```

and another where:

```text
nums[left] == 1
```

Make it extremely clear:

```text
0 leaves:
count--

1 leaves:
count stays the same

BUT:

whether it is 0 or 1:

left++
```

Explain WHY `left++` always happens.

Also explicitly show why this incorrect version can cause an infinite loop:

```cpp
if (nums[left] == 0) {
    count--;
    left++;
}
```

because if `nums[left] == 1`, `left` never moves.

---

# PART 8 — FULL TRACE: EXAMPLE 1

Use:

```text
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2
```

Walk through the entire algorithm.

For EVERY step show a table:

```text
i | nums[i] | left | count | current window | window size | max_length | valid?
```

Do not skip steps.

When `count > k`, show every iteration of the while loop separately.

---

# PART 9 — FULL TRACE: EXAMPLE 2

Use:

```text
nums = [0,0,1,1,0,0,1,1,1,0,1,1]
k = 2
```

Again show every step.

Highlight when:

```text
zero enters → count++
zero leaves → count--
left moves
```

---

# PART 10 — FULL TRACE: EDGE CASES

Also demonstrate:

### Example A

```text
nums = [1,1,1,1]
k = 0
```

### Example B

```text
nums = [0,0,0,1]
k = 1
```

### Example C

```text
nums = [0,1,0,1,0]
k = 0
```

Explain what happens when `k = 0`.

---

# PART 11 — CODE EXECUTION MODE

Add a section where the currently executing C++ line is highlighted.

For example:

```cpp
while (count > k) {
```

Then beside it show:

```text
CURRENT STATE

left = 2
i = 5
count = 3
k = 2

count > k
3 > 2

TRUE → execute while body
```

Then highlight:

```cpp
if (nums[left] == 0)
```

and show exactly what `nums[left]` is.

Then:

```cpp
count--;
```

Then:

```cpp
left++;
```

Then return to:

```cpp
while (count > k)
```

until it becomes false.

I want to SEE the program executing rather than just reading an explanation.

---

# PART 12 — MEMORY RULES

At the bottom create a section called:

# 5 RULES TO REMEMBER

Give me five short rules.

The most important ones should be:

1. `count` = zeros in CURRENT window.
2. `count > k` = window is INVALID.
3. When invalid, move `left`.
4. If the element leaving is `0`, decrement `count`.
5. Fix the window FIRST, then calculate its size and update `max_length`.

Also include:

```text
window_size = i - left + 1
```

---

# PART 13 — RECALL TEST

After the visual explanation, hide the explanations and give me a small quiz.

Ask things like:

"What does `count` represent?"

"What happens when nums[i] == 0?"

"When does the while loop execute?"

"If nums[left] == 1, does count decrease?"

"Does left still increase?"

"What does window_size represent?"

"Can max_length decrease?"

"Why is there a +1?"

Do NOT immediately reveal answers.

Let me answer first, then show whether I'm correct.

---

# PART 14 — IMPLEMENTATION PRACTICE

After I understand the visualization, give me a blank function:

```cpp
int longestOnes(vector<int>& nums, int k) {

}
```

Ask me to implement it myself.

Do NOT give me the complete answer unless I explicitly ask.

If I make a mistake, give me a hint first instead of the solution.

My goal is:

UNDERSTAND → VISUALIZE → RECALL → IMPLEMENT

not:

MEMORIZE → COPY.

Keep the explanations beginner-friendly and use simple visual diagrams throughout.
