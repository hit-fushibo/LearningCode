`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/03 16:57:31
// Design Name: 
// Module Name: hazard_detection_unit
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

module stall_detection_unit(
    input [31:0] if_id_ir,
    input [31:0] id_ex_ir,
    output reg pc_write,
    output reg if_id_write_enable,
    output reg id_ex_reset
    );
    reg [4:0] rs1, rs2, rd;
    
    always @(*) begin   
        pc_write <= 1'b1;
        if_id_write_enable <= 1'b1;
        id_ex_reset <= 1'b1;

        rs1 <= if_id_ir[25:21];
        rs2 <= if_id_ir[20:16];

        if (id_ex_ir[31:26] == `OPERATION) begin
            rd <= id_ex_ir[15:11];
        end
        else if (id_ex_ir[31:26] == `LW) begin
            rd <= id_ex_ir[20:16];
        end

        
        if (id_ex_ir[31:26] == `LW && ((rs1 == rd) || (rs2 == rd)) && (rd != 0)) begin
            if_id_write_enable <= 1'b0;
            pc_write <= 1'b0;
            id_ex_reset <= 1'b0;
        end
        
    end
endmodule
