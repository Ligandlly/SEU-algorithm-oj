import queue

line_number = int(input())
for _ in range(line_number):
    v_number, e_number = map(int, input().split(" "))

    graph = queue.PriorityQueue(20000)
    s = set()
    for _ in range(e_number):
        u, v, w= map(int, input().split(' '))
        graph.put((u, v, w), w)
    
    if v_number > e_number + 1:
        print(-1)
    else:
        result = 0
        while len(s) != v_number:
            edge = graph.get()
            if edge[0] not in s or edge[1] not in s:
                result += edge[2]
                s.add(edge[0])
                s.add(edge[1])
        print(result)
