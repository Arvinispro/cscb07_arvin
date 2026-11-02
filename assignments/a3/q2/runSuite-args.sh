#!/bin/bash
# Usage: ./runsuite.sh <folder_with_in_and_out_files> <executable>
# Runs <executable> on each .in file, redirecting stdin from the .in file
# and stdout to a matching .actual file, then compares .actual against the
# corresponding stored .out file, reporting pass/fail per test.
# If a matching <testname>.args file exists, its contents are passed as
# command-line arguments to the executable.

set -uo pipefail

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <folder_with_in_and_out_files> <executable>" >&2
    exit 1
fi

folder="$1"
executable="$2"

if [ ! -d "$folder" ]; then
    echo "Error: '$folder' is not a valid directory." >&2
    exit 1
fi

if [ ! -x "$executable" ]; then
    echo "Error: '$executable' is not an executable file." >&2
    exit 1
fi

shopt -s nullglob
in_files=("$folder"/*.in)

if [ "${#in_files[@]}" -eq 0 ]; then
    echo "No .in files found in '$folder'." >&2
    exit 0
fi

pass_count=0
fail_count=0

for in_file in "${in_files[@]}"; do
    testname=$(basename "$in_file" .in)
    out_file="$folder/${testname}.out"
    actual_file="$folder/${testname}.actual"
    args_file="$folder/${testname}.args"

    if [ ! -f "$out_file" ]; then
        echo "Warning: expected output file '$out_file' not found, skipping '$testname'." >&2
        continue
    fi

    args=()
    if [ -f "$args_file" ]; then
        read -r -a args < "$args_file"
    fi

    "$executable" "${args[@]}" < "$in_file" > "$actual_file"

    if diff -q "$out_file" "$actual_file" > /dev/null 2>&1; then
        echo "${testname} passed!"
        pass_count=$((pass_count + 1))
    else
        echo "${testname} failed!"
        diff --label expected --label actual -u "$out_file" "$actual_file"
        fail_count=$((fail_count + 1))
    fi
done

echo ""
echo "Summary: ${pass_count} passed, ${fail_count} failed."
