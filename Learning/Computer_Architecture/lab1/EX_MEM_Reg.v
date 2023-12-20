`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/02 21:54:58
// Design Name: 
// Module Name: EX_MEM_Reg
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

`include "define.v"

module EX_MEM(
    input clk,
    input resetn,
    input write_enable,
    input [31:0] alureg_input,
    input [31:0] ir_input,
    input [31:0] pc_input,
    input [31:0] mem_cond,

    // data output
    output [31:0] alureg_output,
    output [31:0] ir_output,
    output [31:0] pc_output,
    output reg [31:0] wb_cond,
    // control output
    output reg dmem_write_enable,
    output reg mux_pc_select,
    output reg adder_jump_select
    );

    initial begin
        wb_cond <= 32'h0;
        dmem_write_enable <= 1'b0;
        mux_pc_select <= 1'b0;
        adder_jump_select <= 1'b0;
    end
    

    always @(ir_output) begin
        case (ir_output[31:26]) 
            `OPERATION: begin
                dmem_write_enable <= 1'b0;
                mux_pc_select <= 1'b0;
                adder_jump_select <= 1'b1;
            end
            `SW: begin
                dmem_write_enable <= 1'b1;
                mux_pc_select <= 1'b0;
                adder_jump_select <= 1'b1;
            end
            `LW: begin
                dmem_write_enable <= 1'b0;
                mux_pc_select <= 1'b0;
                adder_jump_select <= 1'b1;
            end
            `BNE: begin
                dmem_write_enable <= 1'b0;
                mux_pc_select <= 1'b1;
                adder_jump_select <= 1'b1;
            end
            `J: begin
                dmem_write_enable <= 1'b0;
                mux_pc_select <= 1'b1;
                adder_jump_select <= 1'b0;
            end
            default: 
                $display("fault opcode: $h", ir_output[31:26]);
        endcase
        wb_cond <= mem_cond;
    end

    
    data_reg U_aluoutput(
        .clk (clk),
        .reset (resetn),
        .write_enable (write_enable),
        .reg_input (alureg_input),
        .reg_output (alureg_output)
    );

    IR U_EX_MEM_IR (
        .clk(clk),
        .reset(resetn),
        .write_enable (write_enable),
        .instr_input (ir_input),
        .instr_output (ir_output)
    );

    pc U_EX_MEM_PC (
        .clk (clk),
        .rst (resetn),
        .write_enable(write_enable),
        .pc_input (pc_input),
        .pc_output (pc_output)
    );
endmodule
