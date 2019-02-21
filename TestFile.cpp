/**
* @author Jennifer Parrish
* CIS 22C
* TestFile.cpp
*/
/*
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main() {
    List<int> iList;
    List<char> cList;
    List<double> dList;
    List<string> sList;

    cout << "***The next 6 function calls will fail the assertion. The program should halt. "
             <<"After you test each one, then comment out the function call***";
    //sList.removeLast();
    //sList.removeFirst();
    //sList.removeIterator();
    //sList.getFirst();
    //sList.getLast();
    //sList.getIterator();

    iList.insertFirst(5);
    cout << "Should print 5: ";
    iList.printList();
    iList.insertLast(6);
    cout << "Should print 5 6:";
    iList.printList();
    cout <<"***The next function call will fail the assertion. After you test it, "
            << "then comment out the function call***";
    //iList.getIterator();
    iList.startIterator();
    iList.insertIterator(7);
    cout << "Should print 5 7 6:"; //note these should all print on a single line separated by spaces
    iList.printList();

    List<int> iList2(iList); //copy constructor
    cout << "Should print 5 7 6:";
    iList2.printList();

    cout << "Should print lists are equal: " << endl;
    if (iList==iList2)
        cout << "Lists are equal" << endl;
    else
        cout << "Lists are not equal" << endl;

    iList.advanceIterator();
    iList.removeIterator();
    cout << "Should print 5 6:";
    iList.printList();

    cout << "Should print lists are not equal: " << endl;
    if (iList==iList2)
        cout << "Lists are equal" << endl;
    else
        cout << "Lists are not equal" << endl;

    cout << "Length of list should be 0: "<< cList.getLength() << endl;
    cList.insertFirst('a');
    cList.removeLast();
    cout << "Length of list should be 0: "<< cList.getLength() << endl;
    cout << "List should be empty. Nothing printed to screen: "<< endl;
    //Should print nothing and move to a new line.
    //Should NOT print an error message or any other message
    cList.printList();
    cList.insertLast('Z');
    cList.startIterator();
    cList.insertIterator('z');
    cList.insertIterator('z');
    cList.advanceIterator();
    cList.insertIterator('z');
    cList.removeIterator();
    cout << "Should print Z z z:";
    cList.printList();
    cout << "The length of the list should be 3: " << cList.getLength() << endl;

    cout << "***Should fail the assertion as the iterator is off the end of the list. "
                << "Comment out when finished:*** \n";
    dList.advanceIterator();
    cout << "***Should fail the assertion as the iterator is off the end of the list. "
            << "Comment out when finished:*** \n";
    dList.insertIterator(-8.9); //should not insert this value

    dList.insertLast(8.8);
    dList.insertLast(9.9);
    cout << "Should print 8.8 9.9:";
    dList.printList();

    cout << "Should print iterator is off the end of the List:\n";
    if(dList.offEnd())
    {
        cout <<"Iterator is off end\n";
    }
    else
    {
        cout << "Iterator is not off end\n";
    }
    dList.startIterator();
    dList.advanceIterator();
    cout << "Should print 9.9: ";
    cout << dList.getIterator() << endl;
    dList.advanceIterator();
    cout << "***Should fail the assertion as the iterator is off the end of the list. "
                << "Comment out when finished:*** \n";
    cout << dList.getIterator() << endl;
    dList.removeLast();
    cout << "Should print 8.8: ";
    dList.printList();
}
*/
