import db
import numpy as np

class ExtendedOlken:
    def __init__(self, db: db.DatabaseManager, join_order: list) -> None:
        self.db = db
        self.join_order = join_order
        
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
        
        self.oklen_bound=[]
        for i in range(len(self.join_order)):
            bound=1
            for j in range(i+1,len(self.join_order)):
                bound*=self.max_frequency[self.join_order[j]]
            self.oklen_bound.append(bound)
        self.oklen_bound.append(1)
        
    def cul_weight(self):
        self.get_frequency()
        right_attributes = []

        for i in range(len(self.join_order)-1, -1, -1):
            if i == len(self.join_order)-1:
                table = self.join_order[i]
                attributes = self.db.get_table_attributes(table)
                w_table = table+'w'
                data = list(self.db.query_data(table, attributes))
                w_attributes = attributes[:]
                w_attributes.append('w')
                for d in data:
                    w_value = []
                    for value in d:
                        w_value.append('\''+value+'\'')
                    w_value.append(self.oklen_bound[i])
                    self.db.add_tuple(w_table, w_attributes, w_value)
                right_attributes = attributes
            else:
                table = self.join_order[i]
                attributes = self.db.get_table_attributes(table)
                common_attributes = list(
                    set(right_attributes) & set(attributes))[0]
                w_table = table+'w'

                attributes.remove(common_attributes)
                attributes.insert(0, common_attributes)
                data = list(self.db.query_data(table, attributes))
                w_attributes = attributes[:]
                w_attributes.append('w')
                for d in data:
                    w_value = []
                    for value in d:
                        w_value.append('\''+value+'\'')
                    w_value.append(self.oklen_bound[i])
                    self.db.add_tuple(w_table, w_attributes, w_value)
                right_attributes = attributes
    
                
                    
    
    
                
                
        