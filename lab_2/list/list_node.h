#ifndef LIST_NODE_H
#define LIST_NODE_H

#include "errors.h"

template <typename T>
class ListNode
{
public:
    ListNode() noexcept;
    ListNode(const T &data) noexcept;
    ListNode(const std::shared_ptr<ListNode<T>> &node) noexcept;

    ~ListNode() = default;

    void set(const T &data) noexcept;
    void set_next(const ListNode<T> &node);
    void set_next(const std::shared_ptr<ListNode<T>> &node);
    void set_null() noexcept;

    T& get() noexcept;
    const T& get() const noexcept;

    std::shared_ptr<ListNode<T>> get_next() const noexcept;

    bool operator==(const std::shared_ptr<ListNode<T>> &node) const noexcept;
    bool operator!=(const std::shared_ptr<ListNode<T>> &node) const noexcept;

private:
    T data;
    std::shared_ptr<ListNode<T>> next;
};

#include "list_node.hpp"

#endif