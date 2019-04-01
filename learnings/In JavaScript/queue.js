// Queue
// Functions: enqueue(item), dequeue(), front(), isEmpty(), toString()

class Queue {
  constructor() {
    this.items = [];
  }

  // Adding Element to the queue to the back
  enqueue(item) {
    this.items.push(item);
  }

  // Remove an element from front of item array
  dequeue() {
    if (this.isEmpty()) return "Underflow";
    return this.items.shift();
  }

  // Returns the front element of the queue
  front() {
    if (this.isEmpty()) return "No Element in this Queue";
    return this.items[0];
  }

  // Return true if the queue is empty
  isEmpty() {
    return this.items.length === 0;
  }

  toString() {
    let string = "";
    for (let i = 0; i < this.items.length; i++) {
      string += this.items[i] + ", ";
    }
    return string;
  }
}

let q = new Queue();
console.log(q.isEmpty());

q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);

console.log(q.front());
q.dequeue();
console.log(q.toString());
