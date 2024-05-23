from collections import OrderedDict, defaultdict, deque


def main():
    deque_list = deque()
    for i in range(5):
        deque_list.append(i)

    print(deque_list)
    deque_list.appendleft(10)
    print(deque_list)
    deque_list.pop()
    deque_list.rotate(2)
    print(deque_list)
    deque_list.popleft()
    print(deque_list)

    d = OrderedDict()
    d["x"] = 100
    d["y"] = 200
    d["z"] = 300
    d["l"] = 500

    for k, v in d:
        print(k, v)

    # sort by key
    for k, v in OrderedDict(sorted(d.items(), key=lambda t: t[0])).items():
        print(k, v)

    # default dict
    s = [("yellow", 1), ("blue", 2), ("yellow", 3), ("blue", 4), ("red", 1)]
    d = defaultdict(list)
    for k, v in s:
        d[k].append(v)
    print(d.items())


if __name__ == "__main__":
    main()
