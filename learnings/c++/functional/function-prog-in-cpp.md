### Functional Programming

> Functional programming is a style of programming that emphasizes the evaluation of expressions, rather than execution of commands. The expressions in these languages are formed by using functions to combine basic values. A functional language is a language that supports and encourages programming in a functional style.

- FP is a style of programming in which the main program building blocks are functions as opposed to objects and procedures. A program written in the functional style doesn’t specify the commands that should be performed to achieve the result, but rather defines what the result is.
  - Consider a small example: calculating the sum of a list of numbers. In the imperative world, we implement this by iterating over the list and adding the numbers to the accumulator variable. We explain the step-by-step process of how to sum a list of numbers.
  - On the other hand, in the functional style, we need to define only what a sum of a list of numbers is. The computer knows what to do when it’s required to calculate a sum. One way we can do this is to say that the sum of a list of numbers equals the first element of the list added to the sum of the rest of the list, and that the sum is zero if the list is empty. We define what the sum is without explaining how to calculate it.
- **Imperative** means we command the computer to do something by explicitly stating each step it needs to perform in order to calculate the result. **Declarative** means we state what should be done, and the programming language has the task of figuring out how to do it. We define what a sum of a list of numbers is, and the language uses that definition to calculate the sum of a given list of numbers.
- The object-oriented paradigm is based on creating abstractions for data. It allows the programmer to hide the inner representation inside an object and provide only a view of it to the rest of the world via the object’s API. The FP style creates abstractions on the functions. This lets us create more-complex control structures than the underlying language provides.

**WAP:** that takes a list of files and calculates the number of lines in each.

1. Imperatively: Open each file, Define a counter to store the number of lines, Read the file one character at a time, and increase the counter every time the newline character (\n) occurs. At the end of a file, store the number of lines calculated.

```c++
std::vector<int> count_lines_in_files(const std:vector<std::string>& files){
  std::vector<int> results;
  char c = 0;

  for(const auto& file: files){
    int line_count = 0;
    std::ifstream in(file);
    while(in.get(c)) {
      if(c == '\n') line_count++;
    }
    results.push_back(line_count);
  }
  return results;
}
```

2. C++ provides convenient abstractions such as stream iterators that allow you to treat the I/O streams similarly to ordinary collections like lists and vectors.

```cpp
int count_lines(const std::string& filename){
  std::ifstream in(filename);

  return std::count(
    std::istreambuf_iterator<char>(in),
    std::istreambuf_iterator<char>(),
    '\n'
  ); //counts newlines from the current position in the stream until the end of the file
}

std::vector<int> count_lines_in_files(const std::vector<std::string>& files){
  std::vector<int> results;
  for(const auto& file: files){
    results.push_back(count_lines(file)); //Saves the result
  }
}

```

With this solution, we’re no longer concerned about exactly how the counting is implemented; we’re just declaring that we want to count the number of newlines that appear in the given input stream. This is always the main idea when writing programs in the functional style—_use abstractions that let you define the intent instead of specifying how to do something_.

`std::transform` traverses the items in the files collection one by one, transforms them using the `count_lines` function, and stores the resulting values in the results vector.

```cpp
std::vector<int> count_lines_in_files(const std::vector<std::string>& files){
    std::vector<int> results(files.size());
    std::transform(
      files.cbegin(),
      files.cend(), //Specifies which items to transform
      results.begin(), //Where to store the results
      count_lines //Transformation function
    );
    return results;
}
```
