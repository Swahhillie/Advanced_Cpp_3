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
    clear();
}
template <class T>
void SortedBinaryTree<T>::clear()
{
    //delete all the nodes
    DeleteSubtree(m_root);
    m_root = NULL;
    m_size = 0;
}
template <class T>
void SortedBinaryTree<T>::DeleteSubtree(Node* node){
    if(node != NULL){
        DeleteSubtree(node->left);
        DeleteSubtree(node->right);
        delete node;
    }

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
    m_root = erase(m_root, value);
}


template <class T>
typename SortedBinaryTree<T>::Node*  SortedBinaryTree<T>::erase(Node* root, T value)
{
    //http://www.algolist.net/Data_structures/Binary_search_tree/Removal
    //https://www.youtube.com/watch?v=gcULXE7ViZw

    if(root == NULL) return root;
    else if(value < root->value) root->left = erase(root->left, value);
    else if (value > root->value) root->right = erase(root->right, value);
    else
    {
        //case 1: no children
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            m_size--;
        }
        //case 2: 1 child
        else if(root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
            m_size--;
        }
        else if(root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
            m_size--;
        }
        //case 3: 2 children
        else{
            Node* temp = begin(root->right);
            root->value = temp->value;
            root->right = erase(root->right, temp->value);

        }
    }
    return root;

}



template <class T>
void SortedBinaryTree<T>::erase(const iterator& it)
{
    if(it.current >= 0)
    {
        erase(*it);
    }
}
template <class T>
int SortedBinaryTree<T>::count(T value)const
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
typename SortedBinaryTree<T>::Node* SortedBinaryTree<T>::find(Node* node, T value)const
{

    if(node == NULL)return NULL;

    if(value < node->value)
    {
        return find(node->left, value);
    }
    else if (value == node->value)
    {
        return node;
    }
    else
    {
        return find(node->right,value);
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
