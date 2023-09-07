class Solution:
    def canFinish(self, numCourses, prerequisites):

        # one empty array for each course, and the array stores the prereqs needed.
        graph = [[] for _ in range(numCourses)]
        # 0 initialized for each course, represents the visit status of a course
        visit = [0 for _ in range(numCourses)]

        # course number corresponds to the index of the list in the graph that its prerequisite course value would be appended to
        for x, y in prerequisites:
            graph[x].append(y)

        def dfs(i):
            if visit[i] == -1:
                return False

            if visit[i] == 1:
                return True

            # set current one to -1, since we are visiting it right now
            visit[i] = -1

            # executes dfs on all the prerequisite courses
            for j in graph[i]:
                #THIS IS THE IDEA: if you come across a prerequisite that you have seen before, then that means there is a LOOP in the course requirements. Though this does not directly make sense, let's look at this example:
                # 1 needs 2, 2 needs 3, 3 needs 1. this example is not possible. none have been visited yet, so visit array is [0, 0, 0]. start with 1. [-1, 0, 0]. it dfs on 2, so [-1, -1, 0]. 2 dfs on 3, so [-1, -1, -1]. now, 3 dfs on 1, and boom you encounter a -1, the 1 has already been visited. therefore, it is not possible, so it's false.
                if not dfs(j):
                    return False

            # alright HERE IS THE OTHER IDEA: 1 needs 2, 2 needs 3, 3 needs 0. this is possible. start with 1->2->3->0, it becomes [-1, -1, -1, -1] -> [1, 1, 1, 1], and instead of continuing dfs calls again, it is already set to 1 because it was successful, so it saves having to run multiple calls
            visit[i] = 1
            return True

        # runs dfs on every course; if it fails, then the whole thing will never be complete, so entirely fails
        # the reason this is efficient is because dfs will finish the entire singular call before calling another one, and if that call fails or is successful, the other ones will not need to be executed. on failure, it instantly returns false and ends the function. on success, everything is set to 1 and the subsequent dfs calls end instantly since the value is 1.
        for i in range(numCourses):
            if not dfs(i):
                return False

        # true only executes once none of them could fail
        return True
