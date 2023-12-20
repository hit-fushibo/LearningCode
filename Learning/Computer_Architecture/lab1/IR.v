`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/01 21:09:07
// Design Name: 
// Module Name: IR
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

module IR(
    input clk,
    input reset,
    input write_enable,
    input [31:0] instr_input,
    output reg [31:0] instr_output
    );

    initial begin 
        instr_output <= 32'h0000_0000;
    end

    always @(posedge clk) begin 
        if (!reset) begin
            instr_output <= 32'h0000_0000;
        end
        else begin
            if (write_enable) begin
                instr_output <= instr_input;
            end
        end
    end

endmodule
