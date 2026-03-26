class Jar:
    def __init__(self, capacity: int = 12):
        if not isinstance(capacity, int) or capacity < 0:
            raise ValueError
        self._capacity: int = capacity
        self._size: int = 0

    def __str__(self):
        return "🍪" * self._size

    def deposit(self, n: int):
        if self._size + n > self.capacity:
            raise ValueError
        self._size += n

    def withdraw(self, n: int):
        if n > self.size:
            raise ValueError
        self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size


def main():
    jar = Jar()
    # n cookies
    print(str(jar.capacity))
    # 0 cookies
    print(str(jar))

    jar.deposit(2)
    # 2 cookies
    print(str(jar))

    jar.withdraw(1)
    # 1 cookie
    print(str(jar))


main()
