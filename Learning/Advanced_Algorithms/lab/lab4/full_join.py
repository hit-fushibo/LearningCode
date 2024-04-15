import db

class full_join:
    def __init__(self,join_order:list,db:db.DatabaseManager) -> None:
        self.join_order=join_order
        self.db=db
    
    def run(self):
        attribute=['*']
        table=''
        for i in range(len(self.join_order)):
            if i==0:
                table+='%s'%self.join_order[i]
            else:
                table+=' NATURAL JOIN %s '%self.join_order[i]
        
        self.db.query_data(table,attribute)
            