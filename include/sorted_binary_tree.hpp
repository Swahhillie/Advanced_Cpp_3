#ifndef SORTEDBINARYTREE_H
#define SORTEDBINARYTREE_H
#include <iostream>
#include <vector>

template<typename T>
class SortedBinaryTree
{
    friend class iterator;
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

    private:


    class Node
    {
    public:
        Node(T a_value):
            left(NULL),
            right(NULL),
            value(a_value) {}

        Node* left;
        Node* right;
        T value;
    };

public:
// This bidirectional iterator
    // is a, public, nested, class
    class	iterator	// i.e. the Array<T>::iterator
    {
        friend class SortedBinaryTree<T>;
    private:
        iterator():current(-1)
        {

        }
        std::vector<Node*>   sorted;
        int current;		// The 'current element pointer'

    public:
        // constructor and default constructor

        // assignment operator (same as compiler generated default)
        iterator& operator=(const iterator& other)
        {
            current = other.current;
            sorted = other.sorted;
            return *this;
        }

        // infix:	xxx != yyy		(an inline helper function)
        friend  bool operator!=(const iterator& me, const iterator& other)
        {
            //todo check nodes instead of indices. but the assignment tells us not to.
            return me.current != other.current;
        }

        // infix:	xxx == yyy		(an inline helper function)
        friend  bool	operator==(const iterator& me, const iterator& other)
        {
            //todo check nodes instead of indices. but the assignment tells us not to.
            return me.current == other.current;
        }

        // prefix:	++xxx	(CHEAP)
        iterator& operator++()
        {
            //if we iterate past the last element set the current element to -1. this should compare equal to the end iterator.
            //also calling ++ on the end node should not iterate back into range.
            current = current + 1 >= sorted.size() || current == -1? -1 : current + 1;
            return *this;
        }
        // dereference:	*xxx
        // const T&  for "right-hand-side" (rhs) for read-only usage
        const	T& operator*() const
        {
            return sorted[current]->value;    // RVAL
        }

        // dereference:	xxx->member
        // const T*  for "right-hand-side" (rhs) for read-only usage
        const	T* operator->() const
        {
            return sorted[current]->value;    // RVAL
        }



    };  // iterator end
public:
    void clear();
    void insert(T value);
    //erases the first node value that compares equal to value.
    void erase(T value);
    //erases the first node value that compares equal. though it may not be the one pointed at by the iterator. /shrug
    void erase(const iterator& it);
    int count(T value)const;
    iterator begin()const;
    iterator end()const;
    void print_debug(std::ostream& output)const;

protected:


    void insert(Node* node, T value);
    Node* erase(Node* node, T value);
    void DeleteSubtree(Node* node);
    void get_sorted(iterator& it, Node* root)const;
    void print_debug(std::ostream& output, Node* node, int indent)const;
    void print_debug_sorted(std::ostream& output, Node* node, Node* parent)const;

    Node* find(Node* node, T a_value)const;
    //find the lowest value
    Node* begin(Node* node)const;
    Node* end(Node* node)const;
    Node* m_root;
    size_t m_size;

};

#include "../src/sorted_binary_tree.cpp"

#endif // SORTEDBINARYTREE_H
