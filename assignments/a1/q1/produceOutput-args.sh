#!/bin/bash
# Usage: ./produceOutput.sh <folder> <executable>
# Runs <executable> on each .in file in <folder>, redirecting stdin from
# the .in file and stdout to a matching .out file (t1.in -> t1.out).
# If a matching t1.args file exists, its contents are passed as
# command-line arguments to the executable.

set -uo pipefail

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <folder_with_in_files> <executable>" >&2
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

for in_file in "${in_files[@]}"; do
    testname=$(basename "$in_file" .in)
    out_file="$folder/${testname}.out"
    args_file="$folder/${testname}.args"

    args=()
    if [ -f "$args_file" ]; then
        # Word-split the file's contents into separate arguments.
        read -r -a args < "$args_file"
    fi

    echo "Running $executable ${args[*]} < $in_file > $out_file"
    "$executable" "${args[@]}" < "$in_file" > "$out_file"
done

echo "Done. Processed ${#in_files[@]} file(s)."
