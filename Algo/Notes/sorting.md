## sorting

### The Sorting problem

- Given an array of numbers, order them from small to large

  - Input: [9,2, 10, 0, 5, 3, 90, 85]
  - Output: [0, 2, 3, 5, 9, 10, 85, 90]
  - Observe: A[i] <= A[i+1]
  - Observe: If A <= B and B <= C, then A <= C (`transitivity`)

- **Why Sorting**?
  - It makes many computational problems easier to solve
  - Many applications involve sorting items
    - The LeetCode website allows ordering the tasks based on “acceptance ratio”

##### About elements order

- 1, 2, 3, 4, 5, 6
  - This is an `increasing sequence`. Sometimes we use the term `strictly increasing`
- 1, 2, 3, 3, 3, 4, 5, 6, 6
  - This is `not strictly increasing`, as we have duplicates
  - We call it a non-decreasing sequence
- Similarly decreasing and non-increasing concepts
  - 6, 5, 4, 3, 2, 1 is a decreasing sequence
  - 6, 6, 6, 4, 3, 3, 3, 2, 1 is a non-increasing sequence
  - What about: 9, 2, 10, 0, 5, 3, 90, 85? Not ordered
- `Ascending order` means order (numbers/words) from smallest to largest from
  left to right.
- `Descending` order means order from `largest` to `smallest`.

#### Sorting Algorithms

![sorting-algos](../../imgs/sorting-algos.JPG)

- There are many sorting algorithms!
- **simple but inefficient**: `Insertion`, `Selection`, `Bubble`
  - O(n^2) algorithms
- **Efficient**: `Merge Sort`, `QuickSort`, `HeapSort`
  - Heap Sort based on the heap DS
  - O(nLogn) algorithms. log n = log~2~n
    - log~2~(265) = 8, log~2~(4,294,967,296) = 32
- **Distribution-based techniques**: `counting sort`, `bucket sort`, `Radix sort`
  - what if all the values are in the range [0, 100]

#### Incremental Thinking

- Insertion sort is based on a simple and effective thinking technique
- You think this way
  - assume, we know the answer for the first N-1 elements
  - how can we update it for N?
- if the previous question is applicable, we can apply it simply by starting from the first element in the array
  - as first element is the base case
  - with each new element, the solution builds upon the solution found by all the previous elements

### Incremental Thinking: Let’s Apply It

- Given the array [9, 2, 10, 0, 5, 3, 90, 85], where N = 8. How to sort the array?!
- Q1) What is the sorting answer for the first N-1 elements?
- The first 7 values are [9, 2, 10, 0, 5, 3, 90].
- Sorting them gives [0, 2, 3, 5, 9, 10, 90]
- Q2) How can we update the sorted array, but also include the value 85?
- Simply iterate from the end of the array and find the first element, where 85 is
  <= to it. In our case it is 90. Put it before it ⇒ [0, 2, 3, 5, 9, 10, 85, 90]
- Then?
- Now start from the 2nd element, and for each number put in its right place
  with the previous M-1 numbers!
- Done!

![alt](../../imgs/insert-sort.png)

#### How to Code?

```cpp
void insertion_sort(vector<int> &nums)
{
    // for each number: add it in the previous sorted subarray
    for (int i = 0; i < (int)nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;
        // shift and add in the right location
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key; // the first right element
    }
}
```

### How to test?

- Think in a systematic way about possible cases
- Here are general thoughts that may help in different cases for arrays
  Length: 1, 2, 3, and the max N
- Boundaries can be tested with the smallest N and the largest N
- Values:
  - Odd and even
  - Duplicate arrays or unique values
  - Sorted, Almost sorted, not ordered (partially, completely)
- In this problem what matters:
  - Length: 1 and N. Test a random array. Test some arrays with duplicate values

### Some observations

- Assume the array is (almost) sorted: e.g. 1, 2, 3, 4, 5, 6, 7
  - What is the time complexity?
- Clearly, the 2nd nested loop will never work. So we are actually O(n)
  - This is called the Best-case performance (behavior under optimal conditions)
- What if the array is already ordered from large to small? E.g. 7, 6, 5, 4, 3, 2, 1
- Clearly, the 2nd nested loop is applied to the last index. This is O(n^2).
  - This is called the Worst-case performance
- The average case is O(n^2)
  - The second loop is applied (partially or fully) most of the time

### Worst vs Best analysis

- Many algorithms with bad worst-case performance have good average-case performance
  - If this is the case, most of the time your code will be pretty fast except for a few cases!
- Some data structures like hash tables have very poor worst-case behaviors,
  but a well written hash table of sufficient size will never give the worst case
  - That is: A good implementation + proper usage.
- Take-home message: Don’t be systematic when computing/using such types
  of analysis. In practice, we might need to think deeper about what the typical
  inputs are and the effect of that on the problem of interest

#### Correctness

- We must prove the correctness of our approach too
- Many books go very formal for a few pages explaining the proof.
  - Reading lengthy proofs can be exhausting to many people unless you have a good
    mathematical background
  - Understanding proofs is still a very added value. It teaches you to make sure your logic covers
    the possible scenarios
  - You need to read formal proofs to be able to write one, if you are interested
- One such book is Introduction to Algorithms (CLRS) by Cormen et al.
  - I learned from it. It focuses on the theory and is very mathematical but a great book
- There are other books which focus more on the practical side, such as
  Algorithms Design Manual by Steven Skiena

- I suggest a flow that will make your progress faster and much more
  productive - First, focus a lot on the intuition behind the approach
- Strong algorithmist can find solutions for very hard problems in a few minutes
- Understand the code. Think in test cases. Build informal thoughts about correctness
- Solve several exercises about the algorithm
- Optional: Check out the proof.

  - But, at the very least, please find and read the proofs for a few of them

- Insertion sort: Informal proof
  - I hope you can trivially see why it is a correct algorithm
  - At n = 1, the initial sub-array of A[0] is sorted
  - Then from n = 2, covering all the elements. We search linearly to find the correct location
    - Then we shift its right subarray, where all the shifted values are > current key
    - This means: after the ith step, the extended subarray is sorted

#### Insertion Algorithm Properties

- Sorting algorithms have interesting properties to understand
- Adaptive, i.e., efficient for data sets that are already substantially sorted
  - The time complexity is O(kn) when each element in the input is no more than k places away from its sorted position. If the whole list is already sorted, then k = 1
- Stable; i.e., does not change the relative order of elements with equal keys
  - Assume input [1, 2, 5A, 5B, 3, 5C]. [A,B,C just tags]
  - When we sort it: [1, 2, 3, 5A, 5B, 5C]. Equal keys have the SAME old order
- In-place; i.e., only requires a constant amount O(1) of additional memory
  space.
  - As you see, we were updating the given vector itself
- Online; i.e., can sort a list as it receives it
  - Imagine an online service that keeps receiving numbers and sort all what we have so far

### Comparison based algorithms

- As you notice, this algorithm, and many others, compares numbers together
  to find out the right output
  - We will meet other efficient comparison-based algorithms
    - E.g. Merge sort is only O(n logn)
- We will also learn other types of algorithms that are not based on
  comparisons (e.g. Count sort)
- An interesting fact to know: any comparison-based sorting algorithm must
  make [at least (n Log~2~n) comparisons](https://en.wikipedia.org/wiki/Comparison_sort) on average to sort the input array
  - So never try to find something better :)
  - That is: Sometimes we compute the lower-bound complexity for an algorithm
- Sorting is the most thoroughly studied problem in computer science.
