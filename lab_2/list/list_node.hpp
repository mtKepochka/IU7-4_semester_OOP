#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

template <typename T>
ListNode<T>::ListNode() noexcept
{
    this->next = nullptr;
};

template <typename T>
ListNode<T>::ListNode(const T &data) noexcept
{
    this->data = data;
    this->next = nullptr;
};

template <typename T>
ListNode<T>::ListNode(const std::shared_ptr<ListNode<T>> &node) noexcept
{
    this->next = node->next;
    this->data = node->data;
};

template <typename T>
void ListNode<T>::set(const T &data) noexcept
{
    this->data = data;
};

template <typename T>
void ListNode<T>::set_next(const ListNode<T> &node)
{
    std::shared_ptr<ListNode<T>> node_ptr(node);
    this->next = node_ptr;
};

template <typename T>
void ListNode<T>::set_next(const std::shared_ptr<ListNode<T>> &node)
{
    this->next = node;
};

template <typename T>
void ListNode<T>::set_null() noexcept
{
    this->next = nullptr;
};

template <typename T>
T &ListNode<T>::get() noexcept
{
    return this->data;
};

template <typename T>
const T &ListNode<T>::get() const noexcept
{
    return this->data;
};

template <typename T>
std::shared_ptr<ListNode<T>> ListNode<T>::get_next() const noexcept
{
    return this->next;
};

template <typename T>
bool ListNode<T>::operator==(const std::shared_ptr<ListNode<T>> &node) const noexcept
{
    return this == node;
};

template <typename T>
bool ListNode<T>::operator!=(const std::shared_ptr<ListNode<T>> &node) const noexcept
{
    return this != node;
};

#endif