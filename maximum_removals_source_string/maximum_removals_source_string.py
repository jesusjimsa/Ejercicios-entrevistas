"""
You are given a string `source` of size `n`, a string `pattern` that is a subsequence of `source`, and a **sorted**
integer array `targetIndices` that contains **distinct** numbers in the range `[0, n - 1]`.

We define an **operation** as removing a character at an index `idx` from `source` such that:

* `idx` is an element of `targetIndices`.
* `pattern` remains a subsequence of `source` after removing the character.

Performing an operation **does not** change the indices of the other characters in `source`. For example, if you remove
`'c'` from `"acb"`, the character at index 2 would still be `'b'`.

Return the **maximum** number of *operations* that can be performed.

## Example 1:

```
Input: source = "abbaa", pattern = "aba", targetIndices = [0,1,2]

Output: 1

Explanation:

We can't remove source[0] but we can do either of these two operations:

Remove source[1], so that source becomes "a_baa".
Remove source[2], so that source becomes "ab_aa".
```

## Example 2:

```
Input: source = "bcda", pattern = "d", targetIndices = [0,3]

Output: 2

Explanation:

We can remove source[0] and source[3] in two operations.
```

## Example 3:

```
Input: source = "dda", pattern = "dda", targetIndices = [0,1,2]

Output: 0

Explanation:

We can't remove any character from source.
```

## Example 4:

```
Input: source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4]

Output: 2

Explanation:

We can remove source[2] and source[3] in two operations.
```

## Constraints:

* `1 <= n == source.length <= 3 * 10^3`
* `1 <= pattern.length <= n`
* `1 <= targetIndices.length <= n`
* `targetIndices` is sorted in ascending order.
* The input is generated such that `targetIndices` contains distinct elements in the range `[0, n - 1]`.
* `source` and `pattern` consist only of lowercase English letters.
* The input is generated such that `pattern` appears as a subsequence in `source`.
"""

from typing import List


class Solution:
    """
    A class providing methods to remove characters from a source string
    while maintaining a specific pattern.
    """
    def maxRemovals(self, source: str, pattern: str, targetIndices: List[int]) -> int:
        """
        Calculate the maximum number of removals while preserving the pattern.

        Args:
            source (str): The original source string.
            pattern (str): The pattern to be preserved.
            targetIndices (List[int]): Indices of characters that can be removed.

        Returns:
            int: Maximum number of characters that can be removed while
                 keeping the pattern intact.
        """
        result = 0

        for idx in targetIndices:
            local_source = source[:idx] + '_' + source[idx+1:]

            if pattern in local_source.replace('_', ''):
                result += 1
                source = local_source

        return result

sol = Solution()
listilla = [0, 1, 2]
print(sol.maxRemovals(source="abbaa", pattern="aba", targetIndices=listilla))

listilla = [0, 3]
print(sol.maxRemovals(source="bcda", pattern="d", targetIndices=listilla))

listilla = [0, 1, 2]
print(sol.maxRemovals(source="dda", pattern="dda", targetIndices=listilla))

listilla = [0, 2, 3, 4]
print(sol.maxRemovals(source="yeyeykyded", pattern="yeyyd", targetIndices=listilla))
