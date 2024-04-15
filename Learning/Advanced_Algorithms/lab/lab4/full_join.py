import db

class FullJoin:
    def __init__(self,db:db.DatabaseManager,join_order:list) -> None:
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
            