class LRUCache:

    def __init__(self, capacity: int):
        self.cache = {}
        self.count = 0
        self.num = capacity

    def get(self, key: int) -> int:
        if key in self.cache:
            val = self.cache.pop(key)
            self.cache[key] = val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)
        else:
            self.count += 1
        self.cache[key] = value
        if self.count > self.num:
            self.cache.pop(next(iter(self.cache)))
            count -= 1