"""
Author name: Jason Berroa
Date: 2024/03/31
Program Name: BerroaJ_CookieJar.py
Purpose: Simulate a cookie jar within the terminal
"""


import sys

class Jar:
    def __init__(self, capacity=12):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity must be a non-negative integer.")
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self._size

    def deposit(self, n):
        if not isinstance(n, int) or n < 0:
            raise ValueError("Number of cookies to deposit must be a non-negative integer.")
        if self._size + n > self._capacity:
            raise ValueError("No more space in the jar.")
        self._size += n

    def withdraw(self, n):
        if not isinstance(n, int) or n < 0:
            raise ValueError("Number of cookies to withdraw must be a non-negative integer.")
        if self._size < n:
            raise ValueError("Not enough cookies in the jar.")
        self._size -= n

    @property
    def capacity(self):
        return self._capacity
     
    @capacity.setter
    def capacity(self, capacity):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError("Capacity must be a non-negative integer.")
        if capacity < self._size:
            raise ValueError("Capacity cannot be less than size.")
        self._capacity = capacity

    @property
    def size(self):
        return self._size
        
    @size.setter
    def size(self, size):
        if not isinstance(size, int) or size < 0:
            raise ValueError("Size must be a non-negative integer.")
        if size > self._capacity:
            raise ValueError("Size cannot exceed capacity.")
        self._size = size

def main():
    if len(sys.argv) != 2:
        print("Usage: python LastNameFirstInitial_CookieJar.py <capacity>")
        sys.exit(1)

    try:
        capacity = int(sys.argv[1])
    except ValueError:
        print("Command-line argument is not an integer")
        sys.exit(1)

    try:
        jar = Jar(capacity)
    except ValueError as e:
        print(e)
        sys.exit(1)

    jar.deposit(2)
    print(jar)
    print(jar.size)
    print(jar.capacity)
    
    jar.withdraw(2)
    print(jar)
    print(jar.size)
    print(jar.capacity)

    try:
        jar.size = 12
    except ValueError as e:
        print(e)

    print(jar)
    print(jar.size)

if __name__ == "__main__":
    main()
