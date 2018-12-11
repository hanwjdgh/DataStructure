# Heap

Tree-based data structure based on the complete binary tree, designed to speed up the operation to find the maximum and minimum values.

The following heap properties are satisfied :
If A is parent node of B, there is a large(small) relationship between the key value of A and the key value of B.

## Binary Heap

* Min heap : the key at root must be minimum among all keys present in Binary Heap. </br>(priority_queue <T, Container, greater>)
<img width="500" height="200" src="https://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile26.uf.tistory.com%2Fimage%2F2420E14A577E62522833B6"></img>

* Max heap : the key at root must be maximum among all keys present in Binary Heap. </br>(priority_queue <T, Container, less>)
<img width="500" height="200" src="https://img1.daumcdn.net/thumb/R1920x0/?fname=http%3A%2F%2Fcfile28.uf.tistory.com%2Fimage%2F2240714A577E62521C8BA0"></img>

## Binomial Heap

A Binomial Heap is a set of Binomial Trees where each Binomial Tree follows Min Heap property. And there can be at most one Binomial Tree of any degree.

## Fibonacci Heap