class Solution:
    def displayTable(self, orders):
        tables = defaultdict(dict)
        for row in orders:
            tableNum = row[1]
            item = row[2]
            if tableNum not in tables:
                for x in tables.keys():
                    tables[x][tableNum] = 0
                tables[tableNum] += 1
            elif item not in tables[tableNum]:
                tables[tableNum][item] = 1
            else:
                tables[tableNum][item] += 1
        graph = []
        tables_sorted = {k: v for k, v in sorted(tables.items())}
        print(tables)
        for entry in tables_sorted.keys():
            curr = []
            curr.append(entry)
            curr.extend(tables_sorted[entry].values())
            print(curr)



orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
test = Solution()
test.displayTable(orders)
