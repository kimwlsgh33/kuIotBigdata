def main():
    # f = open("yesterday.txt", "r")
    # yesterday_lyrics = f.readlines() # you can use readlines() + while loop generally
    # f.close()

    # file is automatically closed when with scope is ended
    with open("yesterday.txt", "r") as f:
        yesterday_lyrics = f.read()

    # print(yesterday_lyrics)

    # contents = ""
    # for line in yesterday_lyrics:
    # print(line)
    # contents += line.strip() + "\n"
    # contents += line
    # n_of_yesterday = contents.upper().count("YESTERDAY")

    n_of_yesterday = yesterday_lyrics.upper().count("YESTERDAY")
    print(f"Number of a word 'Yesterday' : {n_of_yesterday}")


if __name__ == "__main__":
    main()
