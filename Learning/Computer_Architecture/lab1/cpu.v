`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/01 21:13:35
// Design Name: 
// Module Name: cpu
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

module cpu(
    input clk,
    input resetn,

    output [31:0] debug_wb_pc,
    output debug_wb_rf_wen,
    output [4:0] debug_wb_rf_addr,
    output [31:0] debug_wb_rf_wdata
    );

    wire wb_wen,D_wen,  
         mux_A_select,mux_B_select,mux_pc_select,WB_mux_select,mux_sll_select,
         adder_jump_select,
         pc_write,if_id_write_enable,id_ex_reset;

    wire [1:0] mux_A_select_dir,mux_B_select_dir;

    wire [4:0] WB_addr;

    wire [5:0] alu_op;

    wire [31:0] 
         pc_i, 
         pc_o, 
         pc_adder_o, 
         imem_output, 
         npc, 
         reg_files_outputA, 
         reg_files_outputB, 
         ext_out, 
         reg_A_output, 
         reg_B_output, 
         reg_imm_output, 
         write_back_data, 
         alu_A_input, 
         alu_B_input, 
         alu_output, 
         alureg_output, 
         dmem_data_output, 
         lmd_output, 
         alu_A_sll_input, 
         npc_adder_output, 
         jump_select_output,
         mem_alu_reg_output,
         
         mux_A_output_dir,
         mux_B_output_dir,
         
         if_id_ir,
         id_ex_ir,
         ex_mem_ir,
         mem_wb_ir,
         
         id_ex_npc,
         if_pc,
         id_pc,
         ex_pc,
         mem_pc,
         
         mem_cond,
         wb_cond;

    reg write_enable;

    assign debug_wb_rf_wen = wb_wen;
    assign debug_wb_pc = mem_pc;
    assign debug_wb_rf_addr = WB_addr;
    assign debug_wb_rf_wdata = write_back_data;


    initial begin
        write_enable <= 1'b1;
    end

    pc u_pc(
        .clk (clk),
        .rst (resetn),
        .write_enable(pc_write),
        .pc_input (pc_i),
        .pc_output (pc_o)
    );   

    adder u_adder (
        .A (pc_o),
        .B (32'h4),
        .F (pc_adder_o)
    );//pc+4

    mux u_mux_pc (
        .A (npc),
        .B (jump_select_output),
        .select (mux_pc_select),
        .out (pc_i)
    );

    IMEM u_IMEM (
        .clk (clk),
        .raddr (pc_o),
        .rdata (imem_output)
    );

    IF_ID u_IF_ID (
        .clk(clk),
        .resetn(resetn),
        .wen (if_id_write_enable),
        .ir_input (imem_output),
        .pc_input(pc_o),
        .if_adder_output (pc_adder_o),
        .ir_output (if_id_ir),
        .npc (npc),
        .pc_output (if_pc)
    );

    regs u_regs (
        .clk (clk),
        .raddr1 (if_id_ir[25:21]),
        .raddr2 (if_id_ir[20:16]),
        .we (wb_wen),
        .waddr (WB_addr),
        .wdata (write_back_data),
        .rdata1 (reg_files_outputA),
        .rdata2 (reg_files_outputB)
    );

    extender u_extender (
        .instr_index (if_id_ir[15:0]),
        .out (ext_out) 
    );

    stall_detection_unit u_stall_detection_unit (
        .if_id_ir (if_id_ir),
        .id_ex_ir (id_ex_ir),
        .pc_write (pc_write),
        .if_id_write_enable (if_id_write_enable),
        .id_ex_reset (id_ex_reset)
    );

    ID_EX u_ID_EX(
        .clk(clk),
        .resetn(id_ex_reset),
        .write_enable(write_enable),
        .ir_input (if_id_ir),
        .reg_A_input(reg_files_outputA),
        .reg_B_input (reg_files_outputB),
        .imm_input (ext_out),
        .npc_input (npc),
        .pc_input (if_pc),
        .ir_output (id_ex_ir),
        .npc_output (id_ex_npc),
        .reg_A_output (reg_A_output),
        .reg_B_output (reg_B_output),
        .imm_output (reg_imm_output),
        .pc_output (id_pc),

        .mux_A_select(mux_A_select),
        .mux_B_select (mux_B_select),
        .mux_sll_select (mux_sll_select),
        .alu_op (alu_op)
    );

    mux u_alu_mux1 (
        .A (reg_A_output),
        .B (npc),
        .select (mux_A_select),
        .out (alu_A_input)
    ); 

    mux u_sll_mux (
        .A ({{27'd0}, id_ex_ir[10:6]}),
        .B (alu_A_input),
        .select (mux_sll_select),
        .out (alu_A_sll_input)
    ); 

    mux u_alu_mux2 (
        .A (reg_B_output),
        .B (reg_imm_output),
        .select (mux_B_select),
        .out (alu_B_input)
    );

    dir_unit u_dir_unit (
        .id_ex_ir (id_ex_ir),
        .ex_mem_ir (ex_mem_ir),
        .mem_wb_ir (mem_wb_ir),
        .mem_cond (mux_B_output_dir),
        .wb_cond (wb_cond),   
        .forward_A (mux_A_select_dir),
        .forward_B (mux_B_select_dir)
    );

    mux_4 u_mux_A (
        .A (alu_A_sll_input),
        .B (alureg_output),
        .C (write_back_data),
        .D (),
        .select (mux_A_select_dir),
        .result (mux_A_output_dir)
    );

    mux_4 u_mux_B (
        .A (alu_B_input),
        .B (alureg_output),
        .C (write_back_data),
        .D (),
        .select (mux_B_select_dir),
        .result (mux_B_output_dir)
    );

    alu u_alu (
        .A (mux_A_output_dir),
        .B (mux_B_output_dir),
        .Card (alu_op),
        .result(alu_output)
    );

    EX_MEM u_EX_MEM (
        .clk(clk),
        .resetn(resetn),
        .write_enable(write_enable),
        .alureg_input (alu_output),
        .ir_input (id_ex_ir),
        .pc_input (id_pc),
        .mem_cond(mux_B_output_dir),

        .alureg_output (alureg_output),
        .ir_output (ex_mem_ir),
        .pc_output (ex_pc),
        .wb_cond (wb_cond),

        .dmem_write_enable(D_wen),
        .mux_pc_select (mux_pc_select),
        .adder_jump_select (adder_jump_select)
    );

    npc_adder u_npc_adder (
        .A (npc),
        .B (alureg_output),
        .F (npc_adder_output)
    );

    mux u_jump_select (
        .A ({npc[31:28], ex_mem_ir[25:0], {2'b0}}),
        .B (npc_adder_output),
        .select (adder_jump_select),
        .out (jump_select_output)
    );

    DMEM u_DMEM (
        .clk(clk),
        .raddr (alureg_output),
        .waddr (alureg_output),
        .write_enable (D_wen),
        .wdata (reg_B_output),
        .rdata (dmem_data_output)
    );

    MEM_WB u_MEM_WB(
        .clk(clk),
        .resetn(resetn),
        .write_enable(write_enable),
        .ir_input (ex_mem_ir),
        .lmd_input (dmem_data_output),
        .mem_cond (mem_cond),
        .wb_cond (wb_cond),
        .alureg_input (alureg_output),
        .pc_input (ex_pc),

        .ir_output (mem_wb_ir),
        .lmd_output (lmd_output),
        .alureg_output (mem_alu_reg_output),
        .pc_output(mem_pc),

        .reg_write_enable (wb_wen),
        .write_back_mux_select(WB_mux_select),
        .write_back_addr (WB_addr)
    );

    mux u_wb_mux (
        .A (lmd_output),
        .B (mem_alu_reg_output),
        .select (WB_mux_select),
        .out (write_back_data)
    );

endmodule
