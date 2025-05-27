`timescale 1ns/1ps

module tb;
    reg [1:0] a, b;
    reg fault_en;
    wire [2:0] sum;

    adder2bit_faulty uut (.a(a), .b(b), .fault_en(fault_en), .sum(sum));

    integer i, j, k;
    integer fout;

    initial begin
        fout = $fopen("output.csv", "w");
        $display("%0d,%0d,%0d,%0d,%s", a, b, fault_en, sum, fault_en ? "stuck_at" : "no_fault");

for (i = 0; i < 4; i = i + 1) begin
    for (j = 0; j < 4; j = j + 1) begin
        for (k = 0; k < 2; k = k + 1) begin
            a = i[1:0];
            b = j[1:0];
            fault_en = k;
            #5;  // Let signals settle
            $display("%0d,%0d,%0d,%0d,%s", a, b, fault_en, sum, fault_en ? "stuck_at" : "no_fault");
        end
    end
end

        $fclose(fout);
        $finish;
    end
endmodule
