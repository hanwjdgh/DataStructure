# Queue

FIFO(First In First Out)

* push(element) : Add the element to queue(end)
* pop() : Delete the element in queue(front)
* front() : Return the element at the front of the queue
* back() : Return the element at the end of the queue
* empty() : Return true if the queue is empty or false otherwise
* size() : Return queue size

## Priority queue

priority_queue <T, Container, Compare>

Compare = less : Max heap

Compare = greater : Min heap

* push(element) : Add the element to the priority queue
* pop() : Delete the element of top from the priority queue
* top() : Return the element at the front of the priority queue
* empty() : Return true if the priority queue is empty or false otherwise
* size() : Return priority queue size

## Deque

Deque(Double Ended Queue) (Reference : http://blockdmask.tistory.com/73)

* push_front() : Insert element before the first element
* pop_front() : Delete element at the front of the deque
* push_back() : Insert element after last element
* pop_back() : Delete element at the end of the deque
