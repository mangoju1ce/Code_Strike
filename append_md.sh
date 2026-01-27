#!/usr/bin/env bash

SRC="cur.md"
DST="list.md"

# 安全检查
if [ ! -f "$SRC" ]; then
  echo "❌ 源文件 $SRC 不存在"
  exit 1
fi

if [ ! -f "$DST" ]; then
  echo "❌ 目标文件 $DST 不存在"
  exit 1
fi

echo -e "\n" >> "$DST"

# 核心处理：标题升一级
sed 's/^#/##/' "$SRC" >> "$DST"

echo "✅ 已将 $SRC 处理并追加到 $DST"
