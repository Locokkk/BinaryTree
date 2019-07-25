#include"BinaryTree.h"
#include"Queue.h"

BTNode *BinaryTreeNodeCreate(BTDataType *a, int n, int *pi)//通过前序遍历的数组“ABD##E#H##CF##G##”构建二叉树
{
	if (a[*pi] == '#')
		return NULL;
	BTNode *root = (BTNode *)malloc(sizeof(BTNode));
	root->_data = a[*pi];

	++(*pi);
	root->_left=BinaryTreeNodeCreate(a, n, pi);

	++(*pi);
	root->_right=BinaryTreeNodeCreate(a, n, pi);

	return root;
}
void BinaryTreeDestroy(BTNode **root)
{
	BTNode* newnode = *root;
	if (root == NULL)
		return ;
	BinaryTreeDestroy(&newnode->_left);
	BinaryTreeDestroy(&newnode->_right);
	free(root);
	root = NULL;
}
int BinaryTreeSize(BTNode *root)//结点个数
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) 
		+ BinaryTreeSize(root->_right) 
		+ 1;
}
int BinaryTreeLevelKSize(BTNode *root, int k)//第k层结点个数
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode *BinaryTreeFind(BTNode *root, BTDataType x)//寻找指定值结点
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode *lret = BinaryTreeFind(root->_left, x);
	if (lret != NULL)
		return lret;

	BTNode *rret = BinaryTreeFind(root->_left, x);
	if (rret != NULL)
		return rret;

	return NULL;
}

void BinaryTreePreOrder(BTNode *root)//前、中、后序遍历
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePreOrder(root->_left);
	BinaryTreePreOrder(root->_right);
}
void BinaryTreeInOrder(BTNode *root)
{
	if (root == NULL)
		return;
	BinaryTreePreOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePreOrder(root->_right);
}
void BinaryTreePostOrder(BTNode *root) {
	if (root == NULL)
		return;
	BinaryTreePreOrder(root->_left);
	BinaryTreePreOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode *root)//层序遍历
{
	Queue *pq;
	if (root == NULL)
		return;
	QueueInit(pq);
	QueuePush(pq, root->_data);
	QUDataType left = (QUDataType)root->_left;
	QUDataType right = (QUDataType)root->_right;

	while (!QueueEmpty(pq))
	{
		printf("%c ", root->_data);
		QueuePop(pq);
		if(root->_left!=NULL)
		QueuePush(pq, left);
		if(root->_right!=NULL)
		QueuePush(pq, right);
	}
}

/*bool BinaryTreeComplete(BTNode *root)//判断是否是完全二叉树
{
	int *pi = 0;
	char *array[] = {0};
	array[] = BinaryTreeLevelOrder(root);


}*/
