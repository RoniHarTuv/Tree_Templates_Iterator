// mail:Roniharpaz1@gmail.com
#ifndef TREE_HPP
#define TREE_HPP
#include "node.hpp"
#include <vector>
#include <queue>
#include <stdexcept>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <type_traits>
#include <string>
#include <sstream>
#include <map>
#include <iomanip> 
#include <algorithm>

const float NODE_RADIUS = 61.0f;

/**
 * TREE CLASS
 * A generic tree class template. By default, it represents a binary tree.
 * T = The type of the values stored in the tree nodes.
 * K = The maximum number of children per node (default is 2 for binary tree).
 */
template <typename T, int K = 2> class Tree {
private:
    Node<T> *root;                          // The root node of the tree.
    bool is_binary_tree;                    // Flag indicating if the tree is a binary tree.
    std::vector<Node<T> *> pre_order_nodes; // Nodes in pre-order traversal.
    std::vector<Node<T> *> post_order_nodes;// Nodes in post-order traversal.
    std::vector<Node<T> *> in_order_nodes;  // Nodes in in-order traversal.
    std::vector<Node<T> *> bfs_nodes;       // Nodes in breadth-first traversal.
    std::vector<Node<T> *> dfs_nodes;       // Nodes in depth-first traversal.
    std::vector<Node<T> *> heap_nodes;      // Nodes sorted in heap order.

public:
    /**
     *Default constructor 
     */
    Tree() : root(nullptr), is_binary_tree(K == 2) {}

    /**
     * Destructor 
     */
    ~Tree() {
        delete_tree(root);
    }

    /**
     * Add a root node to the tree.
     * @throws runtime_error if the root already exists.
     */
    void add_root(const Node<T> &node) {
        if (root != nullptr) {
            throw std::runtime_error("Root node already exists.");
        }
        root = new Node<T>(node.get_value());
    }

    /**
     * Add a child node to a specified parent node.
     * @throws runtime_error if the root is not found, the parent node is not found, or the parent has reached the maximum number of children.
     */
    void add_sub_node(const Node<T> &parent, const Node<T> &child) {
        if (root == nullptr) {
            throw std::runtime_error("Root node not found.");
        }
        Node<T>* parent_ptr = find_node(root, parent.get_value());
        if (parent_ptr == nullptr) {
            throw std::runtime_error("Parent node not found.");
        }
        if (parent_ptr->get_children().size() == static_cast<size_t>(K)) {
            throw std::runtime_error("Error: maximum number of children.");
        }
        parent_ptr->add_child(child);
    }

    /**
     * Get the root node of the tree.
     */
    Node<T>* getRoot() const {
        return root;
    }

    /**
     * Get an iterator to the beginning of the pre-order traversal.
     * An iterator to the first node in the pre-order traversal.
     */
    typename std::vector<Node<T> *>::iterator begin_pre_order() {
        if (K != 2) {
            return begin_dfs_scan();
        }
        pre_order_nodes.clear();
        pre_order_helper(root, pre_order_nodes);
        return pre_order_nodes.begin();
    }

    /**
     * Get an iterator to the end of the pre-order traversal.
     * An iterator to the end of the pre-order traversal.
     */
    typename std::vector<Node<T> *>::iterator end_pre_order() {
        if (K != 2) {
            return end_dfs_scan();
        }
        return pre_order_nodes.end();
    }

    /**
     * Get an iterator to the beginning of the post-order traversal.
     * An iterator to the first node in the post-order traversal.
     */
    typename std::vector<Node<T> *>::iterator begin_post_order() {
        if (K != 2) {
            return begin_dfs_scan();
        }
        post_order_nodes.clear();
        post_order_helper(root, post_order_nodes);
        return post_order_nodes.begin();
    }

    /**
     * Get an iterator to the end of the post-order traversal.
     * An iterator to the end of the post-order traversal.
     */
    typename std::vector<Node<T> *>::iterator end_post_order() {
        if (K != 2) {
            return end_dfs_scan();
        }
        return post_order_nodes.end();
    }

    /**
     * Get an iterator to the beginning of the in-order traversal.
     * An iterator to the first node in the in-order traversal.
     */
    typename std::vector<Node<T> *>::iterator begin_in_order() {
        if (K != 2) {
            return begin_dfs_scan();
        }
        in_order_nodes.clear();
        in_order_helper(root, in_order_nodes);
        return in_order_nodes.begin();
    }

    /**
     * Get an iterator to the end of the in-order traversal.
     * An iterator to the end of the in-order traversal.
     */
    typename std::vector<Node<T> *>::iterator end_in_order() {
        if (K != 2) {
            return end_dfs_scan();
        }
        return in_order_nodes.end();
    }

    /**
     * Get an iterator to the beginning of the breadth-first traversal.
     * An iterator to the first node in the breadth-first traversal.
     */
    typename std::vector<Node<T> *>::iterator begin_bfs_scan() {
        bfs_nodes.clear();
        bfs_helper(root, bfs_nodes);
        return bfs_nodes.begin();
    }

    /**
     * Get an iterator to the end of the breadth-first traversal.
     * An iterator to the end of the breadth-first traversal.
     */
    typename std::vector<Node<T> *>::iterator end_bfs_scan() {
        return bfs_nodes.end();
    }

    /**
     * Get an iterator to the beginning of the depth-first traversal.
     * An iterator to the first node in the depth-first traversal.
     */
    typename std::vector<Node<T> *>::iterator begin_dfs_scan() {
        dfs_nodes.clear();
        dfs_helper(root, dfs_nodes);
        return dfs_nodes.begin();
    }

    /**
     * Get an iterator to the end of the depth-first traversal.
     * An iterator to the end of the depth-first traversal.
     */
    typename std::vector<Node<T> *>::iterator end_dfs_scan() {
        return dfs_nodes.end();
    }
    
    /**
     * Get an iterator to the beginning of the heap ordered nodes.
     * An iterator to the first node in the heap order.
     */
    typename std::vector<Node<T> *>::iterator begin_heap() {
        heap_nodes.clear();
        myHeap(root, heap_nodes);
        return heap_nodes.begin();
    }

    /**
     * Get an iterator to the end of the heap ordered nodes.
     * An iterator to the end of the heap order.
     */
    typename std::vector<Node<T> *>::iterator end_heap() {
        return heap_nodes.end();
    }

private:
    void pre_order_helper(Node<T> *node, std::vector<Node<T> *> &result) {
        if (node == nullptr)
            return;
        result.push_back(node);
        for (auto child : node->get_children()) {
            pre_order_helper(child, result);
        }
    }

    void post_order_helper(Node<T> *node, std::vector<Node<T> *> &result) {
        if (node == nullptr)
            return;
        for (auto child : node->get_children()) {
            post_order_helper(child, result);
        }
        result.push_back(node);
    }

    void in_order_helper(Node<T> *node, std::vector<Node<T> *> &result) {
        if (node == nullptr)
            return;

        auto children = node->get_children();
        if (children.size() > 0) {
            in_order_helper(children[0], result); // Left child
        }
        result.push_back(node); // Root
        if (children.size() > 1) {
            in_order_helper(children[1], result); // Right child
        }
    }

    void bfs_helper(Node<T> *node, std::vector<Node<T> *> &result) {
        if (node == nullptr)
            return;
        std::queue<Node<T> *> q;
        q.push(node);
        while (!q.empty()) {
            Node<T> *current = q.front();
            q.pop();
            result.push_back(current);
            for (auto child : current->get_children()) {
                q.push(child);
            }
        }
    }

    void dfs_helper(Node<T> *node, std::vector<Node<T> *> &result) {
        if (node == nullptr)
            return;
        result.push_back(node);
        for (auto child : node->get_children()) {
            dfs_helper(child, result);
        }
    }
    
    void myHeap(Node<T> *node, std::vector<Node<T> *> &result) {
        if (node == nullptr)
            return;
        dfs_helper(node, result);
        auto comp = [](Node<T> *lhs, Node<T> *rhs) { return lhs->get_value() > rhs->get_value(); };
        std::make_heap(result.begin(), result.end(), comp);
        //std::sort_heap(result.begin(), result.end(), comp);
    }

    void delete_tree(Node<T> *node) {
        if (node == nullptr)
            return;
        for (auto child : node->get_children()) {
            delete_tree(child);
        }
        delete node;
    }

    Node<T> *find_node(Node<T> *node, const T &value) {
        if (node == nullptr)
            return nullptr;
        if (node->get_value() == value)
            return node;
        for (auto child : node->get_children()) {
            Node<T> *found = find_node(child, value);
            if (found != nullptr)
                return found;
        }
        return nullptr;
    }

    friend std::ostream &operator<<(std::ostream &os, Tree<T, K> &tree) {
        Node<T> *root = tree.getRoot();

        if (root == nullptr) {
            os << "Error: Tree is empty." << std::endl;
            return os;
        }
        os << "Generate GUI..." << std::endl;

        sf::Font font;
        if (!font.loadFromFile("ALBAS.TTF")) {
            std::cerr << "Failed to load font file " << std::endl;
            return os;
        }
        sf::RenderWindow window(sf::VideoMode(800, 800), "**********MY_TREE**********");
        window.setVerticalSyncEnabled(true); // Attempt to enable vertical sync

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::Black);
            tree.drawTree(window, font);
            window.display();
        }
        return os;
    }

    void drawTree(sf::RenderWindow &window, sf::Font &font) {
        if (this->root == nullptr) return;

        // Create a map to store positions of each node
        std::map<Node<T>*, sf::Vector2f> positions;
        float start_x = window.getSize().x / 2;
        float start_y = NODE_RADIUS * 2;
        float horizontal_spacing = window.getSize().x / 2.5; // Increased horizontal spacing
        calculate_positions(this->root, positions, start_x, start_y, horizontal_spacing);

        for (auto &entry : positions) {
            draw_node(window, entry.first, entry.second, font, positions);
        }
    }

    void calculate_positions(Node<T> *node, std::map<Node<T>*, sf::Vector2f> &positions, float x, float y, float horizontal_spacing) {
        if (node == nullptr) return;

        positions[node] = sf::Vector2f(x, y);
        float child_x = x - ((node->get_children().size() - 1) * horizontal_spacing / 2);
        float child_y = y + NODE_RADIUS * 3; // Increased vertical spacing

        for (auto child : node->get_children()) {
            calculate_positions(child, positions, child_x, child_y, horizontal_spacing / 2);
            child_x += horizontal_spacing;
        }
    }

    void draw_node(sf::RenderWindow &window, Node<T> *node, sf::Vector2f position, sf::Font &font, const std::map<Node<T>*, sf::Vector2f> &positions) {
        sf::CircleShape circle(NODE_RADIUS);
        circle.setFillColor(sf::Color::Magenta);
        circle.setOrigin(NODE_RADIUS, NODE_RADIUS);
        circle.setPosition(position);

        sf::Text text;
        text.setFont(font);
        if constexpr (std::is_same<T, std::string>::value) {
            text.setString(node->get_value());
        } else {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(1) << node->get_value();
            text.setString(oss.str());
        }
        text.setCharacterSize(25);
        text.setFillColor(sf::Color::Black);
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
        text.setPosition(position);

        window.draw(circle);
        window.draw(text);

        for (auto child : node->get_children()) {
            sf::Vertex line[] = {
                sf::Vertex(position),
                sf::Vertex(positions.at(child))
            };
            window.draw(line, 2, sf::Lines);
        }
    }
};

#endif // TREE_HPP
