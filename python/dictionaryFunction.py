def main():
    student_info = {
        20140012: "Sungchul",
        20140059: "Jiyong",
        20150234: "Jaehong",
        20140058: "Wonchul",
    }
    print(type(student_info))
    # call a value by a key
    print(student_info[20140059])

    student_info[20160227] = "Jinho"

    # dictionary loop
    for key in student_info:
        print(key, student_info[key])

    # key, value and item (key & value)
    print(student_info.keys())
    print(student_info.values())
    print(student_info.items())

    for key, value in student_info.items():
        print(key, value)


if __name__ == "__main__":
    main()
