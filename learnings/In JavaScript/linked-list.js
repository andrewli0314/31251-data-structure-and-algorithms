// Linked List

// functions -> size(), isEmpty(), prepend(), append(), remove(), contains()

class LinkedList {
  constructor() {
    this.head = null;
  }

  isEmpty() {
    return this.head === null;
  }

  size() {
    let current = this.head;
    let count = 0;
    while (current != null) {
      count++;
      current = current.next;
    }
    return count;
  }

  prepend(value) {
    this.head = {
      data: value,
      next: this.head
    };
  }

  append(value) {
    let newNode = {
      data: value,
      next: null
    };
    if (this.isEmpty()) {
      this.head = newNode;
      return;
    }

    let current = this.head;
    while (current.next != null) {
      current = current.next;
    }
    current.next = newNode;
  }

  contains(value) {
    let current = this.head;
    while (current !== null) {
      if (current.value === value) return true;

      current = current.next;
    }
    return false;
  }

  remove(value) {
    if (!this.contains(value)) return;

    if (this.head.data == value) {
      this.head = this.head.next;
      return;
    }

    let previous = null;
    let current = this.head;

    while (current.data !== value) {
      previous = current;
      current = current.next;
    }

    previous.next = current.next;
  }

  toString() {
    let current = this.head;
    let output = "[";

    while (current != null) {
      output += current.data;
      if (current.next !== null) output += ",";
      current = current.next;
    }
    output += "]";
    console.log(output);
  }
}

let list = new LinkedList();
list.prepend(10);
list.prepend(100);
list.append(30);
list.append(130);

list.toString();
