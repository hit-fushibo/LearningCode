import db
import numpy as np
class Sampling:
    def __init__(self,db:db.DatabaseManager,num:int,join_order:list) -> None:
        self.num=num
        self.join_order=join_order
        self.db=db
        
    def __sample(self,W:dict):
        # get r0 w
        r0_w=0
        for key in W[self.join_order[0]].keys():
            r0_w+=int(W[self.join_order[0]][key])
        w=r0_w
        current_t=()
        result=[]
        temp_w=w
        for i in range(len(self.join_order)):
            # print(i)
            if i ==0:
                attributes=self.db.get_table_attributes(self.join_order[i])
                w=r0_w
                t=float(1-w/temp_w)
                # print(w,temp_w)
            
                if np.random.uniform(0,1)<t:
                    # print(t)
                    return None
                else:
                    
                    P=np.random.rand()
                    sql='select * from %s '%(self.join_order[i])
                    res=self.db.query_data(self.join_order[i],attributes)
                    p=0.
                    for t in res:
                        p+=int(W[self.join_order[i]][t])/w
                        if P<p:
                            select_t=t
                            w=int(W[self.join_order[i]][t])
                            break
                    if result==[]:
                        result.append(select_t[0])
                    for j in range(1,len(select_t)):
                        result.append(select_t[j])
                    current_t=select_t
                    temp_w=w
                r_attributes= self.db.get_table_attributes(self.join_order[i+1])
                r_common_attributes = list(
                        set(r_attributes) & set(attributes))[0]
                r_index=attributes.index(r_common_attributes)
            else:
                attributes=self.db.get_table_attributes(self.join_order[i])
                l_attributes= self.db.get_table_attributes(self.join_order[i-1])
                l_common_attributes = list(
                    set(l_attributes) & set(attributes))[0]
                l_index=attributes.index(l_common_attributes)
                
                # sql='select %s from %s where %s=\'%s\''%(self.join_order[i],l_common_attributes,current_t[r_index])
                
                res=self.db.query_data(self.join_order[i],attributes,'%s=\'%s\''%(l_common_attributes,current_t[r_index]))
                w=0
                for t in res:
                    w+=int(W[self.join_order[i]][t[l_index]])
                t=float(1-w/temp_w)
                # print(w,temp_w)
                # print(t)
                if np.random.uniform(0,1)<t:
                    return None
                else:
                    
                    P=np.random.rand()
                    p=0.
                    for t in res:
                        p+=int(W[self.join_order[i]][t[l_index]])/w
                        if P<p:
                            select_t=t
                            break
                    if result==[]:
                        result.append(select_t[0])
                    for j in range(1,len(select_t)):
                        result.append(select_t[j])
                    current_t=select_t
                    w=int(W[self.join_order[i]][select_t[l_index]])
                    temp_w=w
                    
                if i!=len(self.join_order)-1:
                    r_attributes= self.db.get_table_attributes(self.join_order[i+1])
                    r_common_attributes = list(
                            set(r_attributes) & set(attributes))[0]
                    r_index=attributes.index(r_common_attributes)
        return result
    
    def sample(self,w:dict):
        res=[]
        for i in range(self.num):
            print('\t\t\t sample ',i+1,'tuple')
            r=self.__sample(w)
            while r==None:
                print('\t\t\t resample ')
                r=self.__sample(w)
            res.append(r)
        return res
                
            