#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"

using namespace std;
int main()
{
    /**
     * Binary Tree :
     **/
    Node<double> root_node = Node<double>(1.1);
    Tree<double> tree;
    tree.add_root(root_node);

    Node<double> n1 = Node<double>(1.2);
    Node<double> n2 = Node<double>(1.3);
    Node<double> n3 = Node<double>(1.4);
    Node<double> n4 = Node<double>(1.5);
    Node<double> n5 = Node<double>(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // Print various traversals
    cout << "Pre-Order Traversal:" << endl;
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << (*node)->get_value() << endl;
    }

    cout << "Post-Order Traversal:" << endl;
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << (*node)->get_value() << endl;
    }

    cout << "In-Order Traversal:" << endl;
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << (*node)->get_value() << endl;
    }

    cout << "BFS Traversal:" << endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << (*node)->get_value() << endl;
    }

    cout << "DFS Traversal:" << endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << (*node)->get_value() << endl;
    }

    cout << "HEAP Traversal:" << endl;
    for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
    {
        cout << (*node)->get_value() << endl;
    }
    cout << tree << endl;
    /**
     * Three-Ary Tree :
     */

    Tree<int, 3> three_ary_tree;
    Node<int> int_root_node = Node<int>(1);
    three_ary_tree.add_root(int_root_node);

    Node<int> int_n1 = Node<int>(2);
    Node<int> int_n2 = Node<int>(3);
    Node<int> int_n3 = Node<int>(4);
    Node<int> int_n4 = Node<int>(5);
    Node<int> int_n5 = Node<int>(6);

    three_ary_tree.add_sub_node(int_root_node, int_n1);
    three_ary_tree.add_sub_node(int_root_node, int_n2);
    three_ary_tree.add_sub_node(int_root_node, int_n3);
    three_ary_tree.add_sub_node(int_n1, int_n4);
    three_ary_tree.add_sub_node(int_n2, int_n5);

    cout << "3-ary Tree DFS Traversal:" << endl;
    for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node)
    {
        cout << (*node)->get_value() << endl;
    }

    cout << "3-ary Tree BFS Traversal:" << endl;
    for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node)
    {
        cout << (*node)->get_value() << endl;
    }
    cout << three_ary_tree << endl;

    /**
     * binary tree with Complex type(see complex.hpp)
     */
    Complex c1(-1, 2);
    Complex c2(1, -4);
    Complex c3(0.3, 4);
    Complex c4(7, 1.2);
    Complex c5(-1, 2.1);
    Complex c6(9, 11);
    Complex c7(12, -1);

    Tree<Complex> complex_tree;
    Node<Complex> complex_root = Node<Complex>(c1);
    complex_tree.add_root(complex_root);
    //Node<Complex> n12 = Node<Complex>(c2);
    complex_tree.add_sub_node(complex_root, c2);
    complex_tree.add_sub_node(complex_root, c3);
    complex_tree.add_sub_node(c2, c4);
    complex_tree.add_sub_node(c2, c5);
    complex_tree.add_sub_node(c3, c6);
    complex_tree.add_sub_node(c3, c7);
    cout << complex_tree;

    /**
     * "university" Tree
     */
    string s1="University";
    string s2="Faculty";
    string s3="School";
    string s4="Department";
    string s5="Clinic";
    string s6="Rooms";
    string s7="Library";

    Tree<string,3> university_tree;
    Node<string> ss2 = Node<string>(s2);
    Node<string> ss3 = Node<string>(s3);
    Node<string> ss4 = Node<string>(s4);
    Node<string> ss5 = Node<string>(s5);
    Node<string> ss6 = Node<string>(s6);
    Node<string> ss7 = Node<string>(s7);
    Node<string> uni_root = Node<string>(s1);
    university_tree.add_root(uni_root);
    university_tree.add_sub_node(uni_root,ss2);
    university_tree.add_sub_node(ss2,ss3);
    university_tree.add_sub_node(ss3,ss4);
    cout << university_tree;
    return 0;
}

// The binary tree should look like:
/**
 *       root = 1
 *     /   |   \
 *    2    3    4
 *   /      \
 *  5        6
 */
// The treeary tree should look like:
/**
 *     root = 1.1
 *     /       \
 *    1.2      1.3
 *   /  \      /
 *  1.4  1.5  1.6
 */
