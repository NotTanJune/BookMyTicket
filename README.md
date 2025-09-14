# BookMyTicket

A small console-based movie ticket listing/management demo written in C++. This was a project that I made with the help of my classmate [Lisa](https://github.com/lisa761) , for our 12th grade final project. It is fun to see how basic this is and how my code has evolved over the years. Also, this was built and written for Turbo C++, so a lot of the design choices were limited by the technology of our time. 

You are free to give it a try, the instructions for executing it are given below. Make sure to download the .dat files if you want a demo version, if not, the code will create it's own during runtime.

## Overview
- Reads movie details from data files (movie.dat, movie1.dat).
- Displays each record with simple paging and shows position as "x of y".
- Basic fields: Movie name, Language, Genre, Format, Lead Actor, Lead Actress.
- Navigation: N (Next), P (Previous), Q (Quit).

## Prerequisites
- macOS/Linux: g++ with C++17 support.
- Windows (either option):
  - Visual Studio 2022 Build Tools (MSVC), or
  - MSYS2 MinGW-w64 (g++).

## Build
You can use the existing VS Code task or compile directly:

```bash
# Using the task (recommended):
# In VS Code: Run Task → Rebuild PROJECTZ.CPP
# (On Windows with MinGW, this produces bookmyticket.exe)
```

macOS/Linux (g++):
```bash
g++ -std=c++17 PROJECTZ.CPP -o bookmyticket
```

Windows — MSVC (Developer Command Prompt):
```bat
cl /std:c++17 PROJECTZ.CPP /Fe:bookmyticket.exe
```

Windows — MSYS2/MinGW:
```bash
g++ -std=c++17 PROJECTZ.CPP -o bookmyticket.exe
```

## Run
macOS/Linux:
```bash
./bookmyticket
```

Windows:
```bat
.\bookmyticket.exe
```

> Note: The app clears the screen using the appropriate command for your OS (cls on Windows, clear on macOS/Linux). No extra configuration is needed.
