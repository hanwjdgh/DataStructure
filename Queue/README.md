# Queue

FIFO(First In First Out)

<img width="500" height="110" src="https://user-images.githubusercontent.com/23069776/42672918-ca85d3fe-86a3-11e8-805b-1b6f1b768820.png"></img>

* push(element) : Add the element to queue(end)
* pop() : Delete the element in queue(front)
* front() : Return the element at the front of the queue
* back() : Return the element at the end of the queue
* empty() : Return true if the queue is empty or false otherwise
* size() : Return queue size

## Priority queue

priority_queue <T, Container, Compare>

<img width="500" height="200" src="https://user-images.githubusercontent.com/23069776/42672927-d98aa3fc-86a3-11e8-9f35-e6721f7188f8.jpg"></img>

Compare = less : Max heap

Compare = greater : Min heap

* push(element) : Add the element to the priority queue
* pop() : Delete the element of top from the priority queue
* top() : Return the element at the front of the priority queue
* empty() : Return true if the priority queue is empty or false otherwise
* size() : Return priority queue size

## Deque

Deque(Double Ended Queue) (Reference : http://blockdmask.tistory.com/73)

<img width="500" height="110" src="https://user-images.githubusercontent.com/23069776/42672940-ed1f65b0-86a3-11e8-925f-520ed4ed32aa.png"></img>

* push_front() : Insert element before the first element
* pop_front() : Delete element at the front of the deque
* push_back() : Insert element after last element
* pop_back() : Delete element at the end of the deque
