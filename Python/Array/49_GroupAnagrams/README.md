# Group Anagrams

```python
from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for i in strs:
            res[''.join(sorted(i))].append(i)
        return list(res.values())
```

The solution is trivial, but here are some useful notes for Python.

* The difference bitween `dict` and `collections.defaultdict(list)`

  * If the key is not in `dict`, it will panic.

  * If the key is not in `collections.defaultdict`, it will return a default type.

    ```python
    d1 = dict()
    d2 = defaultdict(list)
    d3 = defaultdict(int)
    
    print(d1['a'])  # Error!
    print(d2['a'])  # []
    print(d3['a'])  # 0
    ```

* Function `sorted()`:

  * `sort()` is a method for `list`.
  * `sorted(iterable, cmp=None, key=None, reverse=False)`
  * `sorted()` is a funtion for iterable object.
  * It will return a list.

* Function `''.join()`:

  * `str.join(sequence)`
  * Create a new str.
  * If the element in the list is interger, then we should convert it into str:
    * `''.join([str(i) for i in list])`

* The difference bitween `list` and `list`:

  * `list` is mutable, but `tuple` is immutable.
  * `dict` key's type must be immutable, so it can't be `list`, but can be `tuple`.
  * Both `res[''.join(sorted(i))].append(i)` and `res[tuple(sorted(i))].append(i)` make sense.

* Convert `dict` key into `list`: `list(res.keys())`.

* Convert `dict` value into `list`: `list(res.values())`.