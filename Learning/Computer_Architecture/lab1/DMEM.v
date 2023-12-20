`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/01 21:10:50
// Design Name: 
// Module Name: DMEM
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


module DMEM(
    input clk,
    input [31:0] raddr,
    input [31:0] waddr,
    input write_enable,
    input [31:0] wdata,
    output [31:0] rdata
    );

    reg [31:0] dmem_reg_files [255:0];
    integer i;

    initial begin 
        // $readmemh("D:/vivado_code/CPU2/lab_1.data/base_data_data", dmem_reg_files);
        // $readmemh("D:/vivado_code/CPU2/lab_1.data/additional_data_data1", dmem_reg_files);
        $readmemh("D:/vivado_code/CPU2/lab_1.data/additional_data_data2", dmem_reg_files);
    end

    always @(posedge clk) begin
        if (write_enable) begin
            dmem_reg_files[waddr/4] <= wdata;
        end
    end

    assign rdata = dmem_reg_files[raddr/4];
    
endmodule
