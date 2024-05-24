import argparse
import configparser


def main():
    folder = "/home/xxxx/kuIotBigdata/pythonData"
    config = configparser.ConfigParser()
    parser = argparse.ArgumentParser()
    parser.add_argument("-a", "--a_value", dest="a integers", type=int, default=10)
    parser.add_argument("-b", "--b_value", dest="b integers", type=int)
    print(config.sections())
    config.read(folder + "example.cfg")

    print(config.sections())


if __name__ == "__main__":
    main()
