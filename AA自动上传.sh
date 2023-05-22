#!/bin/bash

# 获取 commit message 参数
commit_msg="$1"

# 执行 git add .
git add .

# 执行 git commit -m [参数]
if [ -z "$commit_msg" ]; then
  echo "请提供 commit message 参数"
else
  git commit -m "$commit_msg"
fi

# 执行 git push
git push