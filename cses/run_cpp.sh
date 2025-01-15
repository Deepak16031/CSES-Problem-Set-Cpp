#!/bin/bash
clang++ -Wall -Wextra -std=c++17 -stdlib=libc++ -o program "$1" && ./program
