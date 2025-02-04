#include <iostream>
#include <map>
#include <unordered_map>
// Hash maps introduction
//                       Hash Maps
//                   |
//  _________________________________
//  |                               |
//  ordered                      unordered
// ( printing                 (unordered printing)
// in the order                      O(1)
//    we given)
//  O(logn)
using namespace std;
int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion
    // 1
    pair<string, int> p = make_pair("pratik", 0);
    m.insert(p);

    // 2
    m["insert"] = 1;

    // 3
    pair<string, int> pair2("patil", 1);
    m.insert(pair2);

    // updation
    m["patil"] = 2;

    // search
    cout << m["pratik"] << endl;    //-----> if used for unknown key it will assign 0 to it.
    cout << m.at("pratik") << endl; //-----> cannot be used for for unknown key
                                    //        error aa jayega.
    cout << m["sham"] << endl;
    // check size
    cout << m.size() << endl;

    // check presence
    cout << m.count("bro") << endl; //---->return 0 - absent
                                    //     return 1 - present

    // erase function
    cout << m.erase("patil") << endl;
    cout << m.size() << endl;

    // traversal
    // 1
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    // 2
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}