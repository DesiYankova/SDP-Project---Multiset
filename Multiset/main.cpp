#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Pair.h"
#include "Node.h"
#include "HashTable.h"
#include "Multiset.h"

using namespace std;

int main()
{
    int num;

    cout << "Write 1 if you want to use already done demo" << endl;
    cout << "Write 2 if you want to enter all comands by yourself" << endl;

    cin >> num;

    if(num == 1)
    {
        Pair<string,int> elem1 ("as",2);
        Pair<string,int> elem2 ("sd",5);
        Pair<string,int> elem3 ("as",7);
        Pair<string,int> elem4 ("f",9);
        Pair<string,int> elem5 ("f",2);
        Pair<string,int> elem6 ("s",2);
        Pair<string,int> elem7 ("a",7);
        Pair<string,int> elem8 ("t",5);
        Pair<string,int> elem9 ("a",3);
        Pair<string,int> elem10 ("p",10);

        Multiset<string,int> multiset;

        multiset.add(elem1);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem1.PrintPair();

        multiset.add(elem2);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem2.PrintPair();

        multiset.add(elem3);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem3.PrintPair();

        multiset.add(elem4);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem4.PrintPair();

        multiset.add(elem5);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem5.PrintPair();

        multiset.add(elem6);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem6.PrintPair();

        multiset.add(elem7);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem7.PrintPair();

        multiset.add(elem8);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem8.PrintPair();

        multiset.add(elem9);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem9.PrintPair();

        multiset.add(elem10);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem10.PrintPair();

        cout << endl;
        cout << "Elements in first multiset: " << endl;
        multiset.Print();

        cout << endl;
        multiset.remove(elem1);
        cout << "Remove element - ";
        elem1.PrintPair();

        cout << endl;
        cout << "Elements of first multiset after removing the element: " << endl;
        multiset.Print();

        cout << endl;
        multiset.removeAll("f");
        cout << "Remove all elements in first multiset with key -f- " << endl;

        cout << endl;
        cout << "Elements of first multiset after removing all elements with key -f-" << endl;
        multiset.Print();

        cout << endl;
        cout << "Number of elements with key -as- in first multiset" << endl;
        multiset.count("as");

        cout << endl;
        cout << "The number of different elements in first multiset is: ";
        multiset.count();
        cout << endl;

        //
        Multiset<string,int> multisetSub;


        cout << endl;
        cout << "/////////////" << endl;
        multisetSub.add(elem7);
        cout << endl;
        cout << "Add in second multiset this element- ";
        elem7.PrintPair();

        multisetSub.add(elem3);
        cout << endl;
        cout << "Add in second multiset this element- ";
        elem3.PrintPair();

        multisetSub.add(elem2);
        cout << endl;
        cout << "Add in second multiset this element- ";
        elem2.PrintPair();

        multisetSub.add(elem8);
        cout << endl;
        cout << "Add in first multiset this element- ";
        elem8.PrintPair();

        cout << endl;
        cout << "Elements in second multiset: " << endl;
        multisetSub.Print();

        cout << endl;
        cout << "Is second multiset subset of first? " << endl;
        multiset.isSubSet(multisetSub,multiset) ? cout << "true" : cout << "false";
        cout << endl;

        cout << endl;
        cout << "Is first multiset subset of first? " << endl;
        multiset.isSubSet(multiset,multisetSub) ? cout << "true" : cout << "false";
        cout << endl;

        cout << endl;
        cout << "Merge two multisets: " << endl;
        multiset.merge(multiset,multisetSub);

        multiset.backup("backupFirstMultiset.txt");
        multisetSub.backup("backupSecondMultiset.txt");
    }
    else if(num == 2)
    {
        cout << "Write 1 if you want to add element" << endl;
        cout << "Write 2 if you want to remove element by key and value" << endl;
        cout << "Write 3 if you want to remove all elements by key" << endl;
        cout << "Write 4 if you want to check if one multiset is subset of another multiset" << endl;
        cout << "Write 5 if you want to check the number of elements by key" << endl;
        cout << "Write 6 if you want to check the number of different elements in the multiset" << endl;
        cout << "Write 7 if you want to merge two multisets" << endl;
        cout << "Write 8 if you want to create second multiset" << endl;
        cout << "Write 9 if you do not want to enter other commands" << endl;


        int numOfCommand;
        Multiset<string,int> multiset;
        Multiset<string,int> multiset2;
        int numOfSubs = 1;

        do
        {
            cout << endl;
            cout << "Chose command" << endl;
            cin >> numOfCommand;

            if(numOfCommand == 1)
            {
                int value;
                string key;

                cout << "enter key of string type" << endl;
                cin >> key;

                cout << "enter value of int type" << endl;
                cin >> value;
                cout << endl;

                Pair<string,int> elem;
                elem.setKey(key);
                elem.setValue(value);

                if(numOfSubs == 1)
                {
                    multiset.add(elem);
                }
                else
                {
                    multiset2.add(elem);
                }
            }
            else if(numOfCommand == 2)
            {
                int value;
                string key;

                cout << "enter key of string type" << endl;
                cin >> key;

                cout << "enter value of int type" << endl;
                cin >> value;
                cout << endl;

                Pair<string,int> elem;
                elem.setKey(key);
                elem.setValue(value);

                if(numOfSubs == 1)
                {
                    multiset.remove(elem);
                }
                else
                {
                    multiset2.remove(elem);
                }
            }
            else if(numOfCommand == 3)
            {
                string key;
                cout << "enter key of string type" << endl;
                cin >> key;
                if(numOfSubs == 1)
                {
                    multiset.removeAll(key);
                }
                else
                {
                    multiset2.removeAll(key);
                }
            }
            else if(numOfCommand == 4)
            {
                if(numOfSubs == 1)
                {
                    cout << "Please create another multiset if you want to use 4th function" << endl;
                }
                else
                {
                    multiset.isSubSet(multiset, multiset2)? cout << "true" : cout << "false";
                }
            }
            else if(numOfCommand == 5)
            {
                string key;
                cout << "enter key of string type" << endl;
                cin >> key;
                if(numOfSubs == 1)
                {
                    multiset.count(key);
                }
                else
                {
                    multiset2.count(key);
                }
            }
            else if(numOfCommand == 6)
            {
                if(numOfSubs == 1)
                {
                    multiset.count();
                }
                else
                {
                    multiset2.count();
                }
            }
            else if(numOfCommand == 7)
            {
                if(numOfSubs == 1)
                {
                    cout << "Please create another multiset if you want to use 4th function" << endl;
                }
                else
                {
                    multiset.merge(multiset,multiset2);
                }

            }
            else if(numOfCommand == 8)
            {
                numOfSubs++;
            }
            else if(numOfCommand == 9)
            {
                if(numOfSubs == 1)
                {
                    multiset.backup("backup1.txt");
                }
                else
                {
                    multiset.backup("backup1.txt");
                    multiset2.backup("backup2.txt");
                }

            }
            else
            {
                cout << "wrong number of command" << endl;
            }

        }while(numOfCommand != 9);
    }
    else
    {
        cout << "Wrong number of command" << endl;
    }


    return 0;
}
