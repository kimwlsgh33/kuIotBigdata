import matplotlib.pyplot as plt
import pandas as pd


def main():
    folder = "/Users/skoler/devs/projects/kuIotBigdata/pythonData/data/"
    state = pd.read_csv(folder + "state.csv")

    binnedPopulation = pd.cut(state["Population"], 10)
    binnedPopulation.value_counts()
    print(binnedPopulation)
    print(binnedPopulation.value_counts())

    # plt.hist(state["Population"], bins=10)
    # plt.show()
    # state["Population"].plot.hist(bins=10)
    # ax1 = state["Population"].plot.hist(figsize=(1, 4), bins=10)
    # ax2 = state["Population"].plot.hist(figsize=(2, 4), bins=20)
    # ax3 = state["Population"].plot.hist(figsize=(3, 4), bins=30)
    # ax4 = state["Population"].plot.hist(figsize=(4, 4), bins=40)
    # state["Population"].plot.hist(bins=10)
    # plt.show()

    ax = state["Murder.Rate"].plot.hist(density=True, xlim=[0, 12], bins=range(1, 12))
    state["Murder.Rate"].plot.density(ax=ax)
    ax.set_xlabel("Murder Rate (per 100,000)")
    plt.show()


if __name__ == "__main__":
    main()
