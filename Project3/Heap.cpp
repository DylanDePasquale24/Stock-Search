#include "Heap.h"
#include <math.h>


/* ====== HEAP ======*/
pair<float, DayData> Heap::Extract() {

	pair<float, DayData> top = vec[0];
	vec[0] = vec[vec.size() - 1];
	vec.pop_back();
	HeapifyDown(0);
	return top;
}
void Heap::Insert(pair<float, DayData> data) {
	vec.push_back(data);
	HeapifyUp(vec.size() - 1);
}
Heap::~Heap() {
	vec.clear();
}

/* ====== MIN HEAP ====== */
void MinHeap::HeapifyDown(int rootIndex) {

	int leftIndex = rootIndex * 2 + 1;
	int rightIndex = rootIndex * 2 + 2;

	if (leftIndex > vec.size() - 1) {
		return;
	}


	float leftValue = vec[leftIndex].first;
	float rightValue = leftValue;

	if (rightIndex <= vec.size() - 1) {
		rightValue = vec[rightIndex].first;
	}

	int minChildIndex = leftIndex;
	if (rightValue < leftValue) {
		minChildIndex = rightIndex;
	}

	if (vec[minChildIndex].first < vec[rootIndex].first) {
		pair<float, DayData> temp = vec[rootIndex];
		vec[rootIndex] = vec[minChildIndex];
		vec[minChildIndex] = temp;
		HeapifyDown(minChildIndex);
	}
}
void MinHeap::HeapifyUp(int rootIndex) {
	int parent = floor((rootIndex - 1) / 2);

	if (rootIndex == 0) {
		return;
	}
	else if (vec[parent].first > vec[rootIndex].first){
		pair<float, DayData> temp = vec[parent];
	  vec[parent] = vec[rootIndex];
	  vec[rootIndex] = temp;
	  HeapifyUp(parent);
	}
	else {
		return;
	}

}

/* ====== MAX HEAP ====== */
void MaxHeap::HeapifyDown(int rootIndex) {

	int leftIndex = rootIndex * 2 + 1;
	int rightIndex = rootIndex * 2 + 2;

	//if reach end "tree" and no children, then you are done
	//size - 1 is new end after "deletion" of last element, so if beyond that, its a leaf node (no children)
	if (leftIndex > vec.size() - 1) {
		return;
	}


	float leftValue = vec[leftIndex].first;
	float rightValue = leftValue;

	//need to check first if there is a right value
	if (rightIndex <= vec.size() - 1) {
		rightValue = vec[rightIndex].first;
	}

	//finds the max child index and stores it's index in max
	int maxChildIndex = leftIndex;
	if (rightValue > leftValue) {
		maxChildIndex = rightIndex;
	}

	//if the greatest child is greater than root, you swap
	//otherwise you do nothing an you are done
	if (vec[maxChildIndex].first > vec[rootIndex].first) {
		pair<float, DayData> temp = vec[rootIndex];
		vec[rootIndex] = vec[maxChildIndex];
		vec[maxChildIndex] = temp;
		HeapifyDown(maxChildIndex);  //call heapify down now on the child element after     the swap
	}
}
void MaxHeap::HeapifyUp(int rootIndex) {
	int parent = floor((rootIndex - 1) / 2);

	if (rootIndex == 0) {
		return;
	}
	else if ((vec[parent].first < vec[rootIndex].first)){
	  pair<float, DayData> temp = vec[parent];
	  vec[parent] = vec[rootIndex];
	  vec[rootIndex] = temp;
	  HeapifyUp(parent);
	}
	else {
		return;
	}

}

