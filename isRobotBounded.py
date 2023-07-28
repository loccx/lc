class Solution:
    def isRobotBounded(instructions: str) -> bool:
        dir = {'north':0, 'east':0, 'west':0, 'south':0}
        head = ['north', 'east', 'south', 'west'] #north east south west
        initDir = 0 #initial index for head
        for i in range(4):
            for n in instructions:
                if n == 'R':
                    if initDir == 3:
                        initDir = 0
                    else:
                        initDir += 1
                elif n == 'L':
                    if initDir == 0:
                        initDir = 3
                    else:
                        initDir -= 1
                if n == 'G':
                    dir[head[initDir]] += 1
        return dir['north'] == dir['south'] and dir['east'] == dir['west']


test = Solution
print(test.isRobotBounded("GLLGG"))