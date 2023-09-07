class Node:
    def __init__(self, url: str):
        self.next = None
        self.prev = None
        self.url = url

class BrowserHistory:
    def __init__(self, homepage: str):
        self.curr = Node(homepage)

    def visit(self, url: str) -> None:
        prev = self.curr
        newCurr = Node(url)
        prev.next = newCurr
        newCurr.prev = prev
        self.curr = newCurr

    def back(self, steps: int) -> str:
        while steps > 0 and curr.prev:
            self.curr = curr.prev
        return self.curr.url

    def forward(self, steps: int) -> str:
        while steps > 0 and curr.next:
            self.curr = curr.next
        return self.curr.url

# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
