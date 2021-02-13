# AOC
This is my code for Advent of Code (for all the years that I work on the problems). No written solutions on a wiki for the time being. Each year has a folder with the year number. The source code for each day is in a folder called `day#`. Each day has two files, `day#part1.cpp` and `day#part2.cpp`. Note `.cpp` might be a different extension if I choose to use another language.

Advent of Code is available at [https://adventofcode.com.](https://adventofcode.com/)

# Other notes
- I may not be able to solve all the problems, and may not be able to finish all the problems. I may not do a problem each day, by the way...
- Problem 9 part 2 uses a brute force solution, which may be slower on older computers... Realized from [here](https://github.com/mebeim/aoc/blob/master/2020/README.md#day-9---encoding-error) that a better solution would be to use binary search to find the two places the subarray starts and ends, and then loop through that subarray for the minimum and maximum values.

# Running these solutions (cpp)
- Use the `g++` complier: `g++ solution.cpp -o solution` (for UNIX systems, e.g.: Linux, MacOS, OpenBSD) or `g++ solution.cpp -o solution.exe` (for Windows, make sure to install mingw)
- You can also use other compliers, since solutions don't use `#include <bits/stdc++.h>` anymore
- Replace `solution.cpp` with `day#part#.cpp` (e.g.: `day1part1.cpp`)
- Feel free to replace `solution` or `solution.exe` with your preferred name for the executable.
- Run with `./solution < inputfile.in` or `solution.exe <inputfile.in` (use this with CMD on Windows)
- Replace `inputfile.in` with `day#.in`, like `day1.in`
- **NOTE:** You will have to create your own input files. To do this, get the input on the Advent of Code website for your account. Also, the extension for such a file does not have to be `.in`.

# Updates
- Completed day 4 (2020) solution! (Quite messy though)
- Rewriting solutions without `#include <bits/stdc++.h>`
- Removing binary files (you can always make them with a complier :)
- Removing input files as they are different from everyone
