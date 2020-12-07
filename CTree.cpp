#include "CTree.h"
#include <iostream>
using namespace std;

//sets the root to null
CTree::CTree()
{
	m_root = nullptr;
}

CTree::CTree(const CTree & other)
{
}

CTree::~CTree()
{
	delete m_root;
	m_root = nullptr;
}

const CTree & CTree::operator=(const CTree & rhs)
{
	return *this;
}

void CTree::insert(int key)
{
	if (m_root == nullptr) 
	{
		//create a new CTNode and give it the key, then the new node is the root
		CTNode *newNode = new CTNode(key);
		m_root = newNode;
	}
	else 
	{
		//the root already exists so insert the node and check to see if needs to be rebalanced
		m_root->insert(key);
		rebalance(key);
	}
}

bool CTree::remove(int key)
{

	return false;
}

//finds a node in the tree
bool CTree::find(int key)
{
	//create a new temp node that is at the root
	CTNode* temp = m_root;
	//if the data is not equal to the key go left or right
	while (temp->getData() != key)
	{
		//goes left if the temps key is greater then the nodes key
		if (temp->getData() > key)
		{
			//gets the left node
			temp = temp->getLeft();
		}
		//goes right if the temps key is less then the nodes key
		else if (temp->getData() < key)
		{
			//gets the right node
			temp = temp->getRight();
		}
		if(temp == nullptr)
		{
			return false;
		}
	}
	return true;
}

void CTree::rebalance(int key) //use an array
{
	int i = 0;
	//create a temp CTNode where the root is checked to see if it needs to be rebalanced
	CTNode *temp = m_root->checkRebalance(key);

	if (temp != nullptr)
	{
		//give x the size of temp
		int x = temp->getSize();
		//dynamically allocate an array of the size of the temp - 1. 
		int* nodeArr = new int[x-1];
		//send the dyn alloc array and i = 0 to the buildArr function. 
		temp->buildArr(nodeArr, i);
		//create a temp CTree and a temp node for the parent that gets the parent of the CTNode temp
		CTree *tempCTree = new CTree();
		CTNode *tempParent = temp->getParent();
		//call the array tree. Passes an pointer to the array, start, end. 
		tempCTree->arrTree(nodeArr, 0, x-1);

		if (tempParent != nullptr)
		{
			if (temp->getData() < tempParent->getData())
			{
				//rebalance left
				m_root->setLeft(tempCTree->m_root);
			}
			else if (temp->getData() > tempParent->getData())
			{
				//rebalance right
				m_root->setRight(tempCTree->m_root);
			}
		}
		else
		{
			m_root = tempCTree->m_root;
		}
		delete[] nodeArr;
	}
}

//its the insert function but without calling the rebalance function
void CTree::insertRebalance(int key)
{
	if (m_root == nullptr)
	{
		CTNode *newNode = new CTNode(key);
		m_root = newNode;
	}
	else
	{
		m_root->insert(key);
	}
}

//goes inorder throught the tree
void CTree::inorder()
{
	if (m_root != nullptr)
	{
		cout << "(";
		//call the inorderTraversal function
		m_root->inorderTraversal();
		cout << ")" << endl;
	}
	else
		cout << "The tree is empty" << endl;
}

//uses the "L" char to go left and "R" char to right 
bool CTree::locate(const char * position, int & key)
{
	//create a new CTNode 
	CTNode *temp = m_root;
	if (position[0] == '\0')
	{
		key = temp->getData();
		return true;
	}
	//for loop that goes through the array and checks to see if it's L or R in the array
	for (int i = 0; position[i] != '\0'; i++)
	{
		//if L go left
		if (position[0] == 'L')
		{
			temp = temp->getLeft();
		}
		//if R go right
		else if (position[0] == 'R')
		{
			temp = temp->getRight();
		}
		if (temp != nullptr)
		{
			key = temp->getData();
			return true;
		}
	}
	return false;
}

//gets the middle of the array and calls itself until the array is at the end
void CTree::arrTree(int *arr, int start, int end)
{
	//gets the middle of the array
	int mid = (start + end) / 2;
	if (start <= end)
	{
		insertRebalance(arr[mid]);
		arrTree(arr, start, mid - 1);
		arrTree(arr, mid + 1, end);
	}
}

//default constructor for CTNode
CTNode::CTNode(int data)
{
	m_data = data;
	m_size = 1;
	m_height = 0;
	m_left = nullptr;
	m_right = nullptr;
	m_parent = nullptr;
}

//constructor for CTNode
CTNode::CTNode(int data, CTNode *parent)
{
	m_data = data;
	m_size = 1;
	m_height = 0;
	m_left = nullptr;
	m_right = nullptr;
	m_parent = parent;
}

//gets the parent of the node
CTNode* CTNode::getParent()
{
	return m_parent;
}

//inserts a node into the tree
void CTNode::insert(int key)
{
	//if the key does not equal the data keep going until it is
	if (key != m_data) 
	{
		if (key < m_data) 
		{
			if (m_left == nullptr) 
			{
				//if the left is null, insert the key into that node because it is the end of the tree
				m_left = new CTNode(key, this);
				//update size and height
				size();
				height();
			}
			else 
			{
				//recursive call 
				m_left->insert(key);
			}
		}
		if (key > m_data) 
		{
			if (m_right == nullptr) 
			{
				//if the right is null, insert teh key into that node because it is the end of the tree
				m_right = new CTNode(key, this);
				//update size and height
				size();
				height();
			}
			else 
			{
				//recursive call
				m_right->insert(key);
			}
		}
	}
}

void CTNode::inorderTraversal()
{
	//if the left is not null
	if (m_left)
	{
		cout << "(";
		//keep going through the tree
		m_left->inorderTraversal();
		cout << ")";
	}
	cout << m_data << ':' << m_height << ':' << m_size;
	//if the right is not null
	if (m_right)
	{
		cout << "(";
		//keep going through the tree
		m_right->inorderTraversal();
		cout << ")";
	}
}

//checks to see if the subtree needs to be rebalanced
CTNode* CTNode::checkRebalance(int key)
{
	//create a new CTNode thats null
	CTNode *temp = nullptr;
	if (m_left != nullptr and m_right != nullptr)
	{
		//sets the left and right size to l and r so I dont have to keep typing this all out
		int l = m_left->m_size;
		int r = m_right->m_size;
		//if the left size is greater then the right
		if (l > r)
		{
			//subtract the l and r size and if its creater then 2 then it needs to be rebalanced
			if (l - r > 2)
			{
				return this;
			}
		}
		//if the right - left is greater then 2 the tree needs to be rebalanced
		else
			if (r - l > 2)
			{
				return this;
			}
		//if both are null then return the temp node
		if (m_left == nullptr and m_right == nullptr)
		{
			return temp;
		}
		//if the data is less then the key, the left is checked to see if it needs to be rebalanced 
		if (this->getData() < key)
		{
			m_left->checkRebalance(key);
		}
		//if the data is greater then the key, the right is checked to see if it needs to be rebalanced 
		if (this->getData() > key)
		{
			m_right->checkRebalance(key);
		}
	}
	return temp;
}

void CTNode::buildArr(int arr[], int &data)
{
	//if the left is not null keep calling until its the end
	if (m_left != nullptr)
	{
		m_left->buildArr(arr, data);
	}
	//set the arrays data to m_data and increase the data by 1
	arr[data] = m_data;
	data++;
	//if the right is not null keep calling until it is. 
	if (m_right != nullptr)
	{
		m_right->buildArr(arr, data);
	}
}

//height function to update height
void CTNode::height()
{
	//update height if either the left or right are not null
	if (m_left != nullptr or m_right != nullptr)
	{
		m_height++;
	}
	if (m_parent != nullptr)
	{
		if (m_parent->m_height <= m_height)
		{
			m_parent->height();
		}
	}
}

//size function to update size
void CTNode::size()
{	
	m_size++;
	//keeps calling size until the parent is null
	if (m_parent != nullptr)
		m_parent->size();
}

//gets the size
int CTNode::getSize()
{
	return m_size;
}