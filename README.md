# Git repo for my vs code project trials

### Renaming master to main
https://stevenmortimer.com/5-steps-to-change-github-default-branch-from-master-to-main/

```
git branch -m master main
git push -u origin main
git symbolic-ref refs/remotes/origin/HEAD refs/remotes/origin/main
```
