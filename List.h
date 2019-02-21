//============================================================================
// Name        : List.h
// Author      : Khadeja Khalid
// Version     : Tuesday January 23, 2018
// Description : Header File of List
//============================================================================

//#ifndef LIST_H_
//#define LIST_H_
#include <iostream>
#include <assert.h>
//#include "List.h"
#include <cstddef> //for NULL
//#include <string>
using namespace std;

template <class listdata> //list stores generic listdata, not any specific C++ type

class List
{

private:
    struct Node
	{
    	listdata data;
    	Node* next;
    	Node* prev;

        Node(int newData)
        {
            data = newData;
            next = NULL;
            prev = NULL;
        }
    };

    Node* first;
    Node* last;
    Node* iterator;
    int length;

public:

    /**Constructors and Destructors*/

    List();
    //Default constructor; initializes and empty list
    //Postcondition: The new instance will be created and an empty list equal to zero

    List(const List &list);
    //Copy constructor

    ~List();
    //Destructor. Frees memory allocated to the list
    //Postcondition: The memory allocated to the list is guaranteed to be free and the


    /**Accessors*/

    listdata getFirst() const;
    //Returns the first data in the list
    //Precondition: List cannot be empty, should point to the first node

    listdata getLast() const;
    //Returns the last data in the list
    //Precondition: List cannot be empty

    bool isEmpty() const;
    //Determines whether a list is empty.

    int getLength() const;
    //Returns the size of the list
    //Remains an int because integer value is returned always

    listdata getIterator() const;
    //Returns the element currently pointed at by the iterator
    //Precondition: length != 0, iterator != NULL

    bool offEnd() const;
    //Returns whether the iterator is off the end of the list, i.e. is NULL

    bool operator==(const List &list);
    //Tests two lists to determine whether their contents are equal
    //Postcondition: returns true if lists are equal and false otherwise

    /**Manipulation Procedures*/

    void removeFirst();
    //Removes the value stored in first node in the list
    //Precondition: The list should not be empty
    //Postcondition: No nodes should be left

    void removeLast();
    //Removes the value stored in the last node in the list
    //Precondition: The list should not be empty and should not be the first element
    //Postcondition: One node should be left

    void insertFirst (listdata data);
    //Inserts a new data at the beginning of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: Should insert a new data at the beginning of the list

    void insertLast(listdata data);
    //Inserts a new data at the end of the list
    //If the list is empty, the new data becomes both first and last
    //Postcondition: Should insert a new data at the end of the list

    void startIterator();
    //Moves the iterator to the start of the list

    void removeIterator();
    //Removes the element currently pointed to by the iterator. Iterator then points to NULL.

    void insertIterator(listdata data);
    //Inserts an element after the node currently pointed to by the iterator

    void advanceIterator();
    //Moves the iterator up by one node

    void reverseIterator();
    //Moves the iterator down by one node

    /**Additional List Operations*/

    void printList() const;
    //Prints to the console the value of each data in the list sequentially
    //and separated by a blank space
    //Prints nothing if the list is empty
    //Prints a empty newline character if it's empty..

    void printNumberedList() const;
    //prints the contents of the linked list to the screen in the format #. <element> followed by a newline

};
//#endif /* LIST_H_ */

//============================================================================
// Name        : List.cpp
// Author      : Khadeja Khalid
// Version     : Tuesday January 23, 2018
// Description : Functions Definitions for List
//============================================================================


//Constructor
template <class listdata>
List<listdata>::List()
{
    first = NULL;
    last = NULL;
    iterator = NULL;
    length = 0;
}

//Copy Constructor
template <class listdata>
List<listdata>::List(const List &list)
{

    if(list.first == NULL) //If the original list is empty, make an empty list for this list
    {
        first = last = iterator = NULL; //Make the new list empty
    }
    else
    {
        first = new Node(list.first->data); //calling Node constructor, allocate memory for a new first node
        Node* temp = list.first; //set a temporary node pointer to point at the first of the original list
        iterator = first; //set iterator to point to first node of the new list, copy contents of original first node into new last node

        //Move through both lists with a while loop
        while(temp->next != NULL) //next is not NULL
        {
        	//Copy the contents of original node into new node
            temp = temp->next; //advance up to the next node in the original list
            iterator->next = new Node(temp->data); //using node constructor to create new node w/ copy of data
            iterator = iterator->next; //advance to this new node

        }

        last = iterator; //Why do I need this line of code? to point at the last node in the new list
        iterator = NULL;

    }

    length = list.length;
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

    	cout << temp->data << " "; //Prints the temporary iterator that points to the first and prints a blank space
    	temp = temp->next; //Points to the next

    }
    cout << endl; //What does this do? Prints an empty line

}

//Manipulation
template <class listdata> //Step 1: template the function
void List<listdata>::insertFirst(listdata data) //Step 2 & 3: List is templated and takes in a generic parameter
{

	Node* N = new Node(data);
	if (length == 0)
	{
	    first = N;
	    last = N;
	}
	else
	{
	    N->next = first; //The first points to the new node, which points to the data
	    first->prev = N; //Need to update the prev pointer of first to point back at the new node
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
    	//N->next = last; //Wrong, why? Creates a circle of pointers, how?
    	//last->next = N; //The last points to the new node, which points to the data
    	//last->prev = N; //Need to update the prev pointer of last to point back at the new node

    	N->prev = last;
    	last->next = N;
        last = N;
    }
    length++;
}

//Manipulation
template <class listdata>
void List<listdata>::removeFirst()
{
    assert (length != 0);

    if(length == 1)
    {
        delete first;
        first = last = NULL;
        iterator = NULL;
        length = 0;
    }
    else
    {
        Node* temp = first; //assign a temporary node to first
        first = first->next; //point the first to the second node because temp is now first
        first->prev = NULL; //Make frist's prev point at NULL
        delete temp; //remove the first value
        iterator = NULL;
        length--; //change the length
    }
}

//Manipulation
template <class listdata>
void List<listdata>::removeLast()
{
	assert (length != 0);

    if (length == 1)
    {
        delete last;
        last = first = NULL;
        iterator = NULL;
        length = 0;
    }
    else
    {
    	Node* t = last; //Store the last element to temp
        last = last->prev; //Make last point at second to last
        last->next = NULL; //Set last's next point at NULL
        delete t;
        iterator = NULL;
        length--;
    }

}
//Manipulation
template <class listdata>
void List<listdata>::startIterator()
{
    iterator = first; //Iterator and first point to same data
}

//Manipulation
template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
	assert (!offEnd());

	if(iterator == last)
    {
    	insertLast(data);
    }
    else
    {
    	Node* N = new Node(data);
    	N->next = iterator->next; //Update new node next
    	N->prev = iterator; //Update new node prev
    	iterator->next->prev = N; //Update iterator->next's prev
    	iterator->next = N; //Update iterator's next
    	length++;
    }
}

//Manipulation
template <class listdata>
void List<listdata>::removeIterator()
{
	assert (iterator != NULL);

    if(iterator == first)
    {
    	removeFirst();
    }
    else if (iterator == last)
	{
    	removeLast();
	}
	else
	{
		iterator->prev->next = iterator->next;
		iterator->next->prev = iterator->prev;
		delete iterator;
		length--;
		iterator = NULL;
	}

}


//Manipulation
template <class listdata>
void List<listdata>::advanceIterator()
{
	assert (iterator != NULL);
	iterator = iterator->next;
}

//Manipulation
template <class listdata>
void List<listdata>::reverseIterator()
{
	assert (iterator != NULL);
	iterator = iterator->prev;
	//Node* p = last;
	//p = p->prev;
}

//Access
template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(length != list.length)
        return false;
    Node* temp1 = first;
    Node* temp2 = list.first;
    while(temp1 != NULL)
    {
		if(temp1->data != temp2->data)
           return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

//Access
template <class listdata>
bool List<listdata>::isEmpty() const
{
    return (length == 0);
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
	assert(length != 0);
    return first -> data;

}

//Access
template <class listdata>
listdata List<listdata>::getLast() const
{
    assert(length != 0);
	return last -> data;

}

//Access
template <class listdata>
listdata List<listdata>::getIterator() const
{
	assert (length != 0);
	assert (iterator !=0);
	return iterator->data;
}

//Access
template <class listdata>
bool List<listdata>::offEnd() const
{
	return iterator == NULL;
}

