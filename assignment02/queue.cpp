
#include "queue.h"

queue::queue() : queue_size(0),
                 front(nullptr),
                 back(nullptr)
{
}

queue::queue(const queue &q) : queue_size(q.queue_size),
                               front(nullptr), back(nullptr)
{
    if (q.front->next)
    {
        node *temp = q.front;
        while (temp)
        {
            push(temp->value);
            temp = temp->next;
        }
        back = temp;
    }
}

const queue &queue::operator=(const queue &q)
{
    if (this != &q)
    {
        clear();
        front = nullptr;
        back = nullptr;
        node *temp = q.front;
        while (temp)
        {
            push(temp->value);
            temp = temp->next;
            //std::cout <<"here\n";
        }
        back = temp;
    }
    return *this;
}

queue::~queue()
{
    clear();
}

queue::queue(std::initializer_list<std::string> init) : queue_size(0),
                                                        front(nullptr), back(nullptr)
{
    for (int i = 0; i < init.size(); i++)
    {
        push(init.begin()[i]);
    }
}

void queue::push(const std::string &s)
{
    queue_size++;
    if (back)
    {
        back->next = new node(s);
        back = back->next;
        return;
    }
    front = back = new node(s);
}

void queue::pop()
{
    if (empty())
    {
        throw std::length_error("the queue is empty");
    }
    node *temp = front;
    front = front->next;
    delete temp;
    queue_size -= 1;
}

void queue::clear()
{
    while (front)
    {
        node *temp = front;
        front = front->next;
        delete temp;
    }
    queue_size = 0;
}

// void queue::reset( size_t s );

const std::string &queue::peek() const
{
    if (empty())
    {
        throw std::length_error("the queue is empty");
    }
    return front->value;
}

size_t queue::size() const
{
    return queue_size;
}

bool queue::empty() const
{
    if (queue_size == 0)
    {
        return true;
    }
    return false;
}

void queue::print(std::ostream &out) const
{
    out << "queue: ";
    if (queue_size == 0)
    {
        out << "\n";
        return;
    }
    node *n = front;
    while (n)
    {
        out << n->value;
        if (n->next)
        {
            out << ", ";
        }
        n = n->next;
    }
    out << "\n";
    return;
}
