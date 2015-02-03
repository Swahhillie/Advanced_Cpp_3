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
        m_root = new Node(value);
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
    erase(m_root, value, NULL);
}


template <class T>
void SortedBinaryTree<T>::erase(Node* root, T value, Node* parent)
{
    //http://www.algolist.net/Data_structures/Binary_search_tree/Removal

    //find the first node with the value
    if(Node* to_delete = find(root, value, parent))
    {

        //case 1: no children
        if(!to_delete->left && !to_delete->right)
        {
            if(parent)
            {
                if(parent->left == to_delete)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            else
            {
                m_root = NULL;
            }
            delete to_delete;
            m_size --;
        }
        //case 3: 2 children
        else if(to_delete->left && to_delete->right)
        {

            Node* min_node = begin(to_delete->right);
            to_delete->value = min_node->value; //duplicate value
            //run remove on the right sub tree to delete the duplicate value
            //the duplicate value has max 1 child.
            erase(to_delete->right, value, NULL);

        }
        //case 2: 1 child
        else
        {
            if(parent)
            {
                if(parent->left == to_delete)
                    parent->left = to_delete->left? to_delete->left : to_delete->right;
                else
                    parent->right = to_delete->left? to_delete->left : to_delete->right;
            }
            else
            {
                m_root = to_delete->left? to_delete->left : to_delete->right;
            }
            delete to_delete;
            m_size --;

        }

    }


}
template <class T>
void SortedBinaryTree<T>::erase(const iterator& it)
{
    if(it.current >= 0){
        erase(*it);
    }
}
template <class T>
int SortedBinaryTree<T>::count(T value)const
{
    int count = 0;
    Node* node = m_root;
    Node* parent = NULL;
    while((node = find(node, value, parent)))
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
            node->left = new Node(a_value);
            std::cout << "@" << node<< ": " << a_value << " <= " << node->value << std::endl;
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
            node->right = new Node(a_value);
        }
    }

}
template <class T>
void SortedBinaryTree<T>::print_debug(std::ostream& output)const
{
    //print_debug(output, m_root, 0);
    //output << "-------------------\n";
    output << "digraph G{\ngraph[ordering=\"out\"];\n";
    print_debug_sorted(output, m_root, NULL);
    output << "}";

}
template <class T>
void SortedBinaryTree<T>::print_debug(std::ostream& output, Node* node, int indent)const
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
void SortedBinaryTree<T>::print_debug_sorted(std::ostream& output, Node* node, Node* parent)const
{
    if(node != NULL)
    {
        print_debug_sorted(output, node->left, node);
        if(parent)
        {
            output << "\"" << parent << "\"" << " -> \"" << node << "\";\n";

        }
        output << "\"" << node << "\"[label=\"" << node->value << "\"];\n";
        print_debug_sorted(output, node->right, node);
    }
}
template <class T>
typename SortedBinaryTree<T>::Node* SortedBinaryTree<T>::find(Node* node, T value, Node*& parent)const
{

    if(node == NULL)return NULL;

    if(node->value == value)
    {
        return node;
    }
    if(value < node->value)
    {
        parent = node;
        return find(node->left, value, parent);
    }
    else
    {
        parent = node;
        return find(node->right,value, parent);
    }
}
template<class T>
typename SortedBinaryTree<T>::Node* SortedBinaryTree<T>::begin(Node* node)const
{
    if(node == NULL)return NULL;
    if(node->left)return begin(node->left);

    return node;
}
template<class T>
void SortedBinaryTree<T>::get_sorted(iterator& it, Node* node)const
{
    if(node != NULL)
    {
        //add all left nodes
        get_sorted(it, node->left);
        it.sorted.push_back(node);
        get_sorted(it, node->right);
    }
}

template<class T>
typename SortedBinaryTree<T>::Node* SortedBinaryTree<T>::end(Node* node)const
{
    if(node == NULL)return NULL;
    if(node->right)return end(node->right);
    return node;
}
template<class T>
typename SortedBinaryTree<T>::iterator SortedBinaryTree<T>::begin()const
{

    iterator it;
    it.sorted.reserve(m_size); // hint the amount of nodes. could prevent some allocations.
    get_sorted(it, m_root);
    it.current = it.sorted.empty()? -1 : 0;

    return it;
}
template<class T>
typename SortedBinaryTree<T>::iterator SortedBinaryTree<T>::end()const
{
    //sentinel
    return iterator();
}
