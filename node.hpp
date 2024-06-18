// mail:Roniharpaz1@gmail.com
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
/**
 * NODE CLASS
 * This class represent a Node object that the Tree object contains.
 * each Node has a value(generic) and a vector of Node* for his childrens
 */
template <typename T> class Node
{
public:
    T value;
    std::vector<Node<T> *> children;
    //constructor
    Node(T val) : value(val) {}
    //return the value of the Node
    T get_value() const { return value; }
    //add new child to rhe vector
    void add_child(const Node<T> &child)
    {
        children.push_back(new Node<T>(child));
    }
    //return the list of the childrens
    std::vector<Node<T> *> get_children() const { return children; }
};

#endif // NODE_HPP