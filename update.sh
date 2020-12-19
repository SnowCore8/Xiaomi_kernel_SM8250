# 尝试运行
git checkout --orphan latest_branch
# 添加所有文件
git add -A
# 提交更改
git commit -am "message"
# 删除分支
git branch -D master
# 将当前分支重命名
git branch -m master
# 最后，强制更新存储库
git push -f origin master