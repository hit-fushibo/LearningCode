`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/02 21:54:15
// Design Name: 
// Module Name: IF_ID_Reg
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


module IF_ID(
    input clk,
    input resetn,
    input wen,
    input [31:0] ir_input,
    input [31:0] if_adder_output,
    input [31:0] pc_input,
    output [31:0] ir_output,
    output [31:0] npc,
    output [31:0] pc_output
    );


    npc U_IF_ID_NPC (
        .clk (clk),
        .reset (resetn),
        .write_enable (wen),
        .pc_input (if_adder_output),
        .npc (npc)
    );

    IR U_IF_ID_IR (
        .clk(clk),
        .reset(resetn),
        .write_enable (wen),
        .instr_input (ir_input),
        .instr_output (ir_output)
    );

    pc U_IF_ID_PC (
        .clk (clk),
        .rst (resetn),
        .write_enable(wen),
        .pc_input (pc_input),
        .pc_output (pc_output)
    );

endmodule
