## 11.feature分支
每添加一个新功能，最好新建一个feature_name分支，在上面开发，完成后，合并，最后删除该
feature分支
合并后删除 git branch -d feature_name
不合并强制删除 -D


## 10.Bug分支
当master中的bug修正了，而dev中的分支还未修正，该怎么办呢
1)那就是手动找，然后对照着master来改，但是bug一多就很麻烦
2)..先把master合并到dev，如果有冲突，先修改冲突（直接改成master样子不用保存<<<===>>>），再合并（ff即可）。然后继续开发。并不急着再把dev合并到master
实践出真知，试试才知道
在dev已经add commit完之后，git merge master 会自动写成<=>形式来帮你找位置改成一样的再merge
(master dev 是要同步的，所以每台机子上的最终结果应该是一样的)


修复bug，先git stash保存工作现场，然后建立新的bug分支修复bug，修完后合并，no-ff删除，再回来git stash apply stash@{0}恢复现场继续工作

## 9.解决冲突


## 8.分支branch
	~$ git checkout -b dev
	~$ git branch dev
	~$ git checkout dev

blablabla...

	~$ git checkout master
	~$ git merge dev
	~$ git branch -d dev
保持master主线清晰

## 7.远程仓库
	~$ git push origin master
	~$ git clone <address>


## 6.删除
	~$ rm test.txt

	~$ git rm test.txt
	~$ git checkout -- readme.txt
	

## 5.撤销修改
	~$ 1).before add  
	
	~$ git checkout -- readme.txt

	2).before commit
	~$ git reset HEAD readme.txt
	~$ git checkout -- readme.txt

	3).after commit
	~$ git reset --hard commit_id


## 4.
	~$ git log --pretty=oneline

	~$ git reset --hard HEAD^
	~$ git reset --hard commit_id
	~$ git reflog


## 3.
	~$ git diff HEAD -- readme.txt

使用帮助

	~$ git help commit

## 2.
	~$ mkdir learngit
	~$ cd learngit
	~$ pwd
初始化  
	
	~$ git init

	~$ git add readme.txt
	~$ git commit -m 'write a readme.txt'
	~$ git status

## 1. 故事
	1991 Linus Linux
	2005 Git Linux社区