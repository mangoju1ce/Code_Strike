#!/bin/bash

echo "====== Sorting Algorithm Performance Test ======"

# 读取 input.txt 第一行作为 n
n=$(head -n 1 input.txt)
echo "Data Size: n = $n"
echo "-----------------------------------------------"

run_test () {
    name=$1
    exe=$2
    printf "%-35s" "$name"
    
    start=$(date +%s%N)   # 开始时间（纳秒）
    ./$exe < input.txt > /dev/null
    end=$(date +%s%N)     # 结束时间（纳秒）

    elapsed=$(( (end - start) / 1000000 ))  # 转成毫秒
    echo "${elapsed} ms"
}

echo -e "\nO(n^2):"
run_test "Bubble Sort" bubbleSort
run_test "Selection Sort" selectionSort
run_test "Insertion Sort" insertSort

echo -e "\nO(n log n):"
run_test "Quick Sort (first pivot)" quickSort
run_test "Three-Way Quick Sort (random pivot)" ThreeWay_quickSort
run_test "Merge Sort" mergeSort

echo -e "\nOther:"
run_test "Base Sort" baseSort
run_test "Shell Sort" shellSort

echo -e "\ncpp:"
run_test "algoritm.sort" sort
echo "================================================"
