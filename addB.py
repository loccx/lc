class Solution:
    def addBinary(self, a, b):
        result = ''
        carry = 0
        
        a, b = a[::-1], b[::-1]
        for n in range(max(len(a), len(b))):
            aDig = ord(a[n]) - ord('0') if n < len(a) else 0
            bDig = ord(b[n]) - ord('0') if n < len(b) else 0

            num = aDig + bDig + carry #this is the numerical total of the binary
            char = str(num % 2) #convert the number into a character, through mod, since 1,3 becomes 1 and 2 becomes 0
            result = char + result #add the letter to the final result
            carry = num//2 #removes decimal after division by 2, trick 

        if carry:
            result = '1' + result
        return result
