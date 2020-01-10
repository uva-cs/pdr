#!/bin/sh

make all

git add --all
staged_lines=`git diff --cached --numstat | wc -l`
if [ "$staged_lines "-eq "0" ]; then
    exit 0
fi

git config --global user.name "Github Actions"

git commit -m "Post-process files"

git push https://${GITHUB_ACTOR}:${GITHUB_TOKEN}@github.com/${GITHUB_REPOSITORY} HEAD:master
