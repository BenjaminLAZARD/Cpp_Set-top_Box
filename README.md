# inf224
INF224 course: programming paradigms 2016-2017.
It is a home-made multimedia set-top box software, entirely in C++.

Address of the web-content : [https://github.com/BenjaminLAZARD/Cpp_Set-top_Box](https://github.com/BenjaminLAZARD/Cpp_Set-top_Box)

File destinated to the teacher : **README_Teacher.md**

## Content of the github
Online hub only contains source files required to make executables.
**.GitIgnored** is commented if you whish to know which files are skipped.

## Good to know
User must have a C++ compiler as g++ and run the **Makefile**.
Documentation will be obtained running **Doxyfile**.

So as for myself, under Windows, I used:
+ [Mingw64](https://sourceforge.net/projects/mingw-w64/) and used the GUI to install basic **Mingw**, and **MSYS** configurations (C/C++ compilers, makefile support,etc.).
+ [Eclipse CDT](https://eclipse.org/cdt/) module as a functional add-on to Eclipse IDE to code, debug, build and run the C/c++ project. (until I ran into trouble with *shared_ptr*).
+ [Doxygen wizard](http://www.stack.nl/~dimitri/doxygen/) to generate an HTML documentation directly from the code.
+ [Smart Git](http://www.syntevo.com/smartgit/) to work from home on the Github repository.

Strange comments in the sources allow Doxygen to work.

Mingw64 offers both support for g++ compiler, and enable a Windows user to generate the *.exe* files with the sole command
`mingw64-make run` instead of `make run` under Linux.

But although I tested this options, *Eclipse* correctly parametered, allows for a full build and run with `CTRL + F11` (except for my problem with *shared_ptr* ).
