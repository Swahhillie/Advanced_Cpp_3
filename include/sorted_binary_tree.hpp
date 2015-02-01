#ifndef SORTEDBINARYTREE_H
#define SORTEDBINARYTREE_H
#include <iostream>

template<typename T>
class SortedBinaryTree
{
public:
    SortedBinaryTree();
    virtual ~SortedBinaryTree();


    size_t size()const
    {
        return m_size;
    };
    bool empty()const
    {
        return m_root == NULL;
    };

    void clear();
    void insert(T value);
    void erase(T value);
    int count(T value);

    void print_debug(std::ostream& output);

protected:
private:



    class Node
    {
    public:
        Node(Node * a_up, T a_value):
            left(NULL),
            right(NULL),
            up(a_up),
            value(a_value) {}
        virtual ~Node()
        {
            delete left;
            delete right;
        }

        Node* left;
        Node* right;
        Node* up;
        T value;
    };

    void insert(Node* node, T a_value);
    void print_debug(std::ostream& output, Node* node, int indent);
    void print_debug_sorted(std::ostream& output, Node* node);
    Node* find(Node* node, T a_value);
    Node* m_root;
    size_t m_size;

};

#include "../src/sorted_binary_tree.cpp"

#endif // SORTEDBINARYTREE_H
