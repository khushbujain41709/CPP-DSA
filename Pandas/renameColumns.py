# Leetcode 2885
# Remember, this function rename doesn't change the original DataFrame, but instead returns a new DataFrame with renamed columns. If you wish to modify the original DataFrame, you can set the inplace argument to True when calling the rename method. That's why we used students = students.rename()
import pandas as pd
def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    students = students.rename(
        columns = {
            "id": "student_id",
            "first": "first_name",
            "last": "last_name",
            "age": "age_in_years"
        }
    )
    return students

def renameColumns2(students: pd.DataFrame) -> pd.DataFrame:
    students.rename(
        columns = {
            "id": "student_id",
            "first": "first_name",
            "last": "last_name",
            "age": "age_in_years"
        }
        , inplace = True
    )
    return students