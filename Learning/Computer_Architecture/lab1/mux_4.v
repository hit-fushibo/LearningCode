`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/03 14:45:06
// Design Name: 
// Module Name: mux_4
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


module mux_4(
    input [31:0] A,
    input [31:0] B,
    input [31:0] C,
    input [31:0] D,
    input [1:0] select,
    output reg [31:0] result
    );

    always @(*) begin
        case (select) 
            2'b00: begin
                result = A;
            end
            2'b01: begin
                result = B;
            end
            2'b10: begin
                result = C;
            end
            2'b11: begin
                result = D;
            end
        endcase
    end
endmodule
