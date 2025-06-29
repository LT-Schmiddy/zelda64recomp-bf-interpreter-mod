#include "recomp_interaction.h"

#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recomp_logging.h"

#include "brainfuck.h"

RECOMP_CALLBACK("*", recomp_on_init) void run_bf () {
    unsigned char bf_data[100];
    for (int i = 0; i < 100; i++) {
        bf_data[i] = 0;
    }

    BrainfuckState *state = brainfuck_state();
	BrainfuckExecutionContext *context = brainfuck_context(bf_data, 100);
	BrainfuckInstruction *instruction = brainfuck_parse_string("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.");
 	brainfuck_add(state, instruction);
 	brainfuck_execute(state->root, context);
	brainfuck_destroy_context(context);
 	brainfuck_destroy_state(state);
}


