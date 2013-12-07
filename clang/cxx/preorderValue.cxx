/*
 * preorderValue.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * // find the fixed sum of a tree path
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;	
};

void findpath(BinaryTreeNode *root, int sum, vector<int> path,int currentSUM);


void findpath(BinaryTreeNode *root, int sum)
{
	int currentSUM = 0;
	vector<int> path;
	
	if(root == NULL) return;
	findpath(root,sum,path,currentSUM);
}

void findpath(BinaryTreeNode *root, int sum, vector<int> path,int currentSUM)
{
	path.push_back(root->value);
	currentSUM += root->value;
	
	bool isLeaf = root->left ==NULL && root->right == NULL;
	if(currentSUM == sum && isLeaf)
	{
		cout << "a path is :";
		vector<int>::iterator iter = path.begin();
		for(;iter!= path.end();iter++)
		{
			cout << *iter<<" ";
		}
		cout << endl;
	}
	
	if(root->left)
	{
		findpath(root->left,sum,path,currentSUM);
	}
	
	if(root->right)
	{
		findpath(root->right,sum,path,currentSUM);
	}
	
	path.pop_back();
	
}

int main()
{
	BinaryTreeNode *n10 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	n10->value = 10;
	BinaryTreeNode *n5 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	n5->value = 5;
	BinaryTreeNode *n12 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	n12->value = 12;
	n10->left = n5;
	n10->right = n12;
	BinaryTreeNode *n4 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	n4->value = 4;
	BinaryTreeNode *n7 = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
	n7->value = 7;
	n5->left = n4;
	n5->right = n7;
	
	findpath(n10,22);
	return 0;
}

