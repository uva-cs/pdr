#!/bin/sh

make all

# Frankly, we don't care about file mode changes
git config core.filemode false

git add --all
staged_lines=`git diff --cached --numstat | wc -l`
if [ "$staged_lines" -eq "0" ]; then
    exit 0
fi

git config user.name "Github Actions"
git config user.email "actions@github.com"

git commit -m "Post-process files"

git push "https://${GITHUB_ACTOR}:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY}" HEAD:master
