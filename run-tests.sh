#!/usr/bin/env bash
set -euo pipefail

./solution.sh
pytest -q
