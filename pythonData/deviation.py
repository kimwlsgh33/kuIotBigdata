import numpy as np
import pandas as pd
from scipy import statsmodels


def main():
    folder = "/Users/skoler/devs/projects/kuIotBigdata/pythonData/data/"
    state = pd.read_csv(folder + "state.csv")
    print(f"미국 주의 인구 표준 편차는 {state['Population'].std():.2f}이다.")
    iqr = state["Population"].quantile(0.75) - state["Population"].quantile(0.25)
    print(f"미국 주의 사분위범위(iqr) 은 {iqr} 이다.")
    mad = robust.scale.mad(state["Population"])
    print(f"미국 주의 MAD(mad) 는 {mad} 이다.")


if __name__ == "__main__":
    main()
