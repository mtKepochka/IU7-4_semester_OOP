#include <iostream>
#include <string>

#include "./list/list.h"

using namespace std;

int main()
{
    cout << "List 1\n";
    List<string> list1;
    list1.push_back("First");
    list1.push_back("Second");
    list1.push_back("Third");
    list1.push_back("Fourth");
    cout << list1 << endl;

    cout << "List 2\n";
    List<string> list2(list1);
    cout << list2 << endl;

    cout << "List 3\n";
    string arr[] = { "Hello", "World", "!" };
    List<string> list3(arr, 3);
    cout << list3 << endl;

    cout << "List 4\n";
    List<string> list4 = { "That's", "not", "my", "first", "programm."};
    cout << list4 << endl;

    cout << "List 5\n";
    ListIterator<string> first = list4.begin();
    ListIterator<string> end = list4.begin() + 2;

    List<string> list5(first, end);
    cout << list5 << endl;

    cout << "List 6\n";
    ListConstIterator<string> first_2 = list4.cbegin() + 1;
    ListConstIterator<string> end_2 = list4.cbegin() + 2;

    List<string> list6(first_2, end_2);
    cout << list6 << endl;

    cout << "\nTry create list with negative size:\n";
    try
    {
        List<string> list_tmp_1(arr, -1);
    }
    catch (InvalidSize &error)
    {
        cout << error.what();
    }

    cout << "\nTry create list with bad array:\n";
    try
    {
        List<string> list_tmp_2(nullptr, 3);
    }
    catch (InvalidPointer &error)
    {
        cout << error.what();
    }

    cout << "\n------------------\n";
    cout << "Test methods\n";
    cout << "Is empty (list6): " << list6.empty() << endl;
    cout << "After clear method: ";
    list6.clear();
    cout << "Is empty (list6): " << list6.empty() << endl;

    cout << "\nPush front element\n";
    list6.push_front("front");
    cout << list6 << endl;

    cout << "Push front List 1\n";
    list6.push_front(list1);
    cout << list6 << endl;

    cout << "\nPush back element\n";
    list6.push_back("back");
    cout << list6 << endl;

    cout << "Push back List 1\n";
    list6.push_back(list1);
    cout << list6 << endl;

    cout << "\nInsert in head\n";
    list6.insert(list6.begin(), "AAAAAAAA");
    cout << list6 << endl;

    cout << "Insert in 3d pos\n";
    list6.insert(list6.begin() + 3, "AAAAA");
    cout << list6 << endl;

    cout << "Insert in 3d pos List 1\n";
    list6.insert(list6.begin() + 3, list1);
    cout << list6 << endl;

    cout << "\nInsert const in head\n";
    list5.insert(list5.cbegin(), "meow");
    cout << list5 << endl;

    cout << "Insert const in 3d pos\n";
    list5.insert(list5.cbegin() + 3, "meow-meow");
    cout << list5 << endl;

    cout << "Insert const in 3d List 1\n";
    list5.insert(list5.cbegin() + 3, list1);
    cout << list5 << endl;

    cout << "\nPop front\n";
    cout << "Before:\n";
    cout << list6 << endl;

    list6.pop_front();
    cout << "After:\n";
    cout << list6 << endl;

    cout << "\nPop back\n";
    cout << "Before:\n";
    cout << list6 << endl;

    list6.pop_back();
    cout << "After:\n";
    cout << list6 << endl;

    cout << "\nErase second element\n";
    cout << "Before:\n";
    cout << list6 << endl;

    list6.erase(list6.begin() + 1);
    cout << "After:\n";
    cout << list6 << endl;

    cout << "\nTry pop from empty list:\n";
    list6.clear();
    try
    {
        list6.pop_back();
    }
    catch (EmptyList &error)
    {
        cout << error.what();
    }

    cout << "\nReverse\n";
    cout << "Before:\n";
    cout << list2 << endl;
    list2.reverse();
    cout << "After:\n";
    cout << list2 << endl;

    cout << "\nMerge\n";
    list2.merge(list1);
    list2.merge("merged");
    cout << list2 << endl;

    cout << "\nTest operators\n";
    List<string> list_t_1 = { "1", "2", "3", "4" };
    List<string> list_t_2 = { "5", "6" };

    cout << "First list:\n";
    cout << list_t_1 << endl;
    cout << "Second list:\n";
    cout << list_t_2 << endl;

    cout << "\noperator =: ";
    list_t_1 = list_t_2;
    cout << list_t_1 << endl;

    cout << "\noperator += : ";
    list_t_1 += list_t_2;
    list_t_1 += "10";
    cout << list_t_1 << endl;

    cout << "\noperator +: ";
    list_t_1 = list1 + list_t_2;
    list_t_1 += "100";
    cout << list_t_1 << endl;

    cout << "\nTest cmp operators\n";
    List<string> list_cmp_1 = { "1", "2", "3", "4" };
    List<string> list_cmp_2 = { "1", "2", "3", "4" };

    cout << "\noperator ==: ";
    if (list_cmp_1 == list_cmp_2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    list_cmp_1.pop_back();

    cout << "\noperator !=: ";
    if (list_cmp_1 != list_cmp_1)
        cout << "Not Equal\n";
    else
        cout << "Equal\n";

    list_cmp_1.push_back("5");
    cout << "\nlist_cmp_1: " << list_cmp_1 << endl;
    cout << "list_cmp_2: " << list_cmp_2 << endl;

    cout << "\noperator < (list_cmp_1 < list_cmp_2): ";
    if (list_cmp_1 < list_cmp_2)
        cout << "True\n";
    else
        cout << "False\n";

    cout << "\noperator <= (list_cmp_1 <= list_cmp_2): ";
    if (list_cmp_1 <= list_cmp_2)
        cout << "True\n";
    else
        cout << "False\n";

    cout << "\noperator > (list_cmp_1 > list_cmp_2): ";
    if (list_cmp_1 > list_cmp_2)
        cout << "True\n";
    else
        cout << "False\n";

    cout << "\noperator >= (list_cmp_1 >= list_cmp_2): ";
    if (list_cmp_1 >= list_cmp_2)
        cout << "True\n";
    else
        cout << "False\n";

    cout << "\nTest iterators:\n";
    List<string> test_list = { "1", "2", "3" };

    cout << "Change second value by iterator:\n";
    cout << "Before:\n";
    cout << test_list << endl;

    ListIterator<string> iter = test_list.begin();
    iter++;
    *iter = "500";
    cout << "After:\n";
    cout << test_list << endl;
    ListIterator<string> iter_2 = test_list.begin();
    ++iter_2;

    cout << "\noperator ==: ";
    if (iter == iter_2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    cout << "\noperator !=: ";
    if (iter != iter_2)
        cout << "Not Equal\n";
    else
        cout << "Equal\n";

    cout << "\nTest bool in iterator: ";
    cout << (bool)test_list.begin() << endl;

    return 0;
}