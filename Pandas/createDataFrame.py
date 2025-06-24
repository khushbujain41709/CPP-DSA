# Leetcode 2877
import pandas as pd
def createDataframe(student_data: list[list[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data,columns = ["student_id","age"])
student_data = [
  [1, 15],
  [2, 11],
  [3, 11],
  [4, 20]
]