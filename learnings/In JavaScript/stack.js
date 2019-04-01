/* Stacks */

// functions : push, pop, peek, size
// Stack class
class Stack {
  constructor() {
    this.count = 0;
    this.items = {};
  }

  push(value) {
    this.items[this.count] = value;
    this.count++;
  }

  pop() {
    if (this.count === 0) return "Underflow";
    this.count--;
    let result = this.items[this.count];
    delete this.items[this.count];
    return result;
  }

  size() {
    return this.count;
  }

  // Returns the value at the end of the stack
  peek() {
    return this.items[this.count - 1];
  }

  isEmpty() {
    for (var key in this.items) {
      if (this.items.hasOwnProperty(key)) return false;
    }
    return true;
  }

  toString() {
    let str = "";
    Object.keys(this.items).forEach(item => {
      str = str + " " + this.items[item];
    });
    return str;
  }
}

let stack = new Stack();
stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);

console.log(stack.peek());
console.log(stack.isEmpty());
console.log(stack.toString());
