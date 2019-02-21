
//============================================================================
// Name        : ListTest.cpp
// Author      : Khadeja Khalid
// Version     : Tuesday January 16, 2018
// Description : Tests the List Functions
//============================================================================

#include <iostream>
#include <string>
#include "List.h"
//#include <string>
using namespace std;

int main() {

    //instantiate lists for testing purposes
	List<int> L1; //Contains list of numbers
	List<int> L2; //Contains the value 0
	List<int> L3; //Contains the value 2, now "hi"
	List<int> L4; //Contains nothing, empty list
	List<int> L5; //Contains value 0, 1
	List<int> L6; //Contains value 6


    //Testing insertFirst() and printList()
    cout << "**********Testing InsertFirst**********\n\n";
    cout << "Should print out an empty line: \n";
    L1.printList(); //Should not print any message to the screen, just an empty line


    L1.insertFirst(0); //Inserting a 0 into insertFirst
    cout << "Should print out 0 and then move to a new line: \n";
    L1.printList(); //Should print just a 0

    for (int i = 1; i <= 10; i++)
    {
    	//inserting the the values 1-10 into L1
        L1.insertFirst(i);
    }
    cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 and then move to a new line: \n";
    L1.printList();

    //Testing insertLast()
    cout << endl << "**********Testing insertLast**********" << endl;

    cout << "Should print out 0 and then move on to a new line:" << endl;
    L2.insertLast(0);
    L2.printList();

    cout << "Should print out 2 and then move on to a new line:" << endl;
    L3.insertLast(2);
    L3.printList();

    //Testing removeFirst()
    cout << endl << "**********Testing removeFirst**********" << endl;
    //L4.removeFirst(); //Empty list
    //L4.printList();

    for (int x = 0; x <= 1; x++)
    {
    	L5.insertFirst(x); //inserts value 1 to L5
    }

    cout << "removeFirst. Should print 0: " << endl;
    L5.removeFirst(); //List contain value 0, 1
    L5.printList();
    cout << endl;
    cout << "removeFirst. Should print 9 8 7 6 5 4 3 2 1 0: " << endl;
    L1.removeFirst(); //List containing numbers
    L1.printList();

    //Testing removeLast
    cout << endl << "**********Testing removeLast**********" << endl;
    //L4.removeLast(); //Empty list
    //L4.printList();

    cout << "removeLast. Should print nothing: " << endl;
    L2.removeLast(); //List of 0
    L2.printList();
    cout << endl;
    cout << "removeLast. Should print 9 8 7 6 5 4 3 2 1: " << endl;
    L1.removeLast(); //List containing numbers
    L1.printList();

    //Testing isEmpty
    cout << endl << "**********Testing isEmpty**********" << endl;

    cout << "isEmpty. Should print 9 8 7 6 5 4 3 2 1: " << endl;
    L1.isEmpty(); //List containing numbers
    L1.printList();
    cout << endl;
    cout << "isEmpty. Should print nothing: " << endl;
    L2.isEmpty(); //List of 0
    L2.printList();

    //Testing getLength()
    cout << endl << "**********Testing getLength**********" << endl;

    cout << "getLength. Should print 9 8 7 6 5 4 3 2 1: " << endl;
    L1.getLength(); //List containing numbers
    L1.printList();
    cout << endl;
    cout << "getLength. Should print 2: " << endl;
    L3.getLength(); //List containing 2
    L3.printList();

    //Testing getFirst()
    cout << endl << "**********Testing getFirst**********" << endl;

    cout << "getFirst. Should print 9 8 7 6 5 4 3 2 1: " << endl;
    L1.getFirst(); //List containing numbers
    L1.printList();
    cout << endl;
    cout << "getFirst. Should print 2: " << endl;
    L3.getFirst(); //List containing 2
    L3.printList();

    //Testing getLast
    cout << endl << "**********Testing getLast**********" << endl;

    cout << "getLast. Should print 9 8 7 6 5 4 3 2 1: " << endl;
    L1.getLast(); //List containing numbers
    L1.printList();
    cout << endl;
    cout << "getLast. Should print 2: " << endl;
    L3.getLast(); //List containing 2
    L3.printList();

    cout << endl;
    cout << "**********Testing Operator ==:**********" << endl;
    if(L1==L2)
          cout << "Lists are equal!\n";
    else
          cout << "Lists are unequal!\n";

    L5.startIterator();
    cout << endl << "**********Testing Iterator**********" << endl;

    cout << "Should print 0 3 1: " << endl;
    L5.insertIterator(3);
    L5.printList();

    cout << "Should print 0 3: " << endl;
    L5.advanceIterator();
    L5.removeIterator();
    L5.printList();




}


