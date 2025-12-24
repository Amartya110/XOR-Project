import subprocess
from pathlib import Path


def test_key_file_exists():
    key = Path("key.bin")
    assert key.exists(), "key.bin was not created"


def test_key_file_size():
    key = Path("key.bin")
    assert key.stat().st_size == 16, "key.bin must be exactly 16 bytes"


def test_lock_output():
    result = subprocess.run(
        ["./lock"],
        capture_output=True,
        text=True,
        check=False,
    )

    assert result.returncode == 0, "lock exited with non-zero status"
    assert result.stdout == "ACCESS GRANTED\n", "unexpected lock output"
    assert result.stderr == "", "lock should not write to stderr"
