`timescale 1ns / 1ps

`include "define.v"

module MEM_WB (
    input clk,
    input resetn,
    input write_enable,
    input [31:0] ir_input,
    input [31:0] lmd_input,
    input [31:0] mem_cond,
    input [31:0] wb_cond,
    input [31:0] alureg_input,
    input [31:0] pc_input,
    
    // data output
    output  [31:0] ir_output,
    output  [31:0] lmd_output,
    output  [31:0] alureg_output,
    output [31:0] pc_output,
    // control output 
    output reg reg_write_enable,
    output reg write_back_mux_select,
    output reg [4:0] write_back_addr
);
    initial begin
        reg_write_enable <= 1'b0;
        write_back_mux_select <= 1'b0;
        write_back_addr <= 5'b00000;
    end

    always @(ir_output) begin
        case (ir_output[31:26]) 
            `OPERATION: begin
                write_back_mux_select <= 1'b1;
                write_back_addr <= ir_output[15:11];
                // movz 情况
                if (ir_output[10:0] == 11'b00000_001010 && (wb_cond != 32'h0)) begin
                    reg_write_enable <= 1'b0;
                end else begin
                    reg_write_enable <= 1'b1;
                end
            end
            `SW: begin
                write_back_mux_select <= 1'b0;
                write_back_addr <= ir_output[20:16];
                reg_write_enable <= 1'b0;
            end
            `LW: begin
                write_back_mux_select <= 1'b0;
                write_back_addr <= ir_output[20:16];
                reg_write_enable <= 1'b1;
            end
            `BNE: begin
                write_back_mux_select <= 1'b1;
                reg_write_enable <= 1'b0;
            end
            `J: begin
                write_back_mux_select <= 1'b1;
                reg_write_enable <= 1'b0;
            end
            default: 
                $display("fault opcode: $h", ir_output[31:26]);
        endcase
        
    end

    IR U_MEM_WB_IR (
        .clk(clk),
        .reset(resetn),
        .write_enable (write_enable),
        .instr_input (ir_input),
        .instr_output (ir_output)
    );

    data_reg U_aluoutput(
        .clk (clk),
        .reset (resetn),
        .write_enable (write_enable),
        .reg_input (alureg_input),
        .reg_output (alureg_output)
    );

    data_reg U_LMD (
        .clk (clk),
        .reset (resetn),
        .write_enable (write_enable),
        .reg_input (lmd_input),
        .reg_output (lmd_output)
    );

    pc U_MEM_WB_PC (
        .clk (clk),
        .rst (resetn),
        .write_enable(write_enable),
        .pc_input (pc_input),
        .pc_output (pc_output)
    );

endmodule 