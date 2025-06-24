# Leetcode 2878
import pandas as pd
def getDataframeSize(players: pd.DataFrame) -> list[int]:
    return [players.shape[0] , players.shape[1]]