# Leetcode 2888
# Concatenate dataframes vertically(by rows)
import pandas as pd
def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1,df2], axis = 0) # axis = 0 is default