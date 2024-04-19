import attr
from regex import R
import db
import numpy as np
import time
from sample import Sampling


class ExatWeight(Sampling):
    def __init__(self, db: db.DatabaseManager, join_order: list,num:int) -> None:
        
        super().__init__(db,num,join_order)
        self.tuple_cost={}

    def cul_weight(self):
        for i in range(len(self.join_order)-1, -1, -1):
            self.tuple_cost[self.join_order[i]]={}
            if i == len(self.join_order)-1:
                table = self.join_order[i]
                attributes = self.db.get_table_attributes(table)
                l_attributes= self.db.get_table_attributes(self.join_order[i-1])
                l_common_attributes = list(
                    set(l_attributes) & set(attributes))[0]
                index=attributes.index(l_common_attributes)
                data = list(self.db.query_data(table, attributes))
                r_w={}
                for d in data:
                    self.tuple_cost[self.join_order[i]][d[index]]=1
                    if d[index] in r_w.keys():
                        r_w[d[index]]+=1
                    else:
                        r_w[d[index]]=1
            else:
                table = self.join_order[i]
                attributes = self.db.get_table_attributes(table)
                if i!=0:
                    l_attributes= self.db.get_table_attributes(self.join_order[i-1])
                    l_common_attributes = list(
                        set(l_attributes) & set(attributes))[0]
                    l_index=attributes.index(l_common_attributes)
                else:
                    l_common_attributes=attributes[:]
                r_attributes= self.db.get_table_attributes(self.join_order[i+1])
                r_common_attributes = list(
                        set(r_attributes) & set(attributes))[0]
                r_index=attributes.index(r_common_attributes)
                
                # set cost
                
                data = self.db.query_data(table, attributes)
                for d in data:
                    if i==0:
                        self.tuple_cost[self.join_order[i]][d]=r_w[d[r_index]]
                    else:
                        self.tuple_cost[self.join_order[i]][d[l_index]]=r_w[d[r_index]]
                
                r_w={}
                
                #set r_w
                if i!=0:
                    for d in data:
                        if d[l_index] in r_w.keys():
                            r_w[d[l_index]]+=self.tuple_cost[self.join_order[i]][d[l_index]]
                        else:
                            r_w[d[l_index]]=self.tuple_cost[self.join_order[i]][d[l_index]]
                    
                
    
    def Sample(self):
        t1=time.time()
        self.cul_weight()
        t2=time.time()
        print('\t\t',1)
        # print(self.tuple_cost)
        a=self.sample(self.tuple_cost)
        t3=time.time()
        print('\t\tcul weight:',(t2-t1))
        print('\t\tsample tuple:',(t3-t2))
        return a
                    
                
