#include <iostream>
#include "sorted_binary_tree.hpp"
#include <cstdlib>
#include <fstream>
#include <ctime>

int main()
{
    std::ofstream output("output.txt");
    SortedBinaryTree<int> tree;
    srand(time(NULL));
//    for(int i = 0; i < 100; i++)
//        tree.insert(rand() % 100);
//
//    for(int i = 0; i < 100; i++)
//        tree.erase(rand() % 100);

    tree.insert(1);
    tree.erase(1);
    assert(tree.size() == 0);
    for(int i = 0; i < 20; i++){
        tree.insert(i);
    }
    assert(tree.size() == 20);
    tree.clear();
    assert(tree.size() == 0);

    int testValues[] = {1,2,2,4,5,6,7,8,7,7,7,7,9,0,0,1};
    for(int i = 0; i < 16; i++){
        tree.insert(testValues[i]);
    }
    assert(tree.size() == 16);

    assert(tree.count(1) == 2);
    assert(tree.count(2) == 2);
    assert(tree.count(7) == 5);

    while(tree.count(7) > 0)tree.erase(7);
    assert(tree.count(7) == 0);

    tree.print_debug(output);
    return 0;
}
