`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/11 13:49:15
// Design Name: 
// Module Name: cache_ram
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


module cache_ram(
    input clk,  
    input rst,  
    input cpu_req,  
    input store_in_en,  
    input [31:0] cpu_addr,  

    output reg valid1_out,      
    output reg valid2_out,      
    output reg [19:0] tag1_out, 
    output reg [19:0] tag2_out, 
    output [31:0] data1_out,    
    output [31:0] data2_out,    
    output reg [31:0] cpu_addr_out,  


    input wen,     
    input [31:0] write_addr_in,   
    input [255:0] write_data_in,   
    output reg wend
    );
    
    reg[19:0] tags1[127:0];
    reg[127:0] valid1;
    reg wen1;
    reg[19:0] tags2[127:0]; 
    reg[127:0] valid2;  
    reg wen2;

           

    reg [3:0] write_count;  
    reg [2:0] write_addr_suffix;        

    reg [31:0] write_addr;
    reg [255:0] write_data_all;       
    reg [31:0] write_data;              

    data_ram u_data_ram_1(
        .addrb(cpu_addr[11:2]),
        .clkb(clk),
        .doutb(data1_out),
        .enb(1'b1),
        .addra({write_addr[11:5], write_addr_suffix}),
        .dina(write_data),
        .clka(clk),
        .wea(wen1)
    );

    data_ram u_data_ram_2(
        .addrb(cpu_addr[11:2]),
        .clkb(clk),
        .doutb(data2_out),
        .enb(1'b1),
        .addra({write_addr[11:5], write_addr_suffix}),
        .dina(write_data),
        .clka(clk),
        .wea(wen2)
    );



    reg[127:0] lru;
    always @(posedge clk) begin
        if (store_in_en == 1 && rst == 1) begin
        
            valid1_out <= valid1[cpu_addr[11:5]];
            valid2_out <= valid2[cpu_addr[11:5]];

            
            tag1_out <= tags1[cpu_addr[11:5]];
            tag2_out <= tags2[cpu_addr[11:5]];

            
            cpu_addr_out <= cpu_addr;
        end
    end
    always @(posedge clk) begin
        if (wen == 1 && write_count == 0) begin    
            write_addr <= write_addr_in;
            write_addr_suffix <= 3'h0;
            write_data_all <= write_data_in;
            write_data <= write_data_in[31:0];
            write_count <= write_count + 1;
            wen1 <= ~lru[write_addr_in[11:5]];
            wen2 <= lru[write_addr_in[11:5]];
        end else if (write_count == 1) begin
            write_count <= write_count + 1;
            write_addr_suffix <= 3'h1;
            write_data <= write_data_all[63:32];
        end else if (write_count == 2) begin
            write_count <= write_count + 1;
            write_addr_suffix <= 3'h2;
            write_data <= write_data_all[95:64];
        end else if (write_count == 3) begin
            write_count <= write_count + 1;
            write_addr_suffix <= 3'h3;
            write_data <= write_data_all[127:96];
        end else if (write_count == 4) begin
            write_count <= write_count + 1;
            write_addr_suffix <= 3'h4;
            write_data <= write_data_all[159:128];
        end else if (write_count == 5) begin
            write_count <= write_count + 1;
            write_addr_suffix <= 3'h5;
            write_data <= write_data_all[191:160];
        end else if (write_count == 6) begin
            write_count <= write_count + 1;
            write_addr_suffix <= 3'h6;
            write_data <= write_data_all[223:192];
        end else if (write_count == 7) begin
            write_count <= write_count + 1;
            write_addr_suffix <= 3'h7;
            write_data <= write_data_all[255:224];
        end else if (write_count == 8) begin  
            wend <= 1;
            write_count = write_count + 1;
            lru[write_addr[11:5]] <= ~lru[write_addr[11:5]];
        
            if (lru[write_addr[11:5]]==0) begin
                tags1[write_addr[11:5]] <= write_addr[31:12];
                valid1[write_addr[11:5]] <= 1;
            end else begin
                tags2[write_addr[11:5]] <= write_addr[31:12];
                valid2[write_addr[11:5]] <= 1;
            end
        end else if (write_count == 9) begin
            wen1 <= 0;  
            wen2 <= 0;  
            write_count <= 0;          
        end

        if (write_count == 9 && wend==1) begin
            wend <= 0;
        end
    end
    

    always @(posedge clk) begin
        if (rst==0) begin
            valid1 <= 128'b0;
            valid2 <= 128'b0;
            lru   <= 128'b0;
            wend <= 0;
            write_count <= 0;
            write_data_all <= 0;
            write_data <= 0;
            write_addr_suffix <= 0;
        end
    end
endmodule
