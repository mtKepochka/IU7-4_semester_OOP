#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include <iostream>
#include <memory>
#include <ctime>

#include "base_iterator.h"
#include "errors.h"

#include "list_node.h"
#include "concepts.h"

template <Comparable T>
class List;

template <typename T>
class ListIterator : public BaseIterator
{
public:
    ListIterator() noexcept;
    ListIterator(List<T> &list);
    ListIterator(const std::shared_ptr<ListNode<T>> &node) noexcept;
    ListIterator(const ListIterator<T> &iterator);

    ~ListIterator() = default;

    void next(void) override;
    bool is_invalid(void) const override;

    std::shared_ptr<ListNode<T>> operator->();
    const std::shared_ptr<ListNode<T>> operator->() const;

    T &operator*();
    const T &operator*() const;

    operator bool() const noexcept;

    ListIterator<T> &operator+=(const int &size);
    ListIterator<T> operator+(const int &size) const;
    ListIterator<T> operator=(const ListIterator<T> &iterator);
    ListIterator<T> &operator++(); //префиксный
    ListIterator<T> operator++(int); //постфиксный

    bool operator!=(const ListIterator<T> &iterator) const;
    bool operator==(const ListIterator<T> &iterator) const;

    std::shared_ptr<ListIterator<T>> get_ptr();

private:
    std::weak_ptr<ListNode<T>> ptr;
};

#include "list_iterator.hpp"

#endif