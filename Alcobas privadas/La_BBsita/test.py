
class TwoButtons():
    input = input()
    results = []
    nodes = []
    n = int(input.split()[0])
    m = int(input.split()[1])

    def __init__(self):
        self.results = []
        for x in range(20001):
            self.nodes.append(-1)
        # self.nodes = [False for x in range(100000)]
        if self.n >= self.m:
            self.results.append(self.n - self.m)
            self.get_result()
        else:
            self.way_2(self.n, 0)
            self.way_1(self.n, 0)
            self.get_result()

    def get_result(self):
        print(min(self.results))

    def both_ways(self, current, moves):
        if self.nodes[current] > moves or self.nodes[current] == -1:
            self.nodes[current] = moves
            if current >= self.m:
                self.results.append(moves + (current - self.m))
                return
            elif current > 1 and current != self.n:
                self.way_1(current, moves)
                self.way_2(current, moves)
            else:
                return

    def way_1(self, current, moves):
        current = current * 2
        moves = moves + 1
        if current >= self.m and moves not in self.results:
            self.results.append(moves + (current - self.m))
        self.both_ways(current, moves)

    def way_2(self, current, moves):
        current = current - 1
        moves = moves + 1
        if current == self.m and moves not in self.results:
            self.results.append(moves)
        self.both_ways(current, moves)

objecto = TwoButtons()