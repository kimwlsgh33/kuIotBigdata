import matplotlib.pyplot as plt
import pandas as pd


def main():
    folder = "/Users/skoler/devs/projects/kuIotBigdata/pythonData/data/"
    dfw = pd.read_csv(folder + "dfw_airline.csv")
    # legend : comment on figsize
    ax = dfw.transpose().plot.bar(figsize=(4, 4), legend=False)
    ax.set_xlabel("Cause of delay")
    ax.set_ylabel("Count")
    plt.show()


if __name__ == "__main__":
    main()
