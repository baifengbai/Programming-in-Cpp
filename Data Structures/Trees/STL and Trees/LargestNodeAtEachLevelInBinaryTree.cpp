#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;



//program to print largest nodes at each level of a binary tree

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



//function to find smallest element in a vector
int Largest(vector<int> &v)
{
	vector<int>::iterator i;
	int large = v[0];
	
	for(i = v.begin(); i != v.end() ; i++ )
	{
		if( *i > large )
		{
			large = *i;	
		}	
	}
	
	return large;
}


//function to store all the nodes at each level in a hash map
void LargestNodeUtil(BinaryTreeNode *root, map< int,vector<int> > &Map ,int level)
{
	if(!root) return;
	
	
	
	//store each level as key and corresponding elements at that level in a vector
	LargestNodeUtil(root->left,Map,level+1);
	
	//storing all nodes at each same level in hash map inside a vector
	Map[level].push_back(root->data);
	
	LargestNodeUtil(root->right,Map,level+1);
	
}


void LargestNode(BinaryTreeNode *root)
{
	map< int,vector<int> > Map;
	map<int,vector<int> >::iterator it;
	
	//populating the map
	LargestNodeUtil(root,Map,0);
	
	cout<<"level "<<" "<<" Smallest Node"<<endl;
	
	for(it = Map.begin() ; it!=Map.end() ; it++)
	{
		
		cout<<       it->first<<"   |    ";
		
		cout<<*max_element(it->second.begin(),it->second.end());
		//or use custom function to find minimum element
//		cout<<Largest(it->second);
		 //finding smallest at that level	
	
		
		cout<<endl;
	}
	
}



//Approach B-using iterative level order traversal

void LargestLevelNodeUsingLevelOrder(BinaryTreeNode *root)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	if(!root) return;
	
	int max = INT_MIN;
	
	int level=0;
	q.push(root);
	q.push(NULL); //marker for completion of level-0
	
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		//when temp becomes NULL it means we have traversed a level
		if(temp==NULL)
		{
			cout<<"At level "<<level<<" maximum node is "<<max<<endl;
			
			if(q.empty()) break;
			
			q.push(NULL);
			
			level++;
			
			//resetting min for next level's minimum value
			max = INT_MIN;
			
			continue;
		}
		
		
		//get max at every level
		if(max < temp->data)
		{
			
			max = temp->data;
			
		}
		
		
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
		
	}
}


void Insert( struct BinaryTreeNode **root,int data)
{
	struct BinaryTreeNode *new_node = new BinaryTreeNode();
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *> q;
	new_node->data = data;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(*root==NULL)
	{
		*root = new_node;
		return;
	}
	
	q.push(*root);
	
	while(!q.empty())
	{
		temp  = q.front();
		q.pop();
		
		if(temp->left==NULL)
		{
			temp->left = new_node;
			return;
			
			
		}
		
		else
		{
			q.push(temp->left);
		}
			
		if(temp->right==NULL)
		{
			temp->right = new_node;
			return;
			
		}	
		
		else
		{
			q.push(temp->right);
		}
	}
	
	
}



int main()
{
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,7);
	Insert(&root1,6);
	Insert(&root1,5);
	Insert(&root1,4);
	Insert(&root1,3);
	Insert(&root1,2);
	Insert(&root1,1);
//	Insert(&root1,11);
//	Insert(&root1,-1);
	
		
	
	
	LargestNode(root1);
	cout<<endl;
	LargestLevelNodeUsingLevelOrder(root1);	
	
	
	return 0;
}