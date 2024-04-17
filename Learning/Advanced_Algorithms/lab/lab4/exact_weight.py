import db
import numpy as np
import os


class ExatWeight:
    def __init__(self, db: db.DatabaseManager, join_order: list) -> None:
        self.db = db
        self.join_order = join_order

    def cul_weight(self):
        right_attributes = []

        for i in range(len(self.join_order)-1, -1, -1):
            right_w = {}
            if i == len(self.join_order)-1:
                table = self.join_order[i]
                attributes = self.db.get_table_attributes(table)
                w_table = table+'w'
                data = list(self.db.query_data(table, attributes))
                w_attributes = attributes[:]
                w_attributes.append('w')
                print(len(data))
                for d in data:
                    w_value = []
                    for value in d:
                        w_value.append('\''+value+'\'')
                    w_value.append(1)
                    self.db.add_tuple(w_table, w_attributes, w_value)
                right_attributes = attributes
            else:
                table = self.join_order[i]
                right_table = self.join_order[i+1]+'w'
                attributes = self.db.get_table_attributes(table)
                common_attributes = list(
                    set(right_attributes) & set(attributes))[0]
                w_table = table+'w'

                # set right w
                sql = 'select %s,sum(w) from %s group by %s;' % (
                    common_attributes, right_table, common_attributes)
                result = self.db.execute(sql)
                for tuple in result:
                    if tuple[0] in right_w.keys():
                        right_w[tuple[0]] += tuple[1]
                    else:
                        right_w[tuple[0]] = tuple[1]
                attributes.remove(common_attributes)
                attributes.insert(0, common_attributes)
                data = list(self.db.query_data(table, attributes))
                w_attributes = attributes[:]
                w_attributes.append('w')
                for d in data:
                    w_value = []
                    for value in d:
                        w_value.append('\''+value+'\'')
                    w_value.append(right_w[d[0]])
                    self.db.add_tuple(w_table, w_attributes, w_value)
                right_attributes = attributes
