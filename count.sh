#!/bin/bash

# 文字列の配列を定義
strings=("sa" "sb" "ss" "pa" "pb" "ra" "rb" "rr" "rra" "rrb" "rrr")

# ファイル名
file="result.txt"

# ファイルが存在するか確認
if [[ ! -f $file ]]; then
    echo "$file not found!"
    exit 1
fi

# 各文字列の出現回数をカウント
for str in "${strings[@]}"; do
    count=$(grep -o -x "$str" "$file" | wc -l)
    echo "$str: $count"
done

# pa の後に pb が連続して出現する箇所のカウント
count_pa_pb=$(grep -A1 -x "pa" "$file" | grep -x "pb" | wc -l)
echo "pa+pb: $count_pa_pb"

# ra の後に rb が連続して出現する箇所のカウント
count_ra_rb=$(grep -A1 -x "ra" "$file" | grep -x "rb" | wc -l)
echo "ra+rb: $count_ra_rb"
