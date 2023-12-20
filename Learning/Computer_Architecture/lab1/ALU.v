`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/08/27 18:58:51
// Design Name: 
// Module Name: alu
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

// define all calculator
`define ADD  6'b100000
`define SUB  6'b100010
`define AND  6'b100100
`define OR   6'b100101
`define XOR  6'b100110
`define SLT  6'b101010
`define MOVZ 6'b001010
`define SLL  6'b000000
`define A    6'b000001
`define B    6'b000010

module alu (
    input  [31:0]   A   ,
    input  [31:0]   B   ,
    input  [5:0]  Card,
    output [31:0] result
);

    wire [31:0] add_result ;
    wire [31:0] sub_result ;
    wire [31:0] and_result ;
    wire [31:0] or_result  ;
    wire [31:0] xor_result ;
    wire [31:0] slt_result ;
    wire [31:0] movz_result;
    wire [31:0] sll_result ;

    assign add_result  = A + B;
    assign sub_result  = A - B;
    assign and_result  = A & B;
    assign or_result   = A | B;
    assign xor_result  = A ^ B;
    assign slt_result  = (A < B) ? 32'b1 : 32'b0;
    assign movz_result = (B == 32'b0) ? A : 32'b0;
    assign sll_result  = B << A;
    
    assign  result   =   ({32{Card == `ADD }}  & add_result)   |
                         ({32{Card == `SUB }}  & sub_result)   |
                         ({32{Card == `AND }}  & and_result)   |
                         ({32{Card == `OR  }}  & or_result)    |
                         ({32{Card == `XOR }}  & xor_result)   |
                         ({32{Card == `SLT }}  & slt_result)   |
                         ({32{Card == `MOVZ}}  & movz_result)  |
                         ({32{Card == `SLL }}  & sll_result);

endmodule