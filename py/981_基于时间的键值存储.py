class TimeMap:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.timemap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if self.timemap.get(key) is None:
            self.timemap[key] = []
            self.timemap[key].append([value, timestamp])
        else:
            self.timemap[key].append([value, timestamp])


    def get(self, key: str, timestamp: int) -> str:
        if self.timemap.get(key) is None:
            return ''
        else:
            val_array = self.timemap[key]

            if len(val_array) == 1:
                if val_array[0][1] <= timestamp:
                    return val_array[0][0]
                else:
                    return ''
            else:
                def get_middle_val(val_array, timestamp):
                    low = 0
                    high = len(val_array) - 1

                    while low <= high:
                        mid = (low + high) // 2
                        if val_array[mid][1] == timestamp:
                            return val_array[mid][0]
                        elif val_array[mid][1] > timestamp:
                            high = mid - 1
                        else:
                            low = mid + 1
                    
                    if high >= 0:
                        return val_array[high][0]
                    else:
                        return ''
                        
                return get_middle_val(val_array, timestamp)


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)