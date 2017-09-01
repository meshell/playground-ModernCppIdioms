# Init Statements for if/switch

In the previous exercise you probably had the problem, that you had to rename
some variables or had to put it in a different scope to
have ___const correctness___. E.g
```
{
  const auto it = address_book.find("Hans");
  if (it != address_book.end()) {
      std::cout << "Hans is in address book\n";
  }
}
{
  const auto it = address_book.find("Peter");
  if (it != address_book.end()) {
      std::cout << "Peter is in address book\n";
  }
}   
```

With C++17 there are new versions of the if and switch statements for C++: `if (init; condition)` and `switch (init; condition)`.

The new if statement will make that additional scope in the example above in one line:  
```
if (const auto it = address_book.find("Hans"); it != address_book.end()) {
    std::cout << "Hans is in address book\n";

if (const auto it = address_book.find("Peter"); it != address_book.end()) {
    std::cout << "Peter is in address book\n";
}
```

## DIY

@[Refactor the code and use the new if form to reduce the scope of the constants]({"stubs": ["src/Exercises/init_statements.cpp"],"command": "sh /project/target/check_structured_bindings.sh"})
