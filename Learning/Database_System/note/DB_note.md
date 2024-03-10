<div STYLE="page-break-after: always;"></div>

# 数据库系统复习笔记

2023 秋-张浩老师

---

## 概论

重点

- DBS 定义与特点，文件系统与数据库系统的区别
- 三级抽象
- 二级映射
- 数据独立性

---

### 数据与数据库

数据

- 数据是描述现实世界中各种具体事物或抽象概念的可存储编码，是信息的载体
- 数据与其语义是不可分的

**数据库.**

- 一个互相关联的是数据的集合
- 是长期储存在计算机内、有组织的、可共享的
- 数据库的特征

  - 数据按一定的数据模型组织、描述和储存
  - 可为各种用户共享
  - 冗余度较小
  - 数据独立性较高
  - 易拓展

- 数据库类型

  - 简单结构数据库：关系数据库
  - 复杂结构数据库：图数据库
  - 半结构化数据库：XML 数据库
  - 非结构化数据库：多媒体数据库

- 数据库目的

  - 把现实世界映射到计算机世界
  - 支持各种实际应用

### 数据库管理系统及其结构

数据库管理系统

- 管理数据库的软件系统，包括存储管理、安全性管理、完整性管理等
- 系统结构

  ![1703315416545](images/1703315416545.png)

- 功能与特点

  - 有效的支持数据抽象与数据定义
  - 有效地组织存储数据
  - 有效地处理数据查询与更新
  - 支持数据独立性
  - 控制数据冗余
  - 支持数据共享/并发控制
  - 限制非授权的存取
  - 提供多种用户界面
  - 表示数据之间的复杂联系
  - 支持完整性约束
  - 有效的数据恢复与事务处理

### 数据库系统

数据库系统

- 数据库+数据库管理系统
- 数据库+数据库管理系统+数据库管理员+应用开发工具+应用系统+数据库系统用户

文件系统

- 数据冗余和不一致
- 数据访问困难
- 数据孤立
- 完整性问题
- 原子性问题
- 并发访问异常
- 安全性问题

![1703318288227](images/1703318288227.png)

### 数据抽象与数据模型

数据抽象

- 对于用户系统地隐藏关于数据存储和维护的某些细节
- 屏蔽复杂性，简化用户与系统的交互
- 三个层次
  - 视图抽象
    - 最高层次抽象
    - 把现实世界信息按不同用户观点抽象为多个逻辑数据结构，每个逻辑结构称为一个视图
    - 每个视图称之为了数据库的一个子模式
  - 逻辑抽象
    - 综合所有视图，把用户关心的现实世界抽象为逻辑模式
    - 描述数据库存储什么数据以及这些数据之间存在的关系
  - 物理抽象
    - 最底层抽象
    - 把逻辑模式抽象成为数据库的物理模式
    - 描述数据实际上是怎么存储的

映射数据独立性

- 物理数据独立性
  - 物理模式改变，只需要修改物理模式到逻辑模式的映射，逻辑模式不变
- 逻辑数据独立性
  - 逻辑模式改变，只需要改变逻辑模式到子模式的映射，子模式不变

数据模型

- 是实现数据抽象的工具
  - 描述现实世界对象数据
  - 描述现实世界对象联系
  - 描述数据的完整性约束
  - 描述数据操作集合
- 是数据库系统关键、决定
  - 数据库结构
  - 数据库的设计方法
  - 数据库管理系统设计实现
  - 数据定义语言（DDL）和操纵语言（DML）
- 数据模型的必要条件
  - 真实地模拟现实世界
  - 容易为用户所理解
  - 便于在计算机上实现
- 基本要素
  - 数据结构
  - 数据操作
  - 数据的完整性约束
- 常用数据模型
  - 实体关系（E-R）数据模型
  - 面向对象（O-O）数据模型
  - 关系数据模型
  - 对象关系（O-R）数据模型
  - 层次和网络数据模型

层次数据模型

- 层次数据模型的数据结构
  - 满足以下两个条件的基本层次联系的集合称为层次模型
    - 有且仅有一个节点没有父亲节点，这个节点称为根节点
    - 根以外其他节点有且仅有一个父亲节点
  - 层次模型的数据结构是满足下列条件的树
    - 每个节点对应现实世界的一个对象的数据记录
    - 边表示对象之间的联系
  - 特点
    - 只能处理一对多的实体联系
    - 只有按其路径查看记录值时才能显式其全部意义
    - 任何子女都不能脱离其父亲节点而独立存在
- 层次数据模型的数据操作
  - 树定位
  - 路径定义
  - 沿路径的记录定位
  - 记录查询
  - 记录插入
  - 记录删除
  - 记录更新
  - 模式更新
- 层次数据模型的完整性约束
  - 无相应的父亲节点值就不能插入子女节点值
  - 如果删除父亲节点值，则相应的子女节点值也被删除
  - 更新数据时，应更新所有相应记录，以保证数据一致性
- 层次数据模型的优缺点
  - 优点
    - 层次数据模型简单，对具有一对多的层次关系的现实世界描述自然、直观，容易理解
    - 提供了良好的完整性支持
  - 缺点
    - 多对多表示不自然
    - 对插入和删除操作限制多
    - 查询子女节点必须通过父亲节点
    - 面向过程
- 代表性数据库系统
  - IMS 数据库系统

网状数据模型

- 网状数据模型的数据结构
  - 满足下列条件的图
    - 每个节点是一个对象记录
    - 边表示对象之间的联系
    - 允许多个节点无父节点
    - 允许节点有多个父节点
    - 允许两个节点之间有多种联系
  - 层次模型时网状模型特例
- 网状数据结构的数据操作
  - 网络定位
  - 路径定位
  - 沿路径的记录定位
  - 记录查询
  - 记录插入
  - 记录删除
  - 记录更新
  - 模式更新
- 网状数据模型的完整性约束
  - 完整性约束条件不严格
    - 允许插入尚未确定父节点值的子女节点值
    - 允许只删除父节点值
    - 一些具体系统提供了一些完整性约束
- 网状数据模型的优缺点
  - 优点
    - 能够更为直接地描述现实世界，如一个节点可以有多个父亲节点
    - 具有良好的性能，查询、更新等不需要访问父亲节点
  - 缺点
    - 结构比较复杂，不利于最终用户掌握
    - DDL、DML 语言复杂，用户不容易使用
    - 面向过程
- 代表性网状数据库管理系统
  - IDS

## 关系数据库系统

重点

- 关系数据库的数据结构--元组、属性、域、码（超码、候选码、外码）
- 完整性约束规则--实体完整性、参照完整性、用户定义完整性
- 关系代数--6 种基本操作、派生操作、关系代数书写查询

---

### 关系模型

关系数据模型：用二维表的形式表示实体以及实体之间联系的模型

特点

- 简单
- 表达能力强
- 效率高

### 关系模型的数据结构

- 建立在集合代数的基础上
- 单一的数据结构--关系

  - 现实世界的实体以及实体间的各种联系均用关系表示

- 数据的逻辑结构--二维表

  - 从用户角度，关系模型中数据的逻辑结构是一张二维表

- 基本概念

  - 关系
    - 元组
    - 属性
    - 域
  - 关系模式、关系实例
  - 关系数据库

- 关系数据库由表组成，每个表有唯一的名字，称为**关系**

  - 元组-用来指定关系表的行、次序不重要
  - 属性-用来指代关系表的列、次序不重要
  - 域-属性取值的集合

- 关系的性质

  - 列是同质的
  - 不同的列可能出自同一个域-不同属性要给予不同的属性名
  - 列的顺序无所谓
  - 任意两个元组不能完全相同
  - 行的顺序无所谓
  - 分量必须取原子值

- 关系模式

  - 关系名
  - 属性集合
  - 属性域集合
  - 映射
  - 完整性约束集合
  - 属性间的函数依赖关系

- 关系实例

  - 关系模式在给定时刻的一个快照称为关系实例

- 关系、关系模式和关系实例

  - 关系是一个数据集合
  - 关系模式描述关系的数据结构和语义约束的集合
  - 关系模式是相对稳定的
  - 关系实例时随时间变化的
  - 关系实例时某一时刻现实世界状态的真实反映

- 关系数据库模式

  - 一组关系模式的集合

- 关系数据库实例

  - 关系数据库模式对应关系的关系实例的集合

### 关系模型的完整性约束

- 超码：一个或多个属性的集合，这些属性的组合可以在一个关系中唯一地标识一个元组
  - 如果 K 是一个超码，那么 K 的任意超集也是超码
  - 超码中可能包含无关紧要的属性
- 候选码-最小超码
  - K 是关系的一个超码
  - K 的任意真子集都不能称为关系的超码
- 主码
  - 被数据库设计者选中的、主要用来在一个关系中区分不同元组的**候选码**
  - 应选择那些值从不或极少变化的属性
  - 一个关系模式只能有一个主码
- 主属性
  - 主码中的属性
- 外码
  - 一个关系模式 r1 可能在它的属性中包括另一个关系模式 r2 的主码, 这个属性集合在 r1 上称作参照 r2 的外码
  - 外码不一定要与相应的主码同名
  - 一般情况下，外码与相应的主码往往取相同的名字，便于识别
- 完整性约束
  - 实体完整性约束
    - 主属性不空
  - 参照完整性约束
    - 在参照关系中任意元组在特定属性上的取值必然等于被参照关系中的某个元组在特定属性上的取值
    - 为了保证数据一致性
  - 其他类型的约束-用户定义的完整性约束
    - 语义完整性约束
    - 函数依赖

### 关系运算

查询语言

- 用户用来从数据库中请求获取信息的语言
  - 过程化语言
  - 非过程语言

关系代数

- 一种过程化查询语言
- 包括一个运算集合，这些运算以一个或两个关系作为输入，产生一个新的关系作为结果
- 六种关系运算
  - 选择：$\sigma$
  - 投影：$\Pi$
  - 并：$$
  - 差：$-$
  - 笛卡尔积：$\times$
  - 重命名：$\rho$
  - 其他运算
    - 交
    - 自然连接
    - 除
- 多个关系运算组合成一个关系代数表达式
- 其他运算可以由基本运算定义

元组演算

- 非过程化的查询语言
- 只需要描述所需信息，而不给出获得信息的具体过程

![1703342534369](images/1703342534369.png)

域演算

- 使用从属性域中取值的域变量，而不是整个元组的值

![1703342543331](images/1703342543331.png)

安全关系演算系统

- 不产生无限关系和无穷验证的关系运算系统
- 关系代数系统是安全的
- 而元组演算和域演算是不安全的

![1703342637613](images/1703342637613.png)

关系代数、元组和域演算的等价性

- 下面三者是等价的
  - 基本关系代数
  - 限制在安全表达式范围内的元组关系演算
  - 限制在安全表达式范围内的域关系演算

关系模型和关系数据库的对应

![1703342739786](images/1703342739786.png)

## 结构化查询语言 SQL

重点

- SQL 数据定义--关系定义、视图定义、完整性约束的 SQL 语言表示
- SQL 查询--单表、连接、分组、聚集
- SQL 数据修改--插入、修改、删除

---

### 概览

SQL 语言有以下几个部分

- 数据定义语言（DDL）：提供定义关系模式、删除关系以及修改关系模式的命令
- 数据操纵语言（DML）：提供从数据中查询信息、以及在数据中插入元组、删除元组、修改元组的能力
- 完整性：SQL DDL 包括定义完整性约束命令
- 视图定义：SQL DDL 包括定义视图的命令
- 事务控制：定义事务的开始和结束
- 嵌入式 SQL 和动态 SQL
- 授权：SQL DDL 包括定义对关系和视图的访问权限的命令

SQL 语言的特点

- 综合统一
- 高度非过程化
- 面向集合的操作方式
- 简洁

### SQL 数据定义

SQL 的数据定义语句（DDL）包括

![1703343192396](images/1703343192396.png)

- 索引无修改语句
- 视图通常不能修改，但一些数据库提供这个功能

建立关系模式的语法

![1703343261354](images/1703343261354.png)

- 完整性约束

  - 主码

    ![1703343300036](images/1703343300036.png)

  - 外码

    ![1703343311867](images/1703343311867.png)

  - not null

- 属性类型

  ![1703343345599](images/1703343345599.png)

修改关系模式的语法

![1703343370079](images/1703343370079.png)

删除关系模式的语法

![1703343400312](images/1703343400312.png)

建立索引的语法

![1703343445504](images/1703343445504.png)

- UNIQUE 表明索引属性是主码属性，即不允许重复值
- ORDER：升序 ASC 或降序 DESC 排列
- CLUSTER：是否为聚集索引

删除索引的语法

![1703343567209](images/1703343567209.png)

视图

- 为什么
  - 让所有用户都看到整个逻辑是不合适的，出于安全考虑，可能需要向用户隐藏特定的数据
- 视图本身并不保存数据

定义视图的语法

![1703343651535](images/1703343651535.png)

- 组成视图的属性名或者全部省略或者全部指定
- 子查询：合法的查询表达式
- WITH CHECK OPTION：透过视图进行增删改操作时，不得破坏视图定义中的谓词条件，即子查询中的条件表达式

![1703343666106](images/1703343666106.png)

删除视图的语法

![1703343789192](images/1703343789192.png)

- CASCADE：如果指定了 CASCADE 选项，则该视图和由它导出的所有视图一起删除；如果没有指定，并且在该视图上定义了其他视图，该语句被拒绝执行

### SQL 查询

一般语法格式

![1703343931761](images/1703343931761.png)

- SQL 关键字不区分大小写
- 换行和缩进均不敏感
- 允许查询结果中有重复元组，可通过 DISTINCT 选项去重

单表查询

- 选择表中若干列

  - 列名可以为表达式

    ![1703344130761](images/1703344130761.png)

  - 指定大小写

    ![1703344146825](images/1703344146825.png)

  - 使用列别名

    ![1703344173109](images/1703344173109.png)

- 选择表中若干元组

  - 查询满足条件的元组
    - WHERE 字句
  - 使用 DISTINCT 消除重复行
  - 使用 ALL 明确要求不消除重复行
  - 通配符
    - %代替若干字符
    - \_代替一个字符

- 对查询结果排序

  - ORDER BY 字句
    - 升序：ASC
    - 降序：DEAC
    - 缺省为升序

- 聚集函数

  ![1703344415477](images/1703344415477.png)

- 对查询结果分组

  - GROUP BY 字句
  - 聚集函数将作用在每个分组上
  - 任何出现在 group by 子句中的属性如果出现在 select 子句中的话，它只能出现在聚集函数内部

连接查询

- 同时涉及多个表的查询
- 连接条件

  ![1703344657795](images/1703344657795.png)

- 自然连接

  ![1703344682924](images/1703344682924.png)

- 其他连接

  ![1703344696494](images/1703344696494.png)

嵌套子查询

- 子查询不能使用 ORDER BY 字句
- 有些嵌套查询可以用连接运算替代
- 如果子查询的查询条件依赖于外层父查询的某个属性值，称为相关子查询

  ![1703344841027](images/1703344841027.png)

集合查询

- 并：UNION
- 交：INTERSECT
- 差：EXCEPT
- 参加集合操作的各结果表列数必须相同；对应的数据类型也必须相同，系统自动去掉重复行

### SQL 数据库的修改

插入数据

- 插入单个数据

  ![1703344978923](images/1703344978923.png)

- 插入子查询的结果

  ![1703344999166](images/1703344999166.png)

  ![1703345028731](images/1703345028731.png)

修改数据

![1703345060145](images/1703345060145.png)

删除数据

![1703345078953](images/1703345078953.png)

- WHERE 缺省标识删除所有的元组，不删除关系模式

### SQL 事务

事务

- 由查询和更新语句的序列组成
- commit：提交当前事务，也就是将该事务所做的更新在数据库中持久保存
- roll back：回滚当前事务，即撤销该事务中所有 SQL 语句对数据库的更新。数据库恢复到执行该事务第一条语句之前的状态
- 定义
  - begin atomic `SQL语句` end

### SQL 触发器

触发器是一条语句，当对数据修改时它自动被执行

设置触发器机制，必须满足

- 什么条件下执行触发器
- 触发器的动作

![1703345284219](images/1703345284219.png)

![1703345336497](images/1703345336497.png)

优点

- 提供了检查数据完整性的替代方法
- 可以捕获数据库层中业务逻辑中的错误
- 提供了运行计划任务的另一种方法
- 对于审核表中数据的更改非常有用

缺点

- 只能提供扩展验证，并且无法替换所有验证
- 从客户端应用程序调用和执行 SQL 触发器不可见
- 可能会增加数据库服务器的开销
- 排错困难

### SQL 数据库授权机制

授权语法

![1703345473374](images/1703345473374.png)

- 权限列表
  - 读取数据-select
  - 插入数据-insert
  - 更新数据-update
  - 删除数据-delete
- WITH GRANT OPTION：默认情况下，被授权用户无权把此权限授予其他用户或角色，除非加入 with grant option 语句

收回权限语法

![1703345601937](images/1703345601937.png)

![1703345610496](images/1703345610496.png)

## 概念数据库设计

重点

- ER 图
- 实体
- 属性
- 码
- 联系--映射基数、参与约束

---

### 概述

数据库设计

- 信息管理要求--在数据库中存储和管理那些数据对象
- 数据操作要求--对数据对象需要进行哪些操作
- 设计目标

  - 为用户和各种应用系统提供一个信息基础设施和高效率的运行环境
    - 存储--数据信息完整，冗余度低
    - 使用--数据库的存取效率高
    - 管理--数据库系统运行管理的效率高

- 设计步骤

  ![1703400915593](images/1703400915593.png)

### 需求分析

用户需求在设计过程中扮演一个中心角色

需求分析的任务

- 详细调查现实世界要处理的对象
- 充分了解原系统
- 明确用户的各种需求
- 在此基础上确定新系统的功能
- 新系统必须充分考虑今后可能的扩充和改变

需求分析的重点

- 数据和处理，获得用户对数据库要求
- 信息要求
- 处理要求
- 安全性和完整性要求

需求分析的步骤

- 应用领域的调查分析
- 定义数据库支持的信息与应用
- 定义数据库操作任务
- 预测应用领域的未来改变

### 概念数据库模式设计

概念数据库设计任务包括

- 概念数据库模式设计
- 事务设计

概念数据库模式设计的目标

- 准确描述应用领域的信息模式，支持用户的各种应用
- 既易于转换为逻辑数据库模式，又容易为用户理解

实体联系模型-ER 模型

- 主要元素

  - 实体
  - 属性
  - 联系

- 实体

  - ER 模型的基本对象，是现实世界中可区别所有其他对象的一个“事务”或“对象”
  - 每个实体都有一组特征或性质，称为实体的属性
  - 实体属性的一组特定值确定了一个确定的实体
  - 实体的属性值是数据库中存储的主要数据
  - 实体集
    - 相同类型的实体集合
    - 实体集不必互不相交

- 属性

  - 实体的性质或特征
  - 是实体集映射到域的函数
  - 包括

    - 单值、多值属性

      - 单值属性--对同一实体只能取一个值
      - 多值属性--实体的属性可以取多个值

    - 简单、复合属性

      - 复合属性--可以划分为多个具有独立意义的子属性

        ![1703401601708](images/1703401601708.png)

    - 派生属性

      - 可以由其他属性导出的属性

  - 码--在 ER 模型中每个实体集具有一个由一个或多个属性组成的码，是足以区分每个实体的属性集

    - 由一个属性构成的键称为简单码。由多个属性构成的键称为复合码，统称为码（实下划线）

- 联系--–不同实体集的实体之间可能具有某种关联，我们称这种关联为实体间的联系

  - 联系集--同类联系的集合
    - 一个联系集所关联的实体集的数量称为这个联系集的阶
  - 实体之间的联系既可以通过联系集定义，也可以通过实体属性来表示
  - 联系集的属性--描述性属性

- 约束

  - 映射基数--一个实体通过一个联系集能关联的实体的个数
    - 一对一映射
      - 双箭头
    - 一对多映射
      - 单箭头
    - 多对一映射
      - 单箭头
    - 多对多映射
      - 直线
  - 参与约束
    - 全域关联约束--每个实体都关联另一实体集中的实体
      - 双线表示
    - 部分关联约束
  - 一种更复杂的表示映射基数的方式
    - l..h
      - l--最小基数
      - h--最大基数

- 弱实体集--没有足够的属性以形成主码的实体集

  - 弱实体集必须具有一个或多个属性，使得这些属性可以与主实体集的码相结合，形成相应弱实体的码
  - 上述属性称为弱实体集的部分码(虚线）

实体联系图-ER 图

- 矩形
  - 实体集
- 矩形中的文字
  - 属性
- 菱形
  - 联系集
- 线段
  - 将实体集连接到联系集

### 概念数据库设计的方法和策略

集中式设计方法

- 合并在需求分析阶段得到的各种应用需求
- 在上述基础上设计一个概念数据库模式，满足所有应用的要求

视图综合设计方法

- 不要求应用需求合并
  - 视图设计阶段
    - 根据每个应用的需求，独立地为每个用户和应用设计一个概念数据库模式。每个应用的概念数据库模式称为一个视图
  - 视图合并阶段
    - 把所有视图有机合并成一个统一的概念数据库模式，支持所有应用

自顶向下的设计策略

- 从一个包含高级抽象概念结构的模式出发，对这些高级抽象概念结构逐步求精，形成最终的概念数据库模式

自底向上的设计策略

- 从包含基本概念结构的模式出发，逐步组合这些基本概念结构，形成最终的概念数据库模式

混合策略

- 首先使用自顶向下的策略将应用需求划分为多个需求子集合
- 对于每个子集合采用自底向上的策略设计局部模式
- 组合局部模式，形成最后的概念数据库模式

### 视图综合设计方法

设计局部概念模式

- 抽取各局部应用涉及的数据，标定各局部应用中的实体、实体的属性、标识实体的码，确定实体之间的联系及其约束
- 形成局部 E-R 图

全局概念模式的合成

1. 识别局部概念模式间的冲突
2. 修改局部模式
3. 局部模式合并
4. 优化全局模式

冲突的种类

- 命名冲突
- 模式结构冲突
  - 相同概念在不同的局部模式中使用不同的概念模式表示
- 值域冲突
- 约束冲突

全局模式合成方法

- 二元阶梯合成法
- N 元合成法
- 平衡二元合成法
- 混合合成法

![1703402799925](images/1703402799925.png)

![1703402810578](images/1703402810578.png)

## 逻辑数据库设计

重点

- ER 图到关系表的转换
- 关系数据库的规范化--函数依赖、完全函数依赖、部分函数依赖、传递函数依赖、Armstrong 公理系统、求闭包、求候选码、求极小函数依赖集
- 关系数据库的规范形式--1NF、2NF、3NF、BCNF、无损连接性、函数依赖保持性、判别方法、关系模式的分解算法

---

### 逻辑数据库设计的任务

- 把概念数据库设计阶段产生的概念数据库模式转换为逻辑数据库模式
- ER 图-关系表

### 逻辑数据库设计的目标

- 满足用户的完整性和安全性要求
- 动态关系至少具有第三范式，静态关系至少具有第一范式
- 能够在逻辑级上高效率地支持各种数据库事务的运行
- 存储空间利用率高

### 逻辑数据库设计步骤

#### 形成初始关系数据库模式

目的

- 把概念数据库模式的实体、实体间联系等模型结构变换为关系模式
  方法

普通实体集的变换

- 为概念数据库模式中的每个普通实体集 E 建立一个关系 S
- S 包含 E 的所有简单属性和 E 的复合属性的简单子属性
- E 的码是 S 的主码

弱实体的变换

- 为概念数据库模式中的每个以实体集 E 为识别实体集的弱实体集 W 建立一个关系 S
- Ｗ的所有简单属性和复合属性的简单子属性映射为 S 的属性
- E 的码属性也是 S 的属性
- S 的主码由 E 的码和Ｗ的部分码组合而成
- E 对应的关系的码是 S 的外码

多值属性的变换

- 为 E 的每个多值属性 A 建立一个关系 T，用 T 表示 A
- 如果 A 是简单属性，T 的属性为 A 与 S 的主码 K；A 和 K 形成 T 的主码
- 如果 A 是复合属性，T 包含 A 的简单子属性和 S 的码 K；A 的简单子属性和 K 形成 T 的码
- S 关系中忽略属性 A
- 对联系 R 的多值属性类似处理
  ![1703404408186](images/1703404408186.png)

实体之间联系的变换

- 一对一联系--设 R 是实体集 E1 和 E2 之间的一对一联系，S 和 T 是 E1 和 E2 对应的关系
  - 1：通过在 S 或 T 中增加有关信息来表示联系 R
  - 2：建立一个单独的关系 W 表示 R
    - T 和 S 的主码作为主码添入 W
    - R 的简单属性和复合属性的简单子属性作为简单属性添入 W
- 一对多联系--设 R 是从实体集 E1 到实体集 E2 的一对多联系，S 和 T 是 E1 和 E2 对应的关系
  - 1：不需建立新关系。由于 T 的每个实体至多与 S 的一个实体对应，因此用 T 来表示 R
    - S 的主码作为外码添入 T
    - R 的简单属性和复合属性的简单子属性作为简单属性添入 T
  - 2：建立一个单独的关系 W 表示 R
- 多对多联系--设 R 是从实体集 E1 到实体集 E2 的多对多联系，S 和 T 是 E1 和 E2 对应的关系
  - 建立一个新关系 W 来表示 R
  - S 和 T 的主码添入 W，既作为外码，也组合起来作为 W 的主码
  - W 还需要包含 R 的简单属性和复合属性的简单子属性
- n 元联系--设 R 是关联实体集 E1、E2、...、En 的 n 元联系 - 需建立一个关系 T，用 T 来表示 R - 所有 Ei 的主码都是 T 的外码，也组合起来作为 T 的主码 - T 还包含 R 的简单属性和复合属性的简单子属性
  确定函数依赖集

#### 关系模式规范化

函数依赖：设 R 是一个关系模式，U 是 R 的属性集合，X 和 Y 是 U 的子集。对于 R 的任意实例 r，r 中任意两个元组 t1 和 t2，如果 t1[X]=t2[X]，则 t1[Y]=t2[Y]，我们称 X 函数地确定 Y，或 Y 函数依赖于 X，记作 X→Y

- 如果 X→U，则 X 为 R 的超码
- 如果 Y 不是 X 的子集，则称为非平凡函数依赖
- X 称为函数依赖的决定属性集
- 完全函数依赖：Y 函数依赖于 X 但不函数依赖于 X 的任意真子集，称 Y 完全函数依赖于 X
  - 如果 U 完全函数依赖于 X，则 X 为 R 的候选码
- 部分函数依赖：Y 函数依赖于 X 但不完全函数依赖于 X，称 Y 部分函数依赖于 X
- 传递地函数依赖：Y 函数依赖于 X，Z 函数依赖于 Y 并且 X 并不函数依赖于 Y，则称 Z 传递地函数依赖于 X
- 键属性：包含在任何一个候选码中的属性
- 非键属性：不包含在任何候选码中的属性
- 外码：设 X 是关系模式Ｒ的属性子集合。如果 X 是另一个关系模式的主码，则称 X 是 R 的外码

函数依赖的公理系统--Armstrong 公理系统

- 设 R 是一个具有属性集合 U 的关系模式，F 是 R 上的函数依赖集合。如果对于 R 的任意一个使 F 成立的关系实例ｒ，函数依赖 X→Y 都成立，则称 F 逻辑地蕴含 X→Y
  ![1703405321173](images/1703405321173.png)
- 用途
  - 求给定关系模式的候选键
  - 从一组函数依赖求蕴含的函数依赖
- Armstrong 公理系统--正确和完备的
  ![1703405394541](images/1703405394541.png)
  - 由自反律得到的函数依赖均是平凡函数依赖
- 导出规则
  ![1703405497678](images/1703405497678.png)
- 闭包
  ![1703405554201](images/1703405554201.png)
  - 作用--验证函数依赖是否被蕴含/验证超码
  - 求解算法
    ![1703405642736](images/1703405642736.png)
- 求解候选码的方法
  - 给定关系模式 R 和函数依赖集 F，将属性分为四类
    - L 类：只在 F 的函数依赖左部出现的属性
    - R 类：只在 F 的函数依赖右部出现的属性
    - N 类：在 F 的函数依赖左右两侧均未出现的属性
    - LR 类：在 F 的函数依赖左右两侧均出现的属性
  - 对于给定的关系模式及其函数依赖集 F，若 X 是 L 类属性，则 X 必为 R 的任一候选码的成员
  - 对于给定的关系模式及其函数依赖集 F，若 X 是 R 类属性，则 X 不在任何候选码中
  - 对于给定的关系模式及其函数依赖集 F，若 X 是 N 类属性，则 X 必包含在 R 的任一候选码中
    ![1703405888906](images/1703405888906.png)
    等价函数依赖集
- 闭包相等的函数依赖集相互之间等价
- 判断方法
  ![1703405960018](images/1703405960018.png)

极小函数依赖集
![1703406003428](images/1703406003428.png)

- 极小函数依赖集不唯一
- 求解极小函数依赖集算法
  ![1703406116228](images/1703406116228.png)

关系模式的规范形式

- 第一范式--1NF
  - R 的每个属性的值域都是不可分的简单数据项的集合
- 第二范式--2NF
  - R 是 1NF，并且每个非键属性都完全函数依赖于 R 的候选码
- 第三范式--3NF
  - R 是 2NF，并且每个非键属性都不传递地依赖于任何候选码
- BC 范式--BCNF
  - R 是 1NF，并且对于 R 的每个函数依赖 Y 函数依赖于 X，X 必为候选码
  - 性质
    - 所有非键属性都完全函数依赖于每个候选码
    - 所有键属性都完全函数依赖于每个不包含它的候选码
    - 没有任何属性函数依赖于非键属性的任何一组属性
      ![1703406550504](images/1703406550504.png)

关系模式的分类

- 静态关系：一旦数据已加载, 用户只能在这个关系上运行查询操作, 不再进行插入、删除和更新操作。至少具有第一范式
- 动态关系：经常被更新、插入和删除。应该具有第三范式

关系模式规范化的步骤
![1703406639378](images/1703406639378.png)

- 并不是说规范化程度越高越好

关系模式分解

- 必须满足
  - 无损连接性--可通过自然连接恢复
    ![1703406968943](images/1703406968943.png)
    - 判断方法
      ![1703407163316](images/1703407163316.png)
  - 函数依赖的保持性--F 所逻辑蕴含的函数依赖一定也由分解得到的某个关系模式中的函数依赖 Fi 所逻辑蕴含
    - 判断方法--求出所有分解后的关系模式中的函数依赖的并，判断其中是否逻辑蕴含 F 中的所有函数依赖
- 关系模式分解算法
  - 3NF 分解算法 1
    ![1703407348418](images/1703407348418.png)
  - 3NF 分解算法 2
    ![1703407380274](images/1703407380274.png)

#### 关系模式优化

目的--提高数据操作的效率和存储空间的利用率

常用的关系分解方法

- 水平分解
  - 把(基本)关系的元组分为若干子集合，定义每个子集合为一个子关系，以提高系统的效率
  - 使用范围
    - 满足“80/20 原则”的应用
      - 在一个大型关系中，经常被使用的数据知识是很有限的一部分可以把经常使用的数据分离出来，形成一个子关系
    - 并发事务经常存取不相交的数据
      - 如果关系 R 上有 n 个事务，而且多数事务存取的数据不相交，则 R 可以分解为少于或等于 n 个子关系，是每个事务存取的数据形成一个关系
- 垂直分解
  - 使用范围
    - 取决于分解后 R 上的所有事务的总效率是否得到了提高
  - 垂直分解方法
    - 简单情况：直观分解
    - 复杂情况：用关系模式分解算法
  - 垂直分解必须不损失关系模式的语义，即要保持无损连接性和函数依赖

#### 定义关系上的完整性和安全性约束

每个关系模式上的完整性约束分为三类

- 属性上的完整性约束
- 多个属性之间的完整性约束
- 不同关系模式的属性间的完整性约束

安全性约束分为两类

- 属性上的安全性约束
- 关系模式上的安全性约束

#### 子模式定义

利用视图定义子模式

- 使用更符合用户习惯的列名
- 为不同级别用户定义不同视图
- 简化用户对系统的使用

#### 性能估计

性能估计是对已经设计完成的逻辑数据库的时间复杂性和空间复杂性进行估算，其结果可以用来检验现有的计算机软硬件环境是否满足要求，以便调整软硬件环境或数据库的设计

三个测度

- 逻辑记录存取数
- 信息传输量
- 存储空间占用量

![1703408530627](images/1703408530627.png)

## 物理数据库设计

重点

- 影响物理数据库设计的因素
- 聚集存储方法

---

设计任务

- 在逻辑数据库设计基础上，为每个关系模式选择合适的存储结构和存取方法，使得数据库上的事务能够高效率的运行

设计步骤

- 分析影响物理数据库设计的因素

  - 对于数据库查询事务，需要得到如下信息
    - 查询的关系
    - 查询条件所涉及的属性
    - 连接条件所涉及的属性
    - 查询的投影属性
  - 对于数据更新事务，需要得到如下信息
    - 被更新的关系
    - 每个关系上的更新操作的类型
    - 删除和修改操作条件所涉及的属性
    - 修改操作要改变的属性值
  - 了解每个事务在各关系上运行的频率
  - 了解每个事务的时间约束

- 为关系模式选组存取方法

  - 聚集方法

    - 把经常进行连接操作的多个关系的记录以连接属性为中心分类存储，从而提高连接操作的效率
    - 即参加一个连接的所有关系中具有相同连接属性值的记录被物理地存储在一起
    - 一个物理数据库可以有多个聚集存储
    - 但一个关系只能加入一个聚集存储
    - 聚集存取方法的选择

      - 首先要确定聚集关系组

        - 确定需要多少个聚集存储
        - 每个聚集存储中包含哪些关系
        - 经常在一起进行连接操作的关系可以作为聚集关系组，连接属性作为聚集键
        - 如果一个关系的一组属性经常出现在相等比较条件中，则该单个关系可作为聚集关系组，这组属性作为聚集键
        - 如果一个关系的一个(或一组)属性上的实例值重复率很高，则此单个关系可作为聚集关系组，这组属性作为聚集键
        - 取消候选聚集关系组中不必要的关系,规则如下
          - 从聚集组中删除经常进行全关系扫描的关系
          - 从聚集组中删除更新操作远大于连接操作的关系

      - 然后确定优化的聚集方案

        ![1703417278595](images/1703417278595.png)

  - 索引方法

    - 索引存取方法的选择-根据在 R 上事务 T1、T2、...、Tk 的信息确定候选索引，规则如下
      - 如果一个(或一组)属性经常在查询操作条件中出现，则考虑在这个(或这组)属性上建立索引
      - 如果一个属性经常作为最大值和最小值等聚集函数的参数，则考虑在这个属性上建立索引
      - 如果一个(或一组)属性经常在连接操作的连接条件中出现，则考虑在这个(或这组)属性上建立索引
      - 如果一个(或一组)属性经常作为投影属性使用，则考虑在这个(或这组)属性上建立索引

  - HASH 方法

    - HASH 存取方法的选择-如果一个关系的属性主要出现在相等连接操作条件中，或主要出现在相等比较选择条件中，而且满足下列两个条件之一，则此关系可以选择 HASH 存取方法
      - 如果一个关系的大小可预知，而且不变
      - 如果关系的大小动态改变，而且数据库管理系统提供了动态 HASH 存取方法

- 设计关系、索引等数据库文件的物理存储结构

  - 确定如何在磁盘存储器上存储关系、索引和聚集，使得空间利用率最大化，数据操作引起的系统开销最小化
  - 和具体的数据库管理系统相关

## 物理存储结构

重点

- 硬盘缓冲区处理技术
- 硬盘容错技术--RAID1、4、5
- 磁盘文件--文件、属性表示、记录表示、页面组织、文件记录、文件存储方式（连续、链式、索引）
- 缓冲区管理--缓冲池的作用、缓冲区管理的基本原理、页面替换策略
- Hash 技术--动态 hash 技术
- 索引文件--主索引、聚集索引、辅助索引、多级索引、B+树索引

---

### 数据库存储设备

物理存储设备

- 高速缓冲存储器 Cache
- 主存
- 磁盘存储器
- 快速闪存存储器
- 固态硬盘

  - 写原理

    ![1703417661556](images/1703417661556.png)

  - 读原理

    ![1703417678649](images/1703417678649.png)

- 光学存储器
- 磁带存储器

存储塔

![1703417729460](images/1703417729460.png)

磁盘数据存储机制

![1703417758326](images/1703417758326.png)

![1703417777601](images/1703417777601.png)

磁盘的读写方式

![1703417807934](images/1703417807934.png)

磁盘寻址-柱面号+面号+扇区号

磁盘读写代价=寻道时间+旋转延迟+传输时间

磁盘调度策略

- 先来先服务
- 近者优先
- 全程移动扫描
- 移动扫描
- 分组扫描
- 间歇式全程移动扫描

容错技术

![1703418149139](images/1703418149139.png)

![1703418161841](images/1703418161841.png)

### 磁盘文件

文件和关系

|   文件   |       关系       |
| :------: | :--------------: |
|  数据项  | 属性值的物理形式 |
| 文件记录 |  元组的物理组织  |
|  文件块  | 多元组的物理存放 |
|   文件   |  关系的物理存放  |

数据项

- 最低级的数据组织形式
- 数据项语义

  - 表示关系数据库中元组的属性值

- 数据项类型

  ![1703418458462](images/1703418458462.png)

文件记录--数据项的集合,对应于一个关系元组

- 种类
  - 定长记录
  - 非定长记录
  - 每个属性值存储位置偏移量是 4 字节或 8 字节整数倍
- 多个文件记录的存储
  - 定长记录的存储
    - 单条记录不能跨块存储，一块上只能存储整数个记录
    - 文件中的记录是连续存储的，在删除记录后，需要对剩余的记录进行整理，否则会产生大量碎片
  - 记录整理
    - 移动填充
    - 空闲列表

文件块--记录集合，一个磁盘块

- 文件记录的存储方法

  - 跨块存储
  - 非跨块存储

- 种类

  - 记录固定的文件块

    - 数据库存储指向记录的指针
    - 移动删除记录时需修改指针
    - 很难知道多少指针需要修改，使得指针修改非常困难

  - 记录非固定的文件块

    - 磁盘块底保存间接寻址空间，为块中每个记录设置一个间接寻址项
    - 记录可在块中自由移动,不影响任何指向记录间接地址的指针

- 分槽的页结构--一种常见的文件块组织结构，普遍用于物理块内部的记录组织

  - 块头
    - 记录项的数量
    - 自由空间的末尾处
    - 每条记录位置和大小
  - 块尾
    - 连续的实际记录
  - 块中
    - 空闲空间
  - 删除记录
    - 释放该记录所占用的空间
    - 移动该记录之前的记录
    - 修改块头
  - 插入记录
    - 在块中空闲空间的尾部给这条记录分配空间
    - 修改块头
  - 记录的增长和缩短
    - 移动此记录之前的记录
    - 修改块头

磁盘文件

- 文件--文件块的集合，对应于一个关系
- 文件种类

  - 无序文件
  - 有序文件
  - 索引文件
  - Hash 文件

- 文件的存储方法

  - 连续存储
    - 按照文件中文件块的顺序把文件存储到连续磁盘块上
    - 存取整个文件的效率高
    - 文件扩充困难
  - 链接存储
    - 在每个文件块中增加一个指向下一个文件块所在的磁盘块的地址指针
    - 便于文件扩充
    - 读整个文件速度慢
    - 查询效率低
  - 索引存储
    - 在磁盘上存储一个或多个索引块，每个索引块包含指向文件块的指针
    - 查询处理高效

  ![1703419409356](images/1703419409356.png)

磁盘缓冲处理技术

- 缓冲池--DBMS 将可用内存划分为页数组
- 页框--缓冲池中的页
- 页表--记录缓冲池中当前由哪些页以及这些页在内存的地址
- 记录缓冲池中每个页框状态的变量
  - pin_count--页框中页当前被请求但未释放的次数，即引用次数
  - dirty--是否被修改
- 缓冲区管理器
  - 请求页
    - 缓冲区中存在：pin_count+=1，返回页框地址
    - 缓冲区中不存在：选择替换页--pin_count=0 的页将其 pin_count=1；写回脏页；读请求页
      - 如果不存在这样的页，阻塞请求；事实上 DBMS 会终止提出请求的事务并重做它
  - 释放页
    - unpin，即对应页 pin_count 减一
  - 修改页
    - 将该页 dirty 置为 1
  - 替换策略
    - LRU
    - 时钟策略
    - 立即丢弃策略
    - MRU
    - 预取
- 缓冲池和虚拟内存的异同
  - 相同点
    - 都用于访问内存放不下的数据
    - 都会在需要时调入页
    - 都会进行页替换
  - 不同点
    - DBMS 经常能更准确地预测页的访问顺序
    - OS 不具备内存中的页强制写回磁盘的能力，DBMS 必须具有强制写回的能力
    - 并发控制和故障恢复使得缓冲区管理器的设计更加复杂

### Hash 文件

基本概念

- hash 函数--将任意长度输入映射为定长输出
  - 除留取余
  - 平方取中
- hash 桶

静态 hash 方法--如果记录在 hash 属性上分布不均匀，可能出现 hash 冲突

- 文件被划分为 n 个 Hash 桶, 每个 Hash 桶对应一个磁盘块, 每个 Hash 桶有一个编号，Hash 函数的值域是桶号集合
- 每个 Hash 文件具有一个 Hash 桶目录。第 i 号 Hash 桶的目录项中存储该 Hash 桶对应的磁盘块地址
- 当 n 不大时，Hash 桶目录可以保存在主存储器，否则需存储在磁盘上
- 链接法--对于每个桶设置一个磁盘块链表, 第一个磁盘块存储正常记录，其他磁盘块存储溢出记录
- 局限性
  - 文件数量少时浪费大量空间
  - 文件数量超过一定数量后，磁盘块链会很长，影响存取效率

动态 hash 方法--_建议别看 ppt，依托_

- 可拓展 hash 方法

  - hash 函数是一个 b 位二进制序列，前 d 位标识桶的数目
  - d 的值随着文件增长而增大

- 线性 hash 方法

  - hash 函数

    ![1703420632045](images/1703420632045.png)

  - 何时分裂--当任意桶超出最大容量
  - 分裂后用新的 hash 函数重新分配数据

### 索引文件

索引--一种数据结构，通常是有序文件

- 索引也是一个文件

  - 索引文件的记录称为索引记录或索引项
  - 索引记录包括两个域
    - 一个域存储数据文件索引域的值
    - 一个域存储指针，指向记录地址
  - 通常按照索引域值的大小排序
  - 索引文件一般都远小于数据文件

- 多级索引
- 按结构分类

  - 稀疏索引
    - 按关键字值分组，每组一个索引
    - 索引项少，但更新代价高
  - 稠密索引
    - 每个记录一个索引
    - 索引文件有序
    - 查找更新方便，索引项多空间复杂性大

- 按索引域特点分类

  - 主索引（聚集索引）

    ![1703421156872](images/1703421156872.png)

  - 辅助索引

    ![1703421171841](images/1703421171841.png)

- 优点

  - 索引文件比数据文件小得多
  - 节省搜索时间

- 缺点

  - 更新时还要维护索引

### B+树和 B 树

自己看吧，都学过。_建议别看 ppt，依托。_

## 查询处理

重点

- 选择
- 投影（排序，去重）
- 连接算法
- 集合操作

~~额。。。总结了个寂寞~~

---

这一章差不多都是算法，简单写了

### 选择操作算法

简单选择操作

- 线性搜索
- 二分搜索--该属性有序
- 主索引或 HASH 搜索算法
  - 主索引属性或 HASH 属性上的相等比较
- 使用主索引查找满足条件的元组
  - 主索引属性上的非相等比较
- 使用复辅助索引查找满足条件的元组
  - 具有辅助索引的非键属性上相等比较
- B 树和 B+树索引搜索算法
  - B 树和 B+树索引属性上的相等或非相等比较

复杂选择操作

![1703421777794](images/1703421777794.png)

### 投影操作算法

![1703421816662](images/1703421816662.png)

后面判断包不包含码是为了去重

### 外存的归并排序

假设缓冲区有 n 块，待排序数据有 m 块

排序趟数$\log_n{m}$上取整

两趟多路归并代价分析

![1703422065640](images/1703422065640.png)

### 链接操作算法

![1703422105376](images/1703422105376.png)

- 一趟链接算法

  ![1703422123938](images/1703422123938.png)

- 基于元组的嵌套循环连接--S 为外关系，R 为内关系

  ![1703422181782](images/1703422181782.png)

  ![1703422201597](images/1703422201597.png)

- 基于块的循环嵌套连接

  ![1703422224399](images/1703422224399.png)

- 排序归并连接--假设可以两趟多路排序

  ![1703422266915](images/1703422266915.png)

- hash 连接

  ![1703422416249](images/1703422416249.png)

- 基于索引的连接

  ![1703422471638](images/1703422471638.png)

### 集合操作算法

一趟集合差算法

![1703422533947](images/1703422533947.png)

![1703422577912](images/1703422577912.png)

## 查询优化

重点

- 等价转换规则
- 表达式结果大小的估计--均匀分布
- 处理时间的估计
- 启发式优化算法

---

### 关系表达式的等价转换规则

![1703422664928](images/1703422664928.png)

![1703422673844](images/1703422673844.png)

![1703422684234](images/1703422684234.png)

![1703422693417](images/1703422693417.png)

![1703422703217](images/1703422703217.png)

### 表达式结果大小的估计

![1703422746075](images/1703422746075.png)

![1703422762944](images/1703422762944.png)

![1703422789046](images/1703422789046.png)

![1703422812329](images/1703422812329.png)

![1703422833177](images/1703422833177.png)

![1703422856573](images/1703422856573.png)

取值不均匀的估计--略

### 启发式优化

规则

- 选择和投影尽早执行
- 把某些选择操作和笛卡尔积结合形成连接操作
- 同时执行相同关系上多个选择和投影
- 把投影和连接操作结合执行
- 提取公共表达式

启发式算法

![1703423058742](images/1703423058742.png)

![1703423067899](images/1703423067899.png)

- 选择展开和下移
- 投影下移
- 投影和选择合并
- 选择和笛卡尔积合并
- 查询树的划分

## 并发控制

重点

- 事务的概念（ACID）、数据库的一致性
- 串行调度、可串行调度、冲突可串行化的判定方法--定义、冲突图
- 基于锁的并发控制协议--概念和种类、相容关系、两段锁协议、死锁的判定
- 基于时间戳的并发控制协议，两者比较。_这里好像没写_

---

**_这一章和下一章建议和书一起看_**

### 事务

- 用户定义的一个数据库操作序列，这些操作要么全做，要么全不做，是一个不可分割的工作单位
- 并发控制和恢复的基本单位

事务的特性（ACID）

- 原子性
- 一致性
- 隔离性
- 持久性

保证事务的 ACID 特性是事务处理的任务

破坏 ACID 特性的因素

- 多个事务并行运行时，不同事物的操作交叉执行
- 事务在运行时强行终止

### 事务的并发控制和调度

调度-–一个或多个事务的重要操作按时间排序的一个序列

串行调度--如果一个调度 S 的动作组成首先是一个事务的所有动作,然后是另一个事务的所有动作,依次类推、没有动作的混合

可串行化调度--不管数据库初始状态如何，该调度对数据库状态的影响都和某个串行调度相同

冲突

- 调度中一对连续的动作，它们满足：如果它们的顺序交换，那么涉及的事务中至少有一个的行为会改变
- 类比计组的写后写、写后读、读后写冲突

优先图的画法

![1703423603500](images/1703423603500.png)

![1703423643485](images/1703423643485.png)

冲突可串行性判断--优先图无环

### 并发控制协议

基于锁的协议

- 锁--数据项上的并发控制标志

  - 共享锁 S--只读
  - 互斥锁 X--读写
  - 相容关系
    ![1703423741186](images/1703423741186.png)

    ![1703423764213](images/1703423764213.png)

- 死锁--产生死锁的原因是两个或多个事务都已封锁了一些数据对象，然后又都请求对已为其他事务封锁的数据对象加锁，从而出现死等待

  - 死锁预防

    - 一次封锁法
      - 要求每个事务必须一次将所有要使用的数据全部加锁，否则就不能继续执行
      - 降低并发度
      - 难以事先确定封锁对象
    - 顺序封锁法
      - 预先对数据对象规定一个封锁顺序，所有事务都按这个顺序实行封锁
      - 维护成本高
      - 难以实现

  - 死锁诊断

    - 超时法

      - 事务超时认为发生死锁
      - 实现简单
      - 阈值太小，有可能误判
      - 阈值过大，无法及时检测

    - 事务等待图法

      ![1703423963888](images/1703423963888.png)

      - 周期性生成等待图，有环判断发生死锁

  - 死锁恢复

    - 选择牺牲者：选择代价最小的
      - 剩余时间
      - 已使用数据量
      - 未来使用数据量
      - 回滚涉及事务量
    - 回滚
      - 完全回滚
      - 部分回滚
    - 饿死--一个事务总是被选为牺牲者
      - 保证被选为牺牲者的次数有限

- 两段锁协议

  - 将事务分为两个阶段
    - 加锁段--能获得锁但不能释放锁
    - 解锁段--能解锁但不能获得锁
  - 事务开始就进入加锁段
  - 一旦释放锁则进入解锁段

- 改善的两段锁协议--添加锁的升级和降级操作

  ![1703424287196](images/1703424287196.png)

- 任何一个满足两段锁协议的合理调度都是冲突可串行的

剩余协议--略

## 数据库恢复

重点

- 数据库故障分类
- 使用日志的数据库恢复技术--日志的内容、redo、undo、推迟更新技术、即时更新技术
- 使用检查点的数据库恢复技术--日志的内容、哪些事务要 redo 和 undo
- 恢复算法--先写日志、后更新数据库

---

确保系统发生故障以后，数据库能够恢复到正确的状态

故障分类

- 事务故障
  - 逻辑故障
  - 系统错误
- 系统崩溃
- 硬盘故障

故障恢复和处理

- 确定用于存储数据的设备的故障方式
- 考虑这些故障方式对数据库的影响
- 提出在故障发生后仍保持数据库一致性及事务原子性的算法，主要分两部分
  - 在正常事务处理时采取措施，保证有足够的信息可用于故障恢复
  - 故障发生后采取措施，将数据库内容恢复到某个保证数据库一致性，事务原子性及持久性的状态

### 使用日志的数据库恢复技术

![1703424544577](images/1703424544577.png)

![1703424564876](images/1703424564876.png)

![1703424580410](images/1703424580410.png)

推迟更新技术

- 把数据库更新推迟到该事务提交时执行
- 推迟更新协议

  - 每个事务在到达提交点之前不能更新数据库
  - 在一个事务的所有更新操作对应的日志永久写入存储器之前，该事务不能到达提交点

- 当一个事务到达提交点时，称其进入部分提交状态
- 推迟更新协议保证当一个事务部分提交时，这个事务的所有更新操作的信息都记录在日志中
- 如果在一个事务部分提交之前异常结束或系统发生故障，日志中相关记录将被删除
- 恢复机制

  ![1703471895317](images/1703471895317.png)

- 需要重做的事务 T

  - 日志中包含开始和提交

- 恢复过程

  - 从后向前扫描日志，建立提交事务表和未提交事务表
  - 对提交事务表的每个事务 redo
  - 对未提交事务表的每个事务，删除所有日志记录

即时更新技术

- 允许事务直接更新数据库
- 即时更新协议

  - 所有<T,X, v1,v2>型日志记录安全地、永久存储到存储器之前，事务 T 不能更新数据库
  - 所有<T,X, v1,v2>型日志记录安全地、永久存储到存储器之前，不允许事务 T 提交
  - 保证在故障发生时，每个运行事务的更新操作的描述信息都安全地记录在日志中

    ![1703472485432](images/1703472485432.png)

- 恢复处理过程

  ![1703472518251](images/1703472518251.png)

  - 一般在 redo 之前做 undo

### 使用检查点的数据库恢复技术

上面技术存在的问题

- 搜索过程太耗时
- 大多数重做操作已经写入数据库中，全部重做会使得恢复过程太长

具有检查点的恢复技术

- 在日志中增加检查点记录
- 恢复子系统在登录日志文件期间动态地维护日志

检查点的执行过程如下

- 将位于主存的日志输出到稳定存储器
- 将所有修改的缓冲块输出到磁盘
- 写一个 checkpoint 日志记录，包含当前活跃的事务列表

在检查点执行过程中，不允许事务执行任何更新

建立检查点的时机

- 定期--按照预定的时间间隔建立检查点
- 不定期--按照某种规则建立检查点

恢复过程

![1703472917031](images/1703472917031.png)

### 恢复算法

回滚操作算法

![1703472950415](images/1703472950415.png)

系统崩溃后的恢复算法

- 重做阶段

  ![1703472974555](images/1703472974555.png)

- 撤销阶段

  ![1703472987259](images/1703472987259.png)

### 缓冲技术

![1703473037812](images/1703473037812.png)

![1703473046203](images/1703473046203.png)

![1703473056599](images/1703473056599.png)

<div STYLE="page-break-after: always;"></div>

老婆镇楼

![1703474109879](images/1703474109879.jpg)