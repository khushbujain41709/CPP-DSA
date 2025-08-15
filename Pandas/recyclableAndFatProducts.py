# Leetcode 1757
import pandas as pd
def find_products(products: pd.DataFrame) -> pd.DataFrame:
    df = products[(products["low_fats"] == 'Y') & (products["recyclable"] == 'Y')]
    df = df[["product_id"]] 
    #  we need to select only the desired column product_id from df using double square brackets.
    return df