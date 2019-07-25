#include"BinaryTree.h"
#include"Queue.h"

BTNode *BinaryTreeNodeCreate(BTDataType *a, int n, int *pi)//ͨ��ǰ����������顰ABD##E#H##CF##G##������������
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
int BinaryTreeSize(BTNode *root)//������
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) 
		+ BinaryTreeSize(root->_right) 
		+ 1;
}
int BinaryTreeLevelKSize(BTNode *root, int k)//��k�������
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode *BinaryTreeFind(BTNode *root, BTDataType x)//Ѱ��ָ��ֵ���
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

void BinaryTreePreOrder(BTNode *root)//ǰ���С��������
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

void BinaryTreeLevelOrder(BTNode *root)//�������
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

/*bool BinaryTreeComplete(BTNode *root)//�ж��Ƿ�����ȫ������
{
	int *pi = 0;
	char *array[] = {0};
	array[] = BinaryTreeLevelOrder(root);


}*/
