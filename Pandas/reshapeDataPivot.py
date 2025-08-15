# Leetcode 2889
# Pivoting a table means reshaping it in such a way that you convert a long-format table into a wide-format table.
import pandas as pd
def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    ans = weather.pivot(index="month", columns="city", values="temperature")
    return ans