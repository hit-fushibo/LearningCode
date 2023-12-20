`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/01 10:47:24
// Design Name: 
// Module Name: pc
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


module pc(
    input clk,                 // 输入时钟信号
    input rst,                 // 输入复位信号
    input write_enable,        // 输入写使能信号
    input [31:0] pc_input,     // 输入PC输入数据
    output reg [31:0] pc_output // 输出PC输出数据
    );

    initial begin
        pc_output <= 32'h0000_0000; // 初始时将PC输出数据设置为全零
    end

    always @(posedge clk) begin  // 在时钟上升沿触发时执行以下操作
        if (!rst) begin           // 如果复位信号为低电平
            pc_output <= 32'd0;   // 将PC输出数据重新设置为零
        end
        else begin                // 如果复位信号为高电平
            if (write_enable) begin  // 如果写使能信号为高电平
                pc_output <= pc_input;  // 将PC输出数据设置为输入的PC输入数据
            end
        end
    end
endmodule
