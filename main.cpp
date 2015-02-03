#include <iostream>
#include "sorted_binary_tree.hpp"
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "tree_names.hpp"

extern std::vector<std::string> tree_names();

int main()
{
    std::ofstream output("output.log");
    SortedBinaryTree<int> tree;
    srand(time(NULL));
//    for(int i = 0; i < 100; i++)
//        tree.insert(rand() % 100);
//
//    for(int i = 0; i < 100; i++)
//        tree.erase(rand() % 100);

    //doing a bunch of stuff on an empty tree.
    assert(tree.size() == 0);
    tree.clear();
    assert(tree.size() == 0);
    assert(tree.begin() == tree.end());
    tree.erase(tree.begin());
    tree.erase(19);

    tree.insert(1);
    //delete the root node
    tree.erase(1);
    assert(tree.size() == 0);

    //insert some numbers
    for(int i = 0; i < 20; i++){
        tree.insert(i);
    }
    assert(tree.size() == 20);

    //throw the tree away
    tree.clear();
    assert(tree.size() == 0);


    int testValues[] = {1,2,2,4,5,6,7,8,7,7,7,7,9,0,0,1};
    for(int i = 0; i < 16; i++){
        tree.insert(testValues[i]);
    }
    tree.print_debug(output);
    //iterators test
    for(SortedBinaryTree<int>::iterator it = tree.begin(); it != tree.end(); ++it){
        std::cout << *it << ",";
    }
    std::cout << "\n";

    assert(tree.size() == 16);
    //count test
    assert(tree.count(1) == 2);
    assert(tree.count(2) == 2);
    assert(tree.count(7) == 5);

    //repeat delete an element
    while(tree.count(7) > 0)tree.erase(7);
    assert(tree.count(7) == 0);

    //erase an non existing element
    size_t size = tree.size();
    tree.erase(7); //7 is not in anymore. deleting should be no problem
    assert(tree.size() == size);

    //test some trees with different template params
    std::vector<std::string> trees = tree_names();
    SortedBinaryTree<std::string> forest;

    //designate some forest
    for(int i = 0; i < 98; i ++){
        //plant some trees
        forest.insert(trees[rand() % trees.size()]);
    }
    //add these so there is always some effect of deleting to enjoy
    std::string rand_tree = trees[rand() % trees.size()];
    forest.insert(rand_tree);
    forest.insert(rand_tree);
    {
        std::ofstream forestOutput("forestOutputBefore.log");
        forestOutput << "//forestOutputBefore.log\n";
        forest.print_debug(forestOutput);
    }
    while(forest.count(rand_tree) > 0){
        forest.erase(rand_tree);
    }
    {
        std::cout << " Removed all " << rand_tree << "\n";
        std::ofstream forestOutput("forestOutputAfter.log");
        forestOutput << "//forestOutputAfter.log\n";
        forest.print_debug(forestOutput);

    }

    return 0;
}
