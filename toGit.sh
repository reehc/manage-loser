#! /bin/bash

# Add file or directory to Github every FAST!

GIT_DIR=~/cheerspace/withUnix/
PWD=$(pwd)

if [ $# -ne 2 ]
then
	echo toGit [source] [commit]
	exit 7
fi

cp $1 $GIT_DIR &&
cd $GIT_DIR &&

echo "ok, let's do it !" &&

if [ "$(git pull)" != "Already up-to-date." ]
then
	echo "Git repo is out-of-date!"
	exit 8
fi &&

echo "Git Repo is newest!" &&

echo "to git..." &&

git add * &> /dev/null &&
git commit -m "$2" &> /dev/null &&
git push origin master &> /dev/null &&

echo "Good Job!" &&

cd $PWD
