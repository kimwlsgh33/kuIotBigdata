import matplotlib.pyplot as plt
import pandas as pd


def main():
    folder = "/Users/skoler/devs/projects/kuIotBigdata/pythonData/data/"
    sp500_px = pd.read_csv(folder + "sp500_data.csv", index_col = 0)
    sp500_sym = pd.read_csv(folder + "sp500_sectors.csv")

    etfs = sp500_px.loc[sp500_px.index > "2012-07-01", sp500_sym[sp500_sym$sector=="eft", 'symbol']]
    # ax = dfw.transpose().plot.bar(figsize=(4, 4), legend=False)
    # ax.set_xlabel("Cause of delay")
    # ax.set_ylabel("Count")
    # plt.show()


if __name__ == "__main__":
    main()
