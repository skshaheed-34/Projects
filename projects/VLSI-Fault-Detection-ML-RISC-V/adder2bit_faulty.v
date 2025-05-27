
module adder2bit_faulty (
    input [1:0] a, b,
    input fault_en,
    output [2:0] sum
);

    wire [2:0] temp_sum;

    assign temp_sum = a + b;

   
    assign sum[0] = temp_sum[0];
    assign sum[1] = fault_en ? 1'b1 : temp_sum[1];  
    assign sum[2] = temp_sum[2];

endmodule
