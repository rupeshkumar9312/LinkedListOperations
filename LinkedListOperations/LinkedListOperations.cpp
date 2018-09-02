// LinkedListOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
struct node {
	int data;
	node *next;
};


class linkedList {
public:
	node *head, *tail;
	linkedList() {
		head = NULL;
		tail = NULL;
	}

	void push(int value) {
		node * n = new node;
		n->data = value;
		n->next = NULL;
		if (head == NULL)
		{
			head = n;
			tail = n;
			head->next = NULL;
		}
		else {
			n->next = head;
			head = n;
		}
	}
	void display()
	{
		node *ptr = head;
		while (ptr != NULL)
		{
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}

	node * push(int value, int position)
	{
		//cout << "Position " << position << endl;
		node *n = new node;
		n->data = value;
		node* ptr = head;
		node *temp = ptr;
		int count = 0;
		while (ptr != NULL)
		{
			count++;
			//cout << "Count " << count << endl;
			if (count == position)
			{
				ptr = ptr->next;
				temp->next = n;
				n->next = ptr;
				//break;
			}
			ptr = ptr->next;
			temp = ptr;
		}
		return head;
	}
};
int main()
{
	linkedList list;
	list.push(10);
	list.push(20);
	list.push(40);
	list.push(50);
	list.display();
	cout << "-----------------------" << endl;
	list.push(30,2);
	list.display();
}
