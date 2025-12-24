# XOR Project Lock – Terminal-Bench Sample Task

This repository contains a Medium-difficulty Terminal-Bench–style CLI task.

The task requires generating a binary key file that satisfies multiple
64-bit arithmetic constraints enforced by a compiled executable.

## Structure
- `task.yaml` – task instructions and rules
- `lock.cpp` – challenge binary source
- `solution.py` – reference solution
- `run-tests.sh` – deterministic test runner
- `tests/` – strict validation tests
- `Dockerfile` – isolated execution environment

The task is deterministic, non-interactive, and designed to resist
brute-force or shortcut solutions.
