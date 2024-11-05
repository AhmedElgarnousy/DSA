### Selection Sort

- Selection sort is another simple but slow approach
- It is based on a simple observation
  - The first element in the sorted array is the minimum in the whole array
  - The second element in the sorted array is the second minimum in the whole array
  - And so on
  - Can you sketch the whole idea?

### The procedure

- Keep repeating:
  - Find the minimum in the (reminder of the) array
  - Make it the first (or the next) element

![selection](../../imgs/selection-sort.png)

### O(n^2^) time and O(1) memory

```cpp
//  9,85,10,0,5,3,9,0,2
void selection_sort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        int mn_idx = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[mn_idx])
                mn_idx = j;

        // Put the min in its right place
        swap(nums[mn_idx], nums[i]);
    }
}
```

### Worst vs Best analysis

- We can see how the algorithm doesn’t depend on its number of operations based on the data
- This makes its best, average and worst case complexity the same
- So keep this general property in your mind: To what degree do the data values themselves affect the total number of operations?

### Correctness

- Similar to insertion sort, it is trivial to see weather the algorithm is correct
- Don’t waste time on (in)formal proofs for trivial algorithms

### Selection Sort vs Heap Sort

- During a data-structure course, we study min/max heap data-structure which
  can be used in sorting values ⇒ Heap Sort
- Heapsort is similar to selection sort: it locates the largest value and places it
  in the final array position. Then it locates the next largest value and places it
  in the next-to-last array position and so forth.
  - This is similar to the selection sort process where we find the smallest and place it in the first
    array position (the opposite). - Selection sort takes O(n) to locate the smallest. - Heap sort locates the minimum in O(1) but takes O(logn) to remove it ⇒ O(nlogn)
- If you did not study the heap data structure so far, review this slide later
