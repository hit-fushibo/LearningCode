import numpy as np

class datasets:
    def __init__(self,data_size) -> None:
        self.data={'uniform':list(np.random.uniform(1,1000,data_size)), # type: ignore
                   'normal':list(np.random.normal(500,200,data_size)), # type: ignore
                   'zipf':list(np.random.zipf(1.2,data_size))} # type: ignore
        
    def load(self):
        return self.data