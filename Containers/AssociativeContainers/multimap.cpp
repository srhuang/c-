/*****************************************************************
Name    :multimap
Author  :srhuang
Email   :lukyandy3162@gmail.com
History :
    20191118 Initial Version
*****************************************************************/
/*****************************************************************
Outline
    1. Initialization
    2. Capacity
    3. Element Access
    4. Modifiers
    5. Others
*****************************************************************/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
/*==============================================================*/

void printAll(multimap<int, string> &mymap)
{
    multimap<int, string>::iterator it;
    for(it=mymap.begin(); it!=mymap.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
}

//reverse
bool fncomp (int lhs, int rhs) {return lhs>rhs;}

class classcomp {
public:
    bool operator() (const int& lhs, const int& rhs) const
    {
        return lhs<rhs;
    }
};

int main(int argc, char const *argv[]){
    /*
     * Initialization
     */
    cout << "\nInitialization" << endl;

    //Using default constructor
    multimap<int, string> mymap;
    mymap.insert(pair<int, string>(20, "twenty"));
    mymap.insert(make_pair(10, "ten"));
    mymap.insert({30, "thirty"});
    cout << "mymap :";
    printAll(mymap);
    cout << endl;

    //Using Initializer list constructor
    multimap<int, string> mymap1({{9,"nine"},{5, "five"},{2, "two"},
        {7, "seven"},{9,"nine"},{1, "one"},{4, "four"},{6, "six"},{9,"nine"}});

    cout << "mymap1 :";
    printAll(mymap1);
    cout << endl;

    //Using range constructor
    vector<pair<int, string>> vec{{9,"nine"}, {5, "five"}, {2, "two"}, {7, "seven"}};
    multimap<int, string> mymap2(vec.begin(), vec.end());

    cout << "mymap2 :";
    printAll(mymap2);
    cout << endl;

    //Using copy constructor
    multimap<int, string> mymap3(mymap);

    cout << "mymap3 :";
    printAll(mymap3);
    cout << endl;

    //custom comparator function
    multimap<int, string, bool(*)(int, int)> 
        mymap4(vec.begin(), vec.end(), fncomp);

    cout << "mymap4 :";
    multimap<int, string, bool(*)(int, int)>::iterator it;
    for(it=mymap4.begin(); it!=mymap4.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;

    //custom comparator class
    multimap<int, string, classcomp> mymap5(vec.begin(), vec.end());

    cout << "mymap5 :";
    //map<int, string, bool(*)(int, int)>::iterator it;
    for(it=mymap5.begin(); it!=mymap5.end(); it++)
    {
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;

    /*
     * Capacity
     */
    cout << "\nCapacity" << endl;

    cout << "size:" << mymap.size() << endl;
    cout << "empty:" << mymap.empty() << endl;

    /*
     * Element Access
     */
    cout << "\nElement Access" << endl;

    /*
     * Modifiers
     */
    cout << "\nModifiers " << endl;

    //insert()
    multimap<int, string>::iterator ret;
    ret = mymap.insert({20, "twenty"});
    //[C++11] The function optimizes its insertion time 
    //if position points to the element 
    //that will follow the inserted element (or to the end, if it would be the last).
    mymap.insert(ret, {25, "twenty-five"}); //efficiency inserting
    mymap.insert(ret, {25, "twenty-five"}); //no efficiency inserting
    cout << "insert mymap :";
    printAll(mymap);
    cout << endl;

    pair<int, string> input{99, "ninety-nine"};
    mymap.insert(input); //copy insertion
    input.first = 98;
    mymap.insert(pair<int, string>{1, "one"}); //move insertion
    mymap.insert(vec.begin(), vec.end()); //range insertion
    mymap.insert({{95, "ninety-five"}, 
        {96, "ninety-six"}, {97, "ninety-seven"}}); //initializer list insertion
    cout << "insert mymap :";
    printAll(mymap);
    cout << endl;

    //erase() by key
    mymap.erase(20);
    cout << "erase mymap :";
    printAll(mymap);
    cout << endl;

    //erase() by position
    it = mymap.find(30);
    mymap.erase(it);
    cout << "erase mymap :";
    printAll(mymap);
    cout << endl;

    //erase() by range
    it = mymap.find(25);
    mymap.erase(it, mymap.end());
    cout << "erase mymap :";
    printAll(mymap);
    cout << endl;

    //clear()
    mymap.clear();
    cout << "clear mymap :";
    printAll(mymap);
    cout << endl;

    //swap()
    cout << "swap mymap2 :";
    printAll(mymap2);
    cout << endl;

    multimap<int, string>().swap(mymap2);

    cout << "swap mymap2 :";
    printAll(mymap2);
    cout << endl;

    /*
     * Others
     */
    cout << "\nOthers " << endl;

    //find()
    it = mymap3.find(20);
    if(it!=mymap3.end()){
        cout << "mymap3 find :" << it->second << endl;
    }

    //count()
    if(mymap3.count(25)!=0){
        cout << "element is in the set." << endl;
    }else{
        cout << "element is NOT in the set." << endl;
    }

    return 0;
}
/*==============================================================*/