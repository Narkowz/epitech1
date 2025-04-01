#!/bin/bash

# Switch to the main branch and pull latest changes
git checkout main
git pull origin main

# Loop through all branches except for main
for branch in $(git branch --format='%(refname:short)' | grep -v "main"); do
  # Switch to the branch
  git checkout $branch

  # Merge changes from main
  git push
  git merge main
done
