# 哈工大本部2023秋计算网络笔记

## 1.计算机网络概述

### 1.1计算机网络基本概念

#### 1.1.1计算机网络

计算机网络是**通信技术**与**计算机技术**紧密结合的产物，就是一种通信网络。

计算机网络就是**互连的、自治的**计算机集合。

* 互连：互联互通
* 自治：无主从关系

当计算机距离远、数量大时需要通过交换网络互联主机。

什么是Internet：

* 组成细节角度：ISP网络互连的“网络之网络”
  * 计算机设备的集合
  * 通信链路
  * 分组交换
* 服务角度：
  * 为网络应用提供通信服务的通信基础设施
  * 为网络应用提供应用编程接口

#### 1.1.2网络协议

网络协议(network protocol)，简称为协议，是为进行网络中的数据交换而建立的规则、标准或约定。规定了通信实体之间所交换的信息的**格式、意义、顺序**以及针对收到的信息或发生的事件所采取的“**动作**”。协议规范了网络中所有信息发送和接收过程

协议三要素：

1. 语法
2. 语义
3. 时序

### 1.2计算机网络结构

#### 网络边缘

* 主机（端系统）
  * 位于网络边缘
  * 可分为客户和服务器，客户/服务器应用模型(CS)：客户发送请求，接受服务器响应
  * 对等应用模型(P2P)：无（不仅依赖）专用服务器，通信在对等实体之间直接进行
* 网络应用

#### 接入网络

将端系统物理连接到其边缘路由器的网络

##### 数字用户线路（DSL）

利用已有的电话线连接中心局的DSLAM

* 数据通信通过DSL电话线接入Internet
* 电话通过DSL电话线接入电话网
* <2.5Mbps上行传输速率
* <24Mbps下行传输速率

使用频分多路复用技术，在不同频带上传输不同频道

* 50kHz~1MHz用于下行
* 4kHz~50kHz用于上行
* 0kHz~4kHz用于传统电话

##### 电缆网络

利用混合光纤同轴电缆（HFC）进行连接

* 30Mbps下行传输速率
* 2Mbps上行传输速率

各家庭通过电缆网络->光纤接入ISP路由器

* 各家庭共享家庭到电缆头端的接入网络
* DSL独占至中心局的接入网络

典型的家庭接入网络![1693970052668](image/Computer_Network/1693970052668.png)

##### 以太网

* 机构企业常用
* 典型传输速率： 10 Mbps, 100Mbps, 1Gbps, 10Gbps
* 目前，端系统通常直接连接以太网交换机（switch）

##### 无线接入网络

通过共享的无线接入网络连接端系统和路由器

* 无线局域网（LANs）：
  * 同一建筑物内
  * 11Mbps、54Mbps传输速率
* 广域无线接入网络：
  * 通过运营商的蜂窝网络，接入范围在几十公里
  * 1Mbps、10Mbps、100Mbps传输速率

#### 网络核心

互联的路由器网络，关键功能是：路由和转发

* 路由：确定分组从源到目的地的传输路径
* 转发：将分组从路由器的输入端口交换至正确的输出端口

### 1.3数据交换