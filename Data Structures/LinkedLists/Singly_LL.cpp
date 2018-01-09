#include<iostream>

//SINGLY LINKED LIST
using namesapce std;

struct Node {
	int data;
	Node *next;
};

Node *head;

/*BASIC OPERATIONS- 1)INSERTION-Insertion at beginning-O(1) , insertions at end-O(n) , insertion in middle-O(n)
		    2)DELETION-front,tail and intermediate positions
		    3)TRAVERSAL	-O(n)
*/


//Function to traverse the list and return the count of items in LL

int listlength() {
	Node *current = head;
	int count = 0 ;
	while(current!=NULL) {
		count++;
		cout<<current->data<<" | "<<"\t";
		current=current->next;
	}
	
	return count;
}


void InsertList(int data, int pos) {
	
	Node *temp,*temp1,*new_node;
	
	temp=head;
	new_node->data = data;
	
	if(pos==1) { //insertion at beginning- update the head and next pointer of new_node
		
		new_node->next=temp;
		head=new_node;
		
	}
	
	int k=1;
	else {
		//this condition will work for both insertion at middle and insertion at last
		while(temp!=NULL) && while(k<pos) {
			k++;
			temp1=temp; //temp1 is the node previous temp node
			temp=temp->next;
		}
		
		temp1->next=new_node;
		new_node->next=temp;
	}
}





