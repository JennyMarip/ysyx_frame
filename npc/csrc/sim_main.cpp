#include "Vour.h"
#include "verilated.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "verilated_vcd_c.h"
#include <nvboard.h>

int main(int argc, char** argv){
    nvboard_bind_all_pins(&dut);
    nvboard_init();
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vour* top = new Vour{contextp};

    VerilatedVcdC* tfp = new VerilatedVcdC;
    contextp->traceEverOn(true);
    top->trace(tfp, 0);
    tfp->open("wave.vcd");
    int i=10;
    while((i--)>0){
        int a=rand()&1;
        int b=rand()&1;
        top->a=a;
        top->b=b;
        top->eval();
	nvboard_update();
        printf("a=%d,b=%d,f=%d\n",a,b,top->f);
	tfp->dump(contextp->time());
        contextp->timeInc(1);
        assert(top->f==(a^b));
    }
    delete top;
    delete contextp;
    tfp->close();
    nvboard_quit();
    return 0;
}
