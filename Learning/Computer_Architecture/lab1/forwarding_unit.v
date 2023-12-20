`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/03 10:21:29
// Design Name: 
// Module Name: forwarding_unit
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

module dir_unit(
    input [31:0] id_ex_ir,       
    input [31:0] ex_mem_ir,      
    input [31:0] mem_wb_ir,      
    input [31:0] mem_cond,       
    input [31:0] wb_cond,        
    output reg [1:0] forward_A,   
    output reg [1:0] forward_B    
);

reg mem_reg_write, wb_reg_write; 
reg [4:0] rs1, rs2, mem_rd, wb_rd; 

always @(*) begin
    forward_A <= 2'b00; 
    forward_B <= 2'b00; 
    mem_reg_write <= (ex_mem_ir[31:26] == `LW) || 
                     ((ex_mem_ir[31:26] == `OPERATION) && ((ex_mem_ir[10:0] == 11'b00000_001010 && mem_cond != 32'h0) || (ex_mem_ir[10:0] != 11'b00000_001010)));
    wb_reg_write <= (mem_wb_ir[31:26] == `LW) || 
                    ((mem_wb_ir[31:26] == `OPERATION) && ((mem_wb_ir[10:0] == 11'b00000_001010 && wb_cond != 32'h0) || (mem_wb_ir[10:0] != 11'b00000_001010)));

    if ((id_ex_ir[31:26] != `OPERATION) || (mem_reg_write == 1'b0) || (wb_reg_write == 1'b0)) begin
        forward_A <= 2'b00;
        forward_B <= 2'b00;
    end

    rs1 <= id_ex_ir[25:21]; 
    rs2 <= id_ex_ir[20:16];

    if (ex_mem_ir[31:26] == `OPERATION) begin
        mem_rd <= ex_mem_ir[15:11];
    end 
    else if (ex_mem_ir[31:26] == `LW) begin
        mem_rd <= ex_mem_ir[20:16];
    end
    if (mem_wb_ir[31:26] == `OPERATION) begin
        wb_rd <= mem_wb_ir[15:11];
    end 
    else if (mem_wb_ir[31:26] == `LW) begin
        wb_rd <= mem_wb_ir[20:16];
    end



    
    if (mem_reg_write && (mem_rd != 5'h0) && (mem_rd == rs1)) begin
        forward_A <= 2'b01;
    end
    if (mem_reg_write && (mem_rd != 5'h0) && (mem_rd == rs2)) begin
        forward_B <= 2'b01;
    end


    if (wb_reg_write && (wb_rd != 5'h0) && (wb_rd == rs1) && !(mem_reg_write && (mem_rd != 5'h0) && (mem_rd == rs1))) begin
        forward_A <= 2'b10;
    end
    if (wb_reg_write && (wb_rd != 5'h0) && (wb_rd == rs2) && !(mem_reg_write && (mem_rd != 5'h0) && (mem_rd == rs2))) begin
        forward_B <= 2'b10;
    end

end

endmodule

