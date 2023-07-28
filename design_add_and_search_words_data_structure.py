class WordDictionary:
    def __init__(self):
        self.head = {}

    def addWord( self, word: str ) -> None:
        head = self.head
        for char in word:
            if char not in head:
                head[char] = {}
            head = head[char]
        head["END"] = {}

    def search( self, word: str ) -> bool:
        head = self.head
        return self.dfs( word, head, 0 )

    def dfs( self, word, curr, idx ):
        if idx < len( word ):
            if word[idx] == ".":
                for key in curr:
                    if self.dfs( word, curr[key], idx + 1 ):
                        return True
                return False
            if word[idx] not in curr:
                return False
        if idx == len( word ):
            return 'END' in curr
        curr = curr[word[idx]]
        return self.dfs( word, curr, idx + 1 )

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
