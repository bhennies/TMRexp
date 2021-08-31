#include "run.hpp"

using namespace tmr;


static std::unique_ptr<Program> mk_program() {
	// init prog
	auto init = Sqz(
	);

	// init thread
	auto initthread = Sqz(
	);

	// enterQ
	auto fun1 = Sqz(
            Free(0),
            Clear(0)
	);

	// leaveQ
	auto fun2 = Sqz(
            SetRC(true)
	);

	// retire
	auto retire = Sqz(
            AddArg(0)
	);


	std::string name = "TESTimpl";

	auto prog = Prog(
		name,
		{},
		{},
		std::move(init),
		std::move(initthread),
		Fun("fun1", std::move(fun1), false),
		Fun("fun2", std::move(fun2), false),
		Fun("retire", std::move(retire), true)
	);

	return prog;
}


int main(int argc, char *argv[]) {
	// make program and observer
	std::unique_ptr<Program> program = mk_program();
	return run_test(*program);
}
