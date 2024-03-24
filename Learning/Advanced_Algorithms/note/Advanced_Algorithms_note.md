# 2024 春高级算法笔记

## 第一章 绪论

### 集合的相似性连接

算法描述

- 输入：集族$\mathscr{A}$，阈值$a$
- 输出：$\{(A,B)|A,B\in \mathscr{A},sim(A,B)>a \}$
  - $sim(A,B)=|A\cap B| / |A\cup B |$

minHash 方法

思想：通过随机排列集合中的元素，并统计每次排列后两个集合同时按顺序取到第一个元素的次数与随机排列的次数之比作为两个集合的相似性

例：

![1711282475807](images/1711282475807.png)

A，B 两个集合同时按顺序取到第一个元素两次，随机排列了四次，所以在这里 A，B 的相似度为 1/2

如何随机排列：hash 方法，用 hash 函数$h_i:U\rightarrow[0:|U|-1]$

对于下面的集合和 hash 函数，算法运行如下：

![1711283234309](images/1711283234309.png)

- 首先，生成一个 4\*2 的表格 T 用来记录在每个 hash 函数下集合的 minHash 值，初始值均为无穷大
- 对于 T 的每一行，遍历 hash 函数表格中的对应行，根据元素是否在集合中来更新 T 中的记录
  - 取 hash 值与记录值的最小值
- 遍历完 T 的所有行之后，根据每两列中值相同的行数与总行数之比判定两个集合是否相似

## 第二章 随机算法及其分类

### 2.1 概论基础

#### 概率空间

- 样本空间$\Omega$：所有基本事件（样本）构成的集合
- 事件集合$\Sigma$：$\Omega$的一个子集称为一个事件
  - $\empty,\Omega\in\Sigma$
  - 对$\cup,\cap,/\ $封闭
- 概率测度$Pr$：$\Sigma\rightarrow R$取非负值
  - $Pr(\Omega)=1$
  - $A\cap B=\empty\Rightarrow Pr(A\cup B)=Pr(A)+Pr(B)$
  - $A_1\supset A_2\supset\dots and \cap_nA_n=\empty\Rightarrow\lim_{n\rightarrow \infty}{Pr(A_n)}=0$
- 事件
  - 谓词$\epsilon$
  - 集合$A={x\in \Omega|\epsilon(x) }$
- 概率
  - $Pr(\epsilon )=Pr(A)$
  - 性质
    - $Pr(\neg \epsilon)=1-Pr(\epsilon)$
    - $\epsilon_1\Rightarrow\epsilon_2,Pr(\epsilon_1)\leq Pr(\epsilon_2)$
    - $Pr(\epsilon_1\lor\epsilon_2)=Pr(\epsilon_1)+Pr(\epsilon_2)-Pr(\epsilon_1\land\epsilon_2)$

#### 容斥原理

![1711284340381](images/1711284340381.png)

![1711284354550](images/1711284354550.png)

#### 合并界限-Union Bound

![1711284378566](images/1711284378566.png)

#### 条件概率

- 在随机事件$\epsilon_2$发生的条件下$\epsilon_1$发生的概率
- $Pr(\epsilon_1|\epsilon_2)=\frac{Pr(\epsilon_1\land\epsilon_2)}{Pr(\epsilon_2)}$

#### 条件概率链

![1711284501044](images/1711284501044.png)

#### 全概率公式

![1711284522076](images/1711284522076.png)

#### 随机变量

- 本质是一个函数$X:\Omega\rightarrow R$
- 事件$X=x$即$\{s\in Q|X{s}=x \}$
- $Pr(X=x)=Pr(\{s\in Q|X(s)=x\})$

#### 随机变量的独立性

- 随机变量$X$和$Y$是独立的，如果$Pr(X=x\land Y=y)=Pr(X=x)\cdot Pr(Y=y)$，对任意的$x,y$成立

  ![1711285586452](images/1711285586452.png)

#### 随机变量的数学期望

- 离散随机变量$X$的数学期望定义为$E[X]=\sum_x{x\cdot Pr(X=x)}$
- 期望的线性性质

  ![1711285661573](images/1711285661573.png)

#### 马尔可夫不等式-Markov 不等式

- 对于任意**非负**随机变量$X$，$Pr(X\geq t)\leq\frac{E[x]}{t}$，对于所有的$t>0$都成立
- 推广
  - 对于任意随机变量$X$和**非负**函数$h:X\rightarrow R^+$，$Pr(h(X)\geq t)\leq\frac{E[h(X)]}{t}$，对于任意$t>0$成立

#### 随机变量的方差

- 离散随机变量的方差定义为$Var[X]=E[(X-E[X])^2]$
- 方差的算术平方根称为标准差，记为$\delta[X]$
- $Var[X]=E[X^2]-E[X]^2$

#### 二项分布

- 如果随机变量$X$满足$Pr(X=1)=p,Pr(X=0)=1-p$，则称$X$服从二项分布
- 期望$E[X]=p$
- 方差$Var[X]=p(1-p)$

#### 切比雪夫不等式-Chebyshev 不等式

- 对于任意随机变量$X$，$Pr(|X-E[X]|\geq t)\leq \frac{Var[X]}{t^2}$，对任意的$t>0$成立
- 推广
  - 对于任意随机变量$X$，$Pr(|X-E[X]|\geq t\cdot\delta[X])\leq \frac{1}{t^2}$，对任意的$t>0$成立

#### 尾概率界-tail bound

- $Pr(X>t)<\epsilon$
- 分析手段
  - 计数并计算概率
    - 计算量大
    - 方法不一定有效
  - 将尾概率的计算归结为分析$X$的某种特征$I$
    - 马尔可夫不等式-期望是紧的
    - 切比雪夫不等式
    - 切尔诺夫界

### 2.2 数值随机算法

#### 计算$\pi$值

- ![1711286435845](images/1711286435845.png)
- ![1711286449463](images/1711286449463.png)
- 时间复杂度$O(n)$
  - 不是输入样本大小，而是随机样本的大小
- 解的精确度
  - 随着随机样本大小的增加而增加

#### 计算定积分

- ![1711286540645](images/1711286540645.png)
- ![1711286597824](images/1711286597824.png)
- ![1711286638405](images/1711286638405.png)
- 时间复杂度$O(n)$
- 解的精确度
  - 随着随机样本大小的增加而增加

### 2.3 随机选择和拉斯维加斯算法
