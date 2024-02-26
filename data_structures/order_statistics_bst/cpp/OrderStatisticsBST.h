// Author: Fatih Baskın
// GitHub: fthbaskin

#ifndef ORDER_STATISTICS_BST_H
#define ORDER_STATISTICS_BST_H

#include "OrderStatisticsNode.h"
#include <queue>

template <typename T>
class OrderStatisticsBST
{
private:
    OrderStatisticsNode<T> *root;

    void update_order_statistic(OrderStatisticsNode<T> *);
    OrderStatisticsNode<T> *get_minimum_helper(OrderStatisticsNode<T> *);

    void remove_helper(OrderStatisticsNode<T> *);

public:
    OrderStatisticsBST<T>();
    ~OrderStatisticsBST<T>();

    void insert(const T &);
    OrderStatisticsNode<T> *get_by_rank(int);
    OrderStatisticsNode<T> *get_by_value(const T &);

    OrderStatisticsNode<T> *get_root();
    void remove_by_rank(int);
    void remove_by_value(const T &);
};

template <typename T>
OrderStatisticsBST<T>::OrderStatisticsBST()
{
    root = nullptr;
}

template <typename T>
OrderStatisticsBST<T>::~OrderStatisticsBST()
{
    std::queue<OrderStatisticsNode<T> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        OrderStatisticsNode<T> *current = nodes.front();
        nodes.pop();

        if (current->get_left() != nullptr)
            nodes.push(current->get_left());
        if (current->get_right() != nullptr)
            nodes.push(current->get_right());

        delete current;
    }
}

template <typename T>
void OrderStatisticsBST<T>::insert(const T &data)
{
    OrderStatisticsNode<T> *new_node = new OrderStatisticsNode<T>(data);

    if (root == nullptr)
    {
        root = new_node;
        return;
    }

    OrderStatisticsNode<T> *traversal_parent = root;
    while (traversal_parent != nullptr)
    {
        if (data < traversal_parent->get_data())
        {
            if (traversal_parent->get_left() == nullptr)
            {
                traversal_parent->set_left(new_node);
                new_node->set_parent(traversal_parent);
                update_order_statistic(traversal_parent);
                break;
            }
            else
            {
                traversal_parent = traversal_parent->get_left();
            }
        }
        else
        {
            if (traversal_parent->get_right() == nullptr)
            {
                traversal_parent->set_right(new_node);
                new_node->set_parent(traversal_parent);
                update_order_statistic(traversal_parent);
                break;
            }
            else
            {
                traversal_parent = traversal_parent->get_right();
            }
        }
    }
}

template <typename T>
void OrderStatisticsBST<T>::update_order_statistic(OrderStatisticsNode<T> *node)
{
    while (node != nullptr)
    {
        int left_order_statistic = 0;
        if (node->get_left() != nullptr)
        {
            left_order_statistic = node->get_left()->get_order_statistic();
        }

        int right_order_statistic = 0;
        if (node->get_right() != nullptr)
        {
            right_order_statistic = node->get_right()->get_order_statistic();
        }

        node->set_order_statistic(left_order_statistic + right_order_statistic + 1);
        node = node->get_parent();
    }
}

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsBST<T>::get_by_rank(int rank)
{
    // Throw exception?
    if (rank < 1)
        return nullptr;

    OrderStatisticsNode<T> *traversal_node = root;
    while (traversal_node != nullptr)
    {
        int current_rank = 1;
        if (traversal_node->get_left() != nullptr)
        {
            current_rank += traversal_node->get_left()->get_order_statistic();
        }

        if (current_rank == rank)
        {
            return traversal_node;
        }
        else if (current_rank < rank)
        {
            traversal_node = traversal_node->get_right();
            rank -= current_rank;
        }
        else
        {
            traversal_node = traversal_node->get_left();
        }
    }

    return nullptr;
}

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsBST<T>::get_root() { return root; }

template <typename T>
void OrderStatisticsBST<T>::remove_by_rank(int rank)
{
    OrderStatisticsNode<T> *currentNode = get_by_rank(rank);
    remove_helper(currentNode);
}

template <typename T>
void OrderStatisticsBST<T>::remove_by_value(const T &value)
{
    OrderStatisticsNode<T> *currentNode = get_by_value(value);
    remove_helper(currentNode);
}

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsBST<T>::get_by_value(const T &value)
{
    OrderStatisticsNode<T> *traversal_node = root;
    while (traversal_node != nullptr)
    {
        if (traversal_node->get_data() == value)
        {
            return traversal_node;
        }
        else if (value < traversal_node->get_data())
        {
            traversal_node = traversal_node->get_left();
        }
        else
        {
            traversal_node = traversal_node->get_right();
        }
    }

    return nullptr;
}

template <typename T>
void OrderStatisticsBST<T>::remove_helper(OrderStatisticsNode<T> *currentNode)
{
    if (currentNode == nullptr)
        return;

    OrderStatisticsNode<T> *parent = currentNode->get_parent();
    OrderStatisticsNode<T> *left = currentNode->get_left();
    OrderStatisticsNode<T> *right = currentNode->get_right();

    // If current node is a leaf node
    if (left == nullptr && right == nullptr)
    {
        // Check if the current node is root
        if (parent == nullptr)
            // In this case set root null
            root = nullptr;

        // Otherwise set the parent's child null accordingly
        else if (parent->get_right() == currentNode)
            parent->set_right(nullptr);
        else
            parent->set_left(nullptr);

        delete currentNode;
        // Update the order statistic of the parent
        update_order_statistic(parent);
        return;
    }

    // If the right is null, then set left as the current node
    if (right == nullptr)
    {
        // Check if the current node is leaf node
        if (parent == nullptr)
            // Set root accordingly if the parent is the root
            root = currentNode->get_left();

        else if (parent->get_right() == currentNode)
            parent->set_right(left);
        else
            parent->set_left(left);

        // Update the parent of left node
        // If parent is null it will still be null
        left->set_parent(parent);
        update_order_statistic(parent);

        delete currentNode;
        return;
    }

    // Otherwise, set the right node as current node
    if (parent == NULL)
        root = right;
    else if (parent->get_right() == currentNode)
        parent->set_right(right);
    else
        parent->set_left(right);

    // Update the parent of right node
    right->set_parent(parent);

    update_order_statistic(parent);

    // Then add left subtree to leftmost of right subtree
    OrderStatisticsNode<T> *leftmost = get_minimum_helper(right);
    leftmost->set_left(left);

    // Update the parent of leftnode
    if (left != NULL)
        left->set_parent(leftmost);

    // Update the order statistic of the parent
    update_order_statistic(leftmost);

    delete currentNode;
}

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsBST<T>::get_minimum_helper(OrderStatisticsNode<T> *node)
{
    if (node == nullptr)
        return nullptr;

    while (node->get_left() != nullptr)
    {
        node = node->get_left();
    }
    return node;
}

#endif
