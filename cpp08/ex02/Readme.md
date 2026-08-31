# CPP08 - Exercise 02: MutantStack

## Goal

`std::stack` is a container adapter that follows the **LIFO** rule:

> Last In, First Out

Example:

```cpp
std::stack<int> s;

s.push(5);
s.push(17);
s.push(3);

s.top(); // 3
```

The problem is that `std::stack` **cannot be iterated**:

```cpp
s.begin(); // ❌
s.end();   // ❌
```

The goal of this exercise is to create a `MutantStack` that behaves like a normal `std::stack`, but also supports **iterators**.

---

## How does it work?

We inherit from `std::stack`:

```cpp
template <typename T>
class MutantStack : public std::stack<T>
```

This gives `MutantStack` all the normal stack functions:

```text
push()
pop()
top()
size()
empty()
```

We then add:

```text
begin()
end()
```

---

## The important part

`std::stack` uses another container internally.

By default, it is a `std::deque`.

Conceptually:

```text
MutantStack
     ↓
std::stack
     ↓
underlying container
     ↓
std::deque
```

The underlying container has iterators, so we use them.

First, we define the iterator type:

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
```

This means:

> `iterator` is the iterator type of the stack's underlying container.

Then:

```cpp
iterator begin()
{
    return this->c.begin();
}

iterator end()
{
    return this->c.end();
}
```

`c` is the underlying container used by `std::stack`.

---

## Simple implementation

```cpp
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }
};

#endif
```

---

## Using MutantStack

```cpp
MutantStack<int> mstack;

mstack.push(5);
mstack.push(17);
mstack.push(3);
mstack.push(42);

MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();

while (it != ite)
{
    std::cout << *it << std::endl;
    ++it;
}
```

Now we can:

```text
push / pop / top       → normal stack behavior
begin / end            → iteration
```

## In one sentence

**MutantStack = `std::stack` + iterators.**

We inherit the normal stack functionality and expose the iterators of its underlying container.

The exercise specifically requires the normal `std::stack` member functions plus this additional iterator feature.
