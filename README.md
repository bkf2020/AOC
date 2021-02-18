# AOC
This is my code for Advent of Code (for all the years that I work on the problems). No written solutions on a wiki for the time being. Each year has a folder with the year number. The source code for each day is in a folder called `day#`. Each day has two files, `day#part1.cpp` and `day#part2.cpp`. Note `.cpp` might be a different extension if I choose to use another language.

Advent of Code is available at [https://adventofcode.com.](https://adventofcode.com/)

I may not be able to solve all the problems, and may not be able to finish all the problems. I may not do a problem each day, by the way...

# Running these solutions (C++: `.cpp` extension)
- Use the `g++` complier: `g++ solution.cpp -o solution` (for UNIX systems, e.g.: Linux, MacOS, OpenBSD) or `g++ solution.cpp -o solution.exe` (for Windows, make sure to install mingw)
	- You can also use other compliers, since solutions don't use `#include <bits/stdc++.h>` anymore
- Replace `solution.cpp` with `day#part#.cpp` (e.g.: `day1part1.cpp`)
- Feel free to replace `solution` or `solution.exe` with your preferred name for the executable.
- Run with `./solution < inputfile.in` or `solution.exe <inputfile.in` (use this with CMD on Windows)
	- Replace `inputfile.in` with `day#.in`, like `day1.in`
	- **NOTE:** You will have to create your own input files. To do this, get the input on the Advent of Code website for your account. Also, the extension for such a file does not have to be `.in`.

# Running these solutions (python: `.py` extension)
- Type `python filename.py` where `filename.py` is the solution file
	- OR: Use `pypy` or `python3` (or your preferred way of running Python files)
- Note you will need to have the input file in the same directory as the solution file
- The input file in the python program will be `day#.in`. Change this if your input file name is different

# Updates for each year
- In the folder for each year, there is a `Updates.md` file.

# Walkthroughs?
- I will try to include a walkthrough file for some days. It will be called `Walkthroughs.md` in the folder for the year. You can also view these walkthroughs on the project's wiki, if you prefer that.
