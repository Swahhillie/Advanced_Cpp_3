#include "sorted_binary_tree.hpp"
#include <assert.h>
#include <iostream>
#include <iomanip>

template <class T>
SortedBinaryTree<T>::SortedBinaryTree():
    m_root(NULL),
    m_size(0)
{

}
template <class T>
SortedBinaryTree<T>::~SortedBinaryTree()
{
    delete m_root;
    m_root = NULL;
}
template <class T>
void SortedBinaryTree<T>::clear()
{
    delete m_root;
    m_root = NULL;
    m_size = 0;
}
template <class T>
void SortedBinaryTree<T>::insert(T value)
{
    if(m_size == 0)
    {
        m_root = new Node(NULL, value);
        std::cout << "root = " << value << "\n";
    }
    else
    {
        insert(m_root, value);
    }
    m_size++;
}

template <class T>
void SortedBinaryTree<T>::erase(T value)
{
    //find the first node with the value
    if(Node* to_delete = find(m_root, value))
    {
        if(to_delete->right)
        {
            //find the smallest node that is bigger than the node to delete.
            Node* replacement = to_delete->right;
            while(replacement->left || replacement->right)
            {
                replacement = replacement->left? replacement->left : replacement->right;
            }

            //make the up node of the node to delete point to the replacement node.
            if(to_delete->up)
            {
                if     (to_delete->up->right == to_delete)to_delete->up->right = replacement;
                else if(to_delete->up->left == to_delete)to_delete->up->left = replacement;
            }
            else{
                m_root = replacement;
            }

            //Make the replacement node point to the original leaves of the node to delete
            replacement->left = to_delete->left;
            replacement->right = to_delete->right;
        }
        else
        {
            if(to_delete->up)
            {
                if     (to_delete->up->right == to_delete)to_delete->up->right = to_delete->left;
                else if(to_delete->up->left == to_delete)to_delete->up->left = to_delete->left;
            }
            else{
                m_root = to_delete->left;
            }
        }
        //Delete the node, make sure it has no leaf nodes.
        to_delete->up = NULL;
        to_delete->left = NULL;
        to_delete->right = NULL;
        delete to_delete;
        m_size --;
    }


}
template <class T>
int SortedBinaryTree<T>::count(T value)
{
    int count = 0;
    Node* node = m_root;
    while((node = find(node, value)))
    {
        count ++;
        node = node->left;
    }
    return count;
}
template <class T>
void SortedBinaryTree<T>::insert(Node* node, T a_value)
{
    assert(node != NULL);
    if(a_value <= node->value)
    {
        if(node->left)
        {
            insert(node->left, a_value);
        }
        else
        {
            node->left = new Node(node, a_value);
            std::cout << "@" << node<< ": " << a_value << " < " << node->value << std::endl;
        }
    }
    else
    {
        if(node->right)
        {
            insert(node->right, a_value);
        }
        else
        {
            std::cout << "@" << node<< ": " << a_value << " > " << node->value << std::endl;
            node->right = new Node(node, a_value);
        }
    }

}
template <class T>
void SortedBinaryTree<T>::print_debug(std::ostream& output)
{
    print_debug(output, m_root, 0);
    output << "-------------------\n";
    output << "digraph G{\ngraph[ordering=\"out\"];\n";
    print_debug_sorted(output, m_root);
    output << "}";

}
template <class T>
void SortedBinaryTree<T>::print_debug(std::ostream& output, Node* node, int indent)
{
    if(node != NULL)
    {
        if(node->left) print_debug(output, node->left, indent+4);
        if(node->right) print_debug(output, node->right, indent+4);
        if (indent)
        {
            output << std::setw(indent) << ' ';
        }
        output << node->value << "\n ";
    }
}
template <class T>
void SortedBinaryTree<T>::print_debug_sorted(std::ostream& output, Node* node)
{
    if(node != NULL)
    {
        print_debug_sorted(output, node->left);
        if(node->up)
        {
            output << node->up << " -> " << node << ";\n";
        }
        print_debug_sorted(output, node->right);
    }
}
template <class T>
typename SortedBinaryTree<T>::Node* SortedBinaryTree<T>::find(Node* node, T value)
{
    if(node == NULL)return NULL;

    if(node->value == value)
    {
        return node;
    }
    if(value < node->value)
    {
        return find(node->left, value);
    }
    else
    {
        return find(node->right,value);
    }
}
