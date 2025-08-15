# Leetcode 2886
import pandas as pd
def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students = students.astype({
        "grade" : int
    })
    return students