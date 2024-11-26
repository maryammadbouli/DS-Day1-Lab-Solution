#include <iostream>
#include "LinkedList.h"


using namespace std;

int main()
{
    LinkedList myList;

    myList.display();
    myList.insertAfter(5,4);    ///insert-after --> empty list
    myList.display();
    myList.insertAfter(4,7);    ///insert-after --> single element list
    myList.display();
    myList.add(3);
    myList.add(11);
    myList.add(6);
    myList.display();
    myList.insertAfter(3,20);   ///insert-after --> (normal case)
    myList.display();

    myList.insertBefore(20, 15);    ///insert before
    myList.display();
    myList.insertBefore(6,99);      ///insert before tail
    myList.display();

    cout<<"\nYour list has "<<myList.getCount()<<" nodes"<<endl;    ///get count

    cout<<"Node at index 5 (starting from index 0) is "<<myList.getDataByIndex(5)<<endl;

    return 0;
}
