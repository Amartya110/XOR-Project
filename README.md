# XOR Project Lock – Terminal-Bench Sample Task

This repository contains a Terminal-Bench–style CLI task designed to evaluate
multi-step reasoning and deterministic problem solving in an isolated
command-line environment.

The task requires generating a binary key file that satisfies multiple
64-bit arithmetic constraints enforced by a compiled executable. Brute-force
approaches are infeasible, and correct solutions must reason about the
constraints to construct a valid key.

## Project Structure

- `task.yaml` – Task instructions, rules, and success criteria
- `lock.cpp` – Source for the challenge binary
- `solution.sh` – Reference solution entrypoint (oracle)
- `solution.py` – Deterministic reference implementation
- `run-tests.sh` – End-to-end test runner
- `tests/` – Strict validation tests
- `Dockerfile` – Isolated execution environment
- `dockercompose.yaml` – Container orchestration for task execution

## Notes

- The task is deterministic and non-interactive
- All components run inside a Docker container
- The test suite enforces exact output and behavior
- The task is designed to resist shortcut or brute-force solutions
