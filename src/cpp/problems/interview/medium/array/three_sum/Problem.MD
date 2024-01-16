Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, 
and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set **must not** contain _duplicate triplets_.

---

### Example 1:

**Input:** *nums* = `[-1,0,1,2,-1,-4]` <br />
**Output:** `[[-1,-1,2],[-1,0,1]]` <br />

**Explanation:** <br />
```
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
```
The distinct triplets are `[-1,0,1]` and `[-1,-1,2]`. <br />
Notice that the order of the output and the order of the triplets does not matter.

---

### Example 2:

**Input:** *nums* = `[0,1,1]` <br />
**Output:** `[]` <br />

---

### Example 3:

**Input:** *nums* = `[0,0,0]` <br />
**Output:** `[[0,0,0]]` <br />

---

# Constraints:

* `3 <= nums.length <= 3000`
* -10<sup>5</sup> <= nums[i] <= 10<sup>5</sup>