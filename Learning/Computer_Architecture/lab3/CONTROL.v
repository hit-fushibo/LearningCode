`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/11/11 13:49:15
// Design Name: 
// Module Name: CONTROL
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


module CONTROL(
    input clk,  
    input rst,  
               
    input [31:0] cpu_addr_in,       
    input valid1,                
    input valid2,                
    input [19:0] tag1,           
    input [19:0] tag2,           
    input [31:0] data1,          
    input [31:0] data2,          
    input w_end,                   
    input             arready,         
    input  [3 :0] rid    ,             
    input  [31:0] rdata  ,             
    input         rlast  ,             
    input         rvalid ,             
    output reg    rready,
    output [31:0] cache_rdata,      
    output cache_addr_ok,           
    output cache_data_ok,
    output reg wen,         
    output reg [255:0] wdata,  
    output reg [31:0] waddr,    
    output reg [3 :0] arid   ,         
    output reg [31:0] araddr ,         
    output reg        arvalid             
    );



    // select
    wire is_hitted;     
    wire hit_seq;     
    wire [31:0] mux_data_out;  
    
    // miss_state
    reg [1:0] miss;         //(0-begin,1-miss,2-accepted,3-filled)
    


    // memory_state
    // 0-begin(发地址和请求,置araddr和arvalid);
    // 1-ok，开始接收数据;
    reg state;   



    // accept_data_count
    reg [2:0] accept_data_count;  
    reg [255:0] data_reg;

   //data_send_to_cpu
    reg [31:0] cache_rdata_tosend;



    reg first_beat;



    // cpu
    assign cache_addr_ok = (first_beat == 1) ? 1 : ((miss==3) ? 1 : is_hitted);       // 装载完成时置1，其他时候为is_hitted的值
    assign cache_data_ok = (first_beat == 1) ? 1 : ((miss==3) ? 1 : is_hitted);
    assign cache_rdata = (first_beat == 1) ? 32'b0 : ((miss == 3) ? cache_rdata_tosend : mux_data_out);
    
    
    //hit
    assign is_hitted = (valid1==1 && cpu_addr_in[31:12] == tag1) || (valid2==1 && cpu_addr_in[31:12] == tag2);
    assign hit_seq = (valid2==1 && cpu_addr_in[31:12] == tag2) ? 1 : 0;

    //mux
    assign mux_data_out = hit_seq==0 ? data1 : data2;
    

    always @(posedge clk) begin
        if (rst == 0) begin
            miss <= 0;
            state <= 0;
            arid <= 0;
            accept_data_count <= 0;
            cache_rdata_tosend <= 0;
            data_reg <= 0;
            rready <= 0;
            waddr <= 0;
            wen <= 0;
            wdata <= 0;
            arvalid <= 0;
            first_beat <= 1;
        end
    end
    
    


    always @(posedge clk) begin
        if (first_beat == 1 && rst == 1) begin
            first_beat <= 0;
        end 
        else if (rst == 1 && first_beat ==0) begin
          if (miss == 0) begin
            if (is_hitted == 0) begin
                miss <= 1;
                araddr <= {cpu_addr_in[31:5], 5'b0};  
                arvalid <= 1;                        
            end else begin
                miss <= 0;
            end   
        end 
        else if (miss == 1) begin
            if (state == 0) begin
                
                if (arvalid == 1 && arready == 1) begin
                    state <= 1;
                    arvalid <= 0;
                    rready <= 1;
                    accept_data_count <= 0;
                end 
                
            end 
            else if (state == 1) begin
                if (rvalid == 1 && rlast != 1) begin
                    if (accept_data_count == 0) begin
                        if (accept_data_count == cpu_addr_in[4:2]) begin 
                            cache_rdata_tosend <= rdata;
                        end
                        data_reg[31:0] <= rdata;
                        accept_data_count = accept_data_count + 1;
                    end 
                    else if (accept_data_count == 1) begin
                        if (accept_data_count == cpu_addr_in[4:2]) begin
                            cache_rdata_tosend <= rdata;
                        end
                        data_reg[63:32] <= rdata;
                        accept_data_count = accept_data_count + 1;
                    end 
                    else if (accept_data_count == 2) begin
                        if (accept_data_count == cpu_addr_in[4:2]) begin
                            cache_rdata_tosend <= rdata;
                        end
                        data_reg[95:64] <= rdata;
                        accept_data_count = accept_data_count + 1;
                    end 
                    else if (accept_data_count == 3) begin
                        if (accept_data_count == cpu_addr_in[4:2]) begin
                            cache_rdata_tosend <= rdata;
                        end
                        data_reg[127:96] <= rdata;
                        accept_data_count = accept_data_count + 1;
                    end 
                    else if (accept_data_count == 4) begin
                        if (accept_data_count == cpu_addr_in[4:2]) begin
                            cache_rdata_tosend <= rdata;
                        end
                        data_reg[159:128] <= rdata;
                        accept_data_count = accept_data_count + 1;
                    end 
                    else if (accept_data_count == 5) begin
                        if (accept_data_count == cpu_addr_in[4:2]) begin
                            cache_rdata_tosend <= rdata;
                        end
                        data_reg[191:160] <= rdata;
                        accept_data_count = accept_data_count + 1;
                    end 
                    else if (accept_data_count == 6) begin
                        if (accept_data_count == cpu_addr_in[4:2]) begin
                            cache_rdata_tosend <= rdata;
                        end
                        data_reg[223:192] <= rdata;
                        accept_data_count = accept_data_count + 1;
                    end
                end 
                else if (rvalid == 1 && rlast == 1) begin
                    if (accept_data_count == cpu_addr_in[4:2]) begin
                            cache_rdata_tosend <= rdata;
                    end
                    data_reg[255:224] <= rdata;
                    state <= 0;         
                    miss <= 2;          
                    accept_data_count <= 0;  
                end               
            end
        
        end 
        else if (miss == 2) begin
            if (wen == 0) begin
                wen <= 1;         
                waddr <= cpu_addr_in;  
                wdata <= data_reg;  
            end

            if (w_end == 1) begin
                miss <= 3;                                 
                wen <= 0;
                rready <= 0;
            end

        end 
        else if (miss == 3) begin
            miss <= 0;      // miss归零
        end
        end
    end


    
endmodule
