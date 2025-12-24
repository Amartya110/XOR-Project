set -euo pipefail

rm -f key.bin

python3 solution.py

output="$(./lock)"

if [[ "$output" != "ACCESS GRANTED" ]]; then
  echo "Test failed: unexpected output"
  exit 1
fi
