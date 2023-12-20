`timescale 1ns / 1ps

`include "define.v"

module ID_EX (
    input clk,
    input resetn,
    input write_enable,
    input [31:0] ir_input,
    input [31:0] reg_A_input,
    input [31:0] reg_B_input,
    input [31:0] imm_input,
    input [31:0] npc_input,
    input [31:0] pc_input,
    // �������
    output [31:0] ir_output,
    output [31:0] npc_output,
    output [31:0] reg_A_output,
    output [31:0] reg_B_output,
    output [31:0] imm_output,
    output [31:0] pc_output,
    // �������
    output reg mux_A_select,
    output reg mux_B_select,
    output reg mux_sll_select,
    output reg [5:0] alu_op
);

    initial begin
        mux_A_select <= 1'b0;
        mux_B_select <= 1'b0;
        mux_sll_select <= 1'b0;
        alu_op <= 6'b000000;
    end

    always @(ir_output) begin
        case (ir_output[31:26]) 
            `OPERATION: 
            begin
                mux_A_select <= 1'b0;
                mux_B_select <= 1'b0;
                alu_op <= ir_output[5:0];     
                if (ir_output[5:0] == 6'b000000) 
                begin
                    mux_sll_select <= 1'b0;
                end 
                else 
                begin
                    mux_sll_select <= 1'b1;
                end
            end
            `SW: 
            begin
                mux_A_select <= 1'b0;
                mux_B_select <= 1'b1;
                alu_op <= `ADD;
                mux_sll_select <= 1'b1;
            end
            `LW: 
            begin
                mux_A_select <= 1'b0;
                mux_B_select <= 1'b1;
                alu_op <= `ADD;
                mux_sll_select <= 1'b1;
            end
            `BNE: 
            begin
                mux_A_select <= 1'b0;
                mux_B_select <= 1'b1;
                if(reg_A_output == reg_B_output) begin
                    alu_op <= `B;
                end
                mux_sll_select <= 1'b1;
            end
            `J: 
            begin
                mux_A_select <= 1'b0;
                mux_B_select <= 1'b1;
                alu_op <= `B;
                mux_sll_select <= 1'b1;
            end
            default: 
                $display("fault opcode: $h", ir_output[31:26]);
        endcase
    end

    npc U_ID_EX_NPC(
        .clk (clk),
        .reset (resetn),
        .write_enable (write_enable),
        .pc_input (npc_input),
        .npc (npc_output)
    );

    data_reg U_A (
        .clk (clk),
        .reset(resetn),
        .write_enable (write_enable),
        .reg_input (reg_A_input),
        .reg_output (reg_A_output)
    );

    data_reg U_B (
        .clk (clk),
        .reset (resetn),
        .write_enable (write_enable),
        .reg_input (reg_B_input),
        .reg_output (reg_B_output)
    );

    imm U_imm (
        .clk (clk),
        .reset (resetn),
        .write_enable (write_enable),
        .reg_input (imm_input),
        .reg_output (imm_output)
    );

    IR U_ID_EX_IR (
        .clk(clk),
        .reset(resetn),
        .write_enable (write_enable),
        .instr_input (ir_input),
        .instr_output (ir_output)
    );

    pc U_ID_EX_PC (
        .clk (clk),
        .rst (resetn),
        .write_enable(write_enable),
        .pc_input (pc_input),
        .pc_output (pc_output)
    );
endmodule