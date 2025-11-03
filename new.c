#include <stdio.h>

#define MAX 100   // maximum number of elements in heap

int heap[MAX];
int size = 0;     // current number of elements in heap

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up — used during insertion
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    // While we haven’t reached root and parent is smaller than child
    if (index > 0 && heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);  // recursively move up
    }
}

// Heapify Down — used during deletion
void heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    // Find the largest among node, left child, and right child
    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    // If the largest isn’t the parent, swap and continue down
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

// Insert an element into the heap
void insert(int value) {
    if (size == MAX) {
        printf("Heap is full!\n");
        return;
    }

    heap[size] = value;  // place new value at end
    heapifyUp(size);     // fix heap property upwards
    size++;
}

// Delete and return the maximum element (root)
int deleteMax() {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[size - 1];  // move last element to root
    size--;
    heapifyDown(0);            // fix heap property downwards

    return max;
}

// Display the heap array
void display() {
    printf("Heap array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Main function
int main() {
    insert(20);
    insert(15);
    insert(30);
    insert(5);
    insert(10);
    insert(25);

    printf("Initial heap:\n");
    display();

    printf("\nAfter deleting max:\n");
    printf("Deleted element: %d\n", deleteMax());
    display();

    printf("\nAfter inserting 40:\n");
    insert(40);
    display();

    return 0;
}
