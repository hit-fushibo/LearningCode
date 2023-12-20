`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/03 09:32:43
// Design Name: 
// Module Name: data_reg
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


module data_reg(
    input clk,
    input reset,
    input write_enable,
    input [31:0] reg_input,
    output reg [31:0] reg_output
    );

    initial begin 
        reg_output <= 32'h0000_0000;
    end

    always @(posedge clk) begin
        if (!reset) begin
            reg_output <= 32'h0000_0000;
        end
        else begin
            if (write_enable) begin
                reg_output <= reg_input;
            end
        end
    end

endmodule
