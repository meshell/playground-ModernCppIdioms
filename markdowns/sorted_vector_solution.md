# Keep std::vector sorted
## Possible solution

```C++
template<typename Cont, typename T>
void insert_sorted(Cont& container, const T& item) {
    const auto insert_pos = std::lower_bound(std::begin(container), std::end(container),item);
    container.insert(insert_pos, item);
};
```
