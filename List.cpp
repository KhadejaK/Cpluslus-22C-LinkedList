//============================================================================
// Name        : List.cpp
// Author      : Khadeja Khalid
// Version     : Tuesday January 16, 2018
// Description : Functions Definitions for List
//============================================================================
/*
#include <iostream>
#include <assert.h>
#include "List.h"
using namespace std;

//Constructor
template <class listdata>
List<listdata>::List()
{
    first = NULL;
    last = NULL;
    length = 0;
}

//Destructor
template <class listdata>
List<listdata>::~List()
{
	Node* b = first;
    Node* a = NULL; //a stands for "after" (i.e. after b)
    while (b != NULL)
    {
        a = b->next; //move a to node after b
        delete b; //remove b (you know it is not NULL from if)
        b = a; //b "catches up" with a (both point to same place in list)
    }
}

template <class listdata>
void List<listdata>::printList() const
{
    Node* temp = first; //create a temporary iterator
    while (temp != NULL)
    {

        //Add two lines of code here
        //Hint: One statement should contain a cout

    	cout << temp->data << " "; //Prints the temporary iterator that points to the first and prints a blank space
    	temp = temp->next; //Points to the next

    }
    cout << endl; //What does this do? Prints an empty line

}

//Manipulation
template <class listdata> //Step 1: template the function
void List<listdata>::insertFirst(listdata data) //Step 2 & 3: List is templated and takes in a generic parameter
{
	if (length == 0)
	{
		first = last = new Node(data);

	}
    else
    {
    	Node* N = new Node(data);
        N->next = first; //The first points to the new node, which points to the data
        first = N;
    }

    length++;
}

//Manipulation
template <class listdata>
void List<listdata>::insertLast(listdata data)
{
    Node* N = new Node(data);
    if (length == 0)
    {
        first = N;
        last = N;
    }
    else
    {
        N->next = last;
        last = N;
    }
    length++;
}

//Manipulation
template <class listdata>
void List<listdata>::removeFirst()
{
    if(length == 0)
    {
        cout << "removeFirst : List is empty, no data to remove." << endl;
        return;
    }
    else if(length == 1)
    {
        delete first;
        first = last = NULL;
        length = 0;
    }
    else
    {
        Node* temp = first;
        first = first->next;
        delete temp;
        length--;
    }
}

//Manipulation
template <class listdata>
void List<listdata>::removeLast()
{
    if (length == 0)
    {

        cout << "removeLast : List is empty, no data to remove." << endl;
        return;

    }
    else if (length == 1)
    {

        delete last;
        last = first = NULL;
        length = 0;

    }
    else
    {
        Node* temp = first;
        while(temp->next != last) //move temp to second to last node in list
        {
            temp = temp->next;
        }
        delete last;
        last = temp; //set last to be the former second to last node stored in temp
        last->next = NULL; //set pointer to point at NULL rather than deallocated memory

        length--;

    }

}

//Access
template <class listdata>
bool List<listdata>::isEmpty() const
{
    return length == 0;
}

//Access
template <class listdata>
int List<listdata>::getLength() const
{
    return length;
}

//Access
template <class listdata>
listdata List<listdata>::getFirst() const
{
    return first -> data;

}

//Access
template <class listdata>
listdata List<listdata>::getLast() const
{
    //assert(length!=0);
	return last -> data;

}
*/
