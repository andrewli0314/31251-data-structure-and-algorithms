function HashTable() {
  this.size = 0;
  this.dataStore = {};
}

HashTable.prototype.toString = function() {
  return String(this.dataStore);
};

HashTable.prototype.remove = function(key) {
  if (this.dataStore.hasOwnProperty(key)) {
    delete this.dataStore[key];
    this.size--;
    return this.dataStore;
  }
};

HashTable.prototype.size = function() {
  return this.size;
};

HashTable.prototype.put = function(key, value) {
  if (this.dataStore.hasOwnProperty(key)) {
    throw new Error('Hash Store cannot contain duplicates');
  } else {
    this.dataStore[key] = value;
    this.size += 1;
    return this.dataStore;
  }
};

HashTable.prototype.enumerate = function() {
  for (let el in this.dataStore) {
    console.log(el + ' ' + this.dataStore[el]);
  }
};

HashTable.prototype.isEmpty = function() {
  return this.size > 0 ? false : true;
};

HashTable.prototype.clear = function() {
  this.dataStore = {};
  this.size = 0;
  return this.dataStore;
};

HashTable.prototype.contains = function(key) {
  if (this.dataStore.hasOwnProperty(key)) {
    return true;
  }
  return false;
};

var ht = new HashTable();
console.log(ht.put('color', 'Redd'));
