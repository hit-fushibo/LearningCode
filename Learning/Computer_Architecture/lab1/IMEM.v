`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/09/01 21:10:39
// Design Name: 
// Module Name: IMEM
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


module IMEM(
    input clk,
    input [31:0] raddr,
    output [31:0] rdata
);

    reg [31:0] data [255:0];
    integer i;

    initial begin 
        // $readmemh("D:/vivado_code/CPU2/lab_1.data/base_inst_data", data);
        // $readmemh("D:/vivado_code/CPU2/lab_1.data/additional_inst_data1", data);
        $readmemh("D:/vivado_code/CPU2/lab_1.data/additional_inst_data2", data);
    end

    assign rdata = data[raddr/4];
    
endmodule

