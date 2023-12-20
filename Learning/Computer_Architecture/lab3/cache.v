`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/11 13:49:15
// Design Name: 
// Module Name: cache
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module cache(
    input            clk             ,  // clock, 100MHz
    input            rst             ,  // active low

    //  Sram-Like接口信号，用于CPU访问Cache
    input         cpu_req      ,    //由CPU发送至Cache
    input  [31:0] cpu_addr     ,    //由CPU发送至Cache
    output [31:0] cache_rdata  ,    //由Cache返回给CPU
    output        cache_addr_ok,    //由Cache返回给CPU
    output        cache_data_ok,    //由Cache返回给CPU

    //  AXI接口信号，用于Cache访问主存
    output [3 :0] arid   ,              //Cache向主存发起读请求时使用的AXI信道的id号
    output [31:0] araddr ,              //Cache向主存发起读请求时所使用的地址
    output        arvalid,              //Cache向主存发起读请求的请求信号
    input         arready,              //读请求能否被接收的握手信号

    input  [3 :0] rid    ,              //主存向Cache返回数据时使用的AXI信道的id号
    input  [31:0] rdata  ,              //主存向Cache返回的数据
    input         rlast  ,              //是否是主存向Cache返回的最后一个数据
    input         rvalid ,              //主存向Cache返回数据时的数据有效信号
    output        rready                //标识当前的Cache已经准备好可以接收主存返回的数据
    );
    /*TODO：完成指令Cache的设计代码*/
    wire valid1;
    wire valid2;
    wire [19:0] tag1;
    wire [19:0] tag2;
    wire [31:0] data1;
    wire [31:0] data2;
    wire [31:0] cpu_addr_out;
    wire wend;

    wire wen;             
    wire [255:0] write_data;  
    wire [31:0] write_addr;    


    CONTROL U_CONTROL(
        .clk(clk),
        .rst(rst),
        .cpu_addr_in(cpu_addr_out),
        .valid1(valid1),
        .valid2(valid2),
        .tag1(tag1),
        .tag2(tag2),
        .data1(data1),
        .data2(data2),
        .w_end(wend),
        .arready(arready),
        .rid(rid),
        .rdata(rdata),
        .rlast(rlast),
        .rvalid(rvalid),
        .rready(rready),
        .cache_rdata(cache_rdata),
        .cache_addr_ok(cache_addr_ok),
        .cache_data_ok(cache_data_ok),
        .wen(wen),
        .wdata(write_data),
        .waddr(write_addr),
        .arid(arid),
        .araddr(araddr),
        .arvalid(arvalid)
    );



    
    cache_ram U_cache_ram(
        .clk(clk),
        .rst(rst),
        .store_in_en(cache_data_ok),
        .cpu_req(cpu_req),
        .cpu_addr(cpu_addr),
        .valid1_out(valid1),
        .valid2_out(valid2),
        .tag1_out(tag1),
        .tag2_out(tag2),
        .data1_out(data1),
        .data2_out(data2),
        .cpu_addr_out(cpu_addr_out),
        .wen(wen),
        .write_addr_in(write_addr),
        .write_data_in(write_data),
        .wend(wend)
    );


    
endmodule
