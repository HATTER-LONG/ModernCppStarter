#!/bin/bash
alias gall="cmake -S all -B build -DCMAKE_CXX_COMPILER=\"/Users/layton/Desktop/WorkSpace/Tools/usr/bin/clang++\""
alias ball="cmake --build build"
alias all="gall && ball"

alias galone="cmake -S standalone -B build/standalone -DCMAKE_CXX_COMPILER=\"/Users/layton/Desktop/WorkSpace/Tools/usr/bin/clang++\""
alias balone="cmake --build build/standalone"
alias alone="galone && balone"

alias gtest="cmake -S test -B build/test -DCMAKE_CXX_COMPILER=\"/Users/layton/Desktop/WorkSpace/Tools/usr/bin/clang++\""
alias btest="cmake --build build/test"
alias rtest="CTEST_OUTPUT_ON_FAILURE=1 cmake --build build/test --target test"

alias install_format_dep="python3 -m venv .venv && source .venv/bin/activate && pip install cmake_format clang-format pyyaml"
alias gen_format="cmake -S test -B build/test -DCMAKE_CXX_COMPILER=\"/Users/layton/Desktop/WorkSpace/Tools/usr/bin/clang++\""
alias view_format="cmake --build build/test --target format"
alias apply_format="cmake --build build/test --target fix-format"
