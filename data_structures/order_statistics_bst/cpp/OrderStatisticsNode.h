// Author: Fatih Baskın
// GitHub: fthbaskin

#ifndef ORDER_STATISTICS_NODE_H
#define ORDER_STATISTICS_NODE_H

template <typename T>
class OrderStatisticsNode
{
private:
    T data;
    int order_statistic;
    OrderStatisticsNode<T> *left;
    OrderStatisticsNode<T> *right;
    OrderStatisticsNode<T> *parent;

public:
    OrderStatisticsNode(T data);

    T &get_data();
    int get_order_statistic() const;
    OrderStatisticsNode<T> *get_left() const;
    OrderStatisticsNode<T> *get_right() const;
    OrderStatisticsNode<T> *get_parent() const;

    void set_data(T);
    void set_order_statistic(int);
    void set_left(OrderStatisticsNode<T> *);
    void set_right(OrderStatisticsNode<T> *);
    void set_parent(OrderStatisticsNode<T> *);
};

template <typename T>
OrderStatisticsNode<T>::OrderStatisticsNode(T data) : data(data), order_statistic(1), left(nullptr), right(nullptr), parent(nullptr) {}

template <typename T>
T &OrderStatisticsNode<T>::get_data() { return data; }

template <typename T>
int OrderStatisticsNode<T>::get_order_statistic() const { return order_statistic; }

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsNode<T>::get_left() const { return left; }

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsNode<T>::get_right() const { return right; }

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsNode<T>::get_parent() const { return parent; }

template <typename T>
void OrderStatisticsNode<T>::set_data(T data) { this->data = data; }

template <typename T>
void OrderStatisticsNode<T>::set_order_statistic(int order_statistic) { this->order_statistic = order_statistic; }

template <typename T>
void OrderStatisticsNode<T>::set_left(OrderStatisticsNode<T> *left) { this->left = left; }

template <typename T>
void OrderStatisticsNode<T>::set_right(OrderStatisticsNode<T> *right) { this->right = right; }

template <typename T>
void OrderStatisticsNode<T>::set_parent(OrderStatisticsNode<T> *parent)
{
    this->parent = parent;
}

#endif
