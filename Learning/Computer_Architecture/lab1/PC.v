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
    input clk,                 // ����ʱ���ź�
    input rst,                 // ���븴λ�ź�
    input write_enable,        // ����дʹ���ź�
    input [31:0] pc_input,     // ����PC��������
    output reg [31:0] pc_output // ���PC�������
    );

    initial begin
        pc_output <= 32'h0000_0000; // ��ʼʱ��PC�����������Ϊȫ��
    end

    always @(posedge clk) begin  // ��ʱ�������ش���ʱִ�����²���
        if (!rst) begin           // �����λ�ź�Ϊ�͵�ƽ
            pc_output <= 32'd0;   // ��PC���������������Ϊ��
        end
        else begin                // �����λ�ź�Ϊ�ߵ�ƽ
            if (write_enable) begin  // ���дʹ���ź�Ϊ�ߵ�ƽ
                pc_output <= pc_input;  // ��PC�����������Ϊ�����PC��������
            end
        end
    end
endmodule
