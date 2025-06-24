# Leetcode 2891
# In Pandas, method chaining enables us to perform operations on a DataFrame without breaking up each operation into a separate line or creating multiple temporary variables. 
# Chaining Operations: Performing multiple operations on a DataFrame in a single line by connecting methods with dots. 
import pandas as pd
def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    filtered_animals = animals[animals["weight"] > 100]
    sorted_animals = filtered_animals.sort_values(by = "weight", ascending = False)
    new_name = sorted_animals[["name"]] # By using double square brackets [['name']], we select only this column. 
    # The double brackets ensure that the result is a DataFrame and not a Series.
    return new_name

# Using Multiple Chaining
import pandas as pd
def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals[animals['weight'] > 100].sort_values(by='weight', ascending=False)[['name']]
