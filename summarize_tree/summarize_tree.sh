!#/usr/bin/env bash
path="$1"

num_reg=$( find . -type f | wc -l)
num_dirs=$( find . -type d | wc -l)

echo "There were" "$num_dirs" "directories."
echo "There were" "$num_reg" "regular files." 
