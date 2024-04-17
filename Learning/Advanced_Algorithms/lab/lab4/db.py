import pymysql

default_host='localhost'
default_port=3306
default_user='root'
default_passwd='Fu213138487'
default_DataBase='lab4'

class DatabaseManager:
    def __init__(self, host=default_host, port=default_port, user=default_user, passwd=default_passwd, database=default_DataBase):
        self.host = host
        self.port = port
        self.user = user
        self.passwd = passwd
        self.database = database
        try:
            self.db = pymysql.connect(host=self.host, user=self.user, passwd=self.passwd, port=self.port, db=self.database)
            print('connect success')
        except Exception as e:
            print(f'Error: {e}')
            exit(0)

    def add_tuple(self, table:str, attributes:list, values:list):
        cursor = self.db.cursor()
        try:
            value_sql=''
            for value in values:
                value_sql+='%s,'%value
            value_sql=value_sql[:-1]
            
            sql = f"INSERT INTO {table} ({', '.join(attributes)}) VALUES ({value_sql});"
            cursor.execute(sql)
            self.db.commit()
            # print("Tuple added successfully")
        except Exception as e:
            self.db.rollback()
            print(sql,attributes,values)
            print(f"Error adding tuple: {e}")
        finally:
            cursor.close()
    def execute(self,sql:str):
        cursor = self.db.cursor()
        try:
            cursor.execute(sql)
            results = cursor.fetchall()
            return results
        except Exception as e:
            print(sql)
            print(f"Error executing sql : {e}")
            exit(0)
        finally:
            cursor.close()

    def query_data(self, table:str, attributes:list, condition:str=''):
        cursor = self.db.cursor()
        try:
            if not condition=='':
                sql = f"SELECT {', '.join(attributes)} FROM {table} WHERE {condition};"
            else:
                sql = f"SELECT {', '.join(attributes)} FROM {table};"
            cursor.execute(sql)
            results = cursor.fetchall()
            return results
        except Exception as e:
            print(f"Error querying data: {e}")
            exit(0)
        finally:
            cursor.close()

    def delete_tuple(self, table:str, condition:str):
        cursor = self.db.cursor()
        try:
            sql = f"DELETE FROM {table};"
            cursor.execute(sql)
            self.db.commit()
            # print("Tuple deleted successfully")
        except Exception as e:
            self.db.rollback()
            print(f"Error deleting tuple: {e}")
        finally:
            cursor.close()
    
    def get_table_attributes(self,table:str):
        cursor = self.db.cursor()
        sql='select column_name from information_schema.columns where table_schema= \'%s\' and table_name=\'%s\''%(self.database,table)
        try:
            cursor.execute(sql)
            cols=[c[0] for c in cursor.fetchall()]
            return cols
        except Exception as e:
            self.db.rollback()
            print(f"Error getting table attributes: {e}")
            exit(0)
            
        finally:
            cursor.close()

    def close_connection(self):
        self.db.close()
        print('Connection closed')

    