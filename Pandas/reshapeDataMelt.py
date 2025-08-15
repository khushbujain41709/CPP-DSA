# Leetcode 2890
# Pandas' melt function is used to transform or reshape data. It changes the DataFrame from a wide format, where columns represent multiple variables, to a long format, where each row represents a unique variable.
import pandas as pd
def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    report = report.melt(
        id_vars=["product"],
        value_vars=["quarter_1", "quarter_2", "quarter_3", "quarter_4"],
        var_name="quarter",
        value_name="sales"
    )
    return report