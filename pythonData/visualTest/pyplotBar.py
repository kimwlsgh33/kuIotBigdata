import matplotlib.pyplot as plt
import numpy as np


def main():
    data = [
        [5.0, 25.0, 50.0, 20.0],
        [4.0, 23.0, 51.0, 17.0],
        [6.0, 22.0, 52.0, 19.0],
        [5.0, 26.0, 53.0, 23.0],
    ]

    # # 바 그래프
    # X = np.arange(0,8,2)
    # plt.bar(X + 0.00, data[0], color = 'b', width = 0.50)
    # plt.bar(X + 0.50, data[1], color = 'g', width = 0.50)
    # plt.bar(X + 1.0, data[2], color = 'r', width = 0.50)
    # plt.xticks(X+0.50, ("A","B","C","D"))

    # 누적바 그래프
    data2 = np.array(data)
    color_list = np.random.choice(
        ["b", "g", "r", "y", "m", "c", "k"], data2.shape[0], replace=False
    )
    data_label = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")[: data2.shape[0]]
    X = np.arange(data2.shape[1])

    for i in range(data2.shape[0]):
        plt.bar(
            X,
            data2[i],
            bottom=np.sum(data2[:i], axis=0),
            color=color_list[i],
            label=data_label[i],
        )
    plt.legend()
    plt.show()


if __name__ == "__main__":
    main()
