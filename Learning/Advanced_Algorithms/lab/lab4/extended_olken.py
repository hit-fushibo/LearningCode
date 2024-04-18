import db
import numpy as np
from sample import Sampling
class ExtendedOlken(Sampling):
    def __init__(self, db: db.DatabaseManager, join_order: list,num:int) -> None:
        
        super().__init__(db,num,join_order)
        self.tuple_cost={}
        
    def get_frequency(self):
        self.max_frequency={}
        self.mean_frequency={}
        self.table_len={}
        for i in range(len(self.join_order)-1,-1,-1):
            c_table=self.join_order[i]
            c_attributes=self.db.get_table_attributes(c_table)
            c_frequency={}
            if i!=0:
                l_table=self.join_order[i-1]
                l_attributes=self.db.get_table_attributes(l_table)
                common_attribute=list(set(c_attributes)&set(l_attributes))[0]
            else:
                continue
            
            sql='select count(*) from %s'%(c_table)
            res=self.db.execute(sql)
            cnt=int(res[0][0])
            self.table_len[c_table]=cnt
            sql='select %s,count(*) from %s group by %s'%(common_attribute,c_table,common_attribute)
            res=self.db.execute(sql)
            max_f=0
            mean_f=0
            i=0
            for t in res:
                c_frequency[t[0]]=int(t[1])
                max_f=max(max_f,int(t[1]))
                mean_f=mean_f*(i/(i+1))+(c_frequency[t[0]])/(i+1)
                i+=1
            self.max_frequency[c_table]=max_f
            self.mean_frequency[c_table]=mean_f
        
        self.oklen_bound={}
        for i in range(len(self.join_order)):
            bound=1
            for j in range(i+1,len(self.join_order)):
                bound*=self.max_frequency[self.join_order[j]]
            self.oklen_bound[self.join_order[i]]=bound
        self.oklen_bound[self.join_order[len(self.join_order)-1]]=1
        
    def cul_weight(self):
        self.get_frequency()
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
                for d in data:
                    self.tuple_cost[self.join_order[i]][d[index]]=1
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
                        self.tuple_cost[self.join_order[i]][d]=self.oklen_bound[self.join_order[i]]
                    else:
                        self.tuple_cost[self.join_order[i]][d[l_index]]=self.oklen_bound[self.join_order[i]]
    def Sample(self):
        self.cul_weight()
        print(1)
        # print(self.tuple_cost)
        return self.sample(self.tuple_cost)            
                
    
                
                    
    
    
                
                
        