import db
import numpy as np
class Sampling:
    def __init__(self,db:db.DatabaseManager,num:int,join_order:list) -> None:
        self.num=num
        self.join_order=join_order
        self.db=db
        
    def __sample(self):
        # get r0 w
        sql='select sum(w) from %s;'%(self.join_order[0]+'w')
        res=self.db.execute(sql)
        
        r0_w=int(res[0][0])
        w=r0_w
        current_t=()
        common_attribute=''
        result=[]
        temp_w=w
        for i in range(len(self.join_order)):
            
            if i ==0:
                w=r0_w
            else:
                c_attributes=self.db.get_table_attributes(self.join_order[i])
                l_attributes=self.db.get_table_attributes(self.join_order[i-1])
                common_attribute=list(set(c_attributes)&set(l_attributes))[0]
                
                sql='select sum(w) from %s where %s=\'%s\''%(self.join_order[i]+'w',common_attribute,current_t[len(current_t)-2])
                
                res=self.db.execute(sql)
                
                w=int(res[0][0])
            t=float(1-w/temp_w)
            
            if np.random.uniform(0,1)<t:
                return None
            else:
                
                P=np.random.rand()
                if i!=0:
                    sql='select * from %s where %s=\'%s\''%(self.join_order[i]+'w',common_attribute,current_t[len(current_t)-1])
                else:
                    sql='select * from %s '%(self.join_order[i]+'w')
                res=self.db.execute(sql)
                p=0.
                for t in res:
                    p+=t[2]/w
                    if P<p:
                        select_t=t
                        break
                if result==[]:
                    result.append(select_t[0])
                for i in range(1,len(select_t)-1):
                    result.append(select_t[i])
                current_t=select_t
                w=select_t[-1]
                temp_w=w
        return result
    
    def sample(self):
        res=[]
        for i in range(self.num):
            r=self.__sample()
            while r==None:
                r=self.__sample()
            res.append(r)
        return res
                
            