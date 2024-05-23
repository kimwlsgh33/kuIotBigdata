def main():
    s = set([1, 2, 3, 1, 2, 3])
    s.add(1)
    s.remove(1)
    s.update([1, 4, 5, 6, 7])
    s.discard(3)
    s.clear()

    s1 = set([1, 2, 3, 4, 5])
    s2 = set([3, 4, 5, 6, 7])

    # operator overloading
    s3 = s1.union(s2)
    print(s1 | s2)

    s4 = s1.intersection(s2)
    print(s1 & s2)

    s5 = s1.difference(s2)
    print(s1 - s2)

    print(f"Union s3 : {s3}")
    print(f"Intersection s4 : {s4}")
    print(f"Difference s5 : {s5}")


if __name__ == "__main__":
    main()
