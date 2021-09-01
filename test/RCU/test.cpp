#include "run.hpp"

using namespace tmr;


static std::unique_ptr<Program> mk_program() {
	// init prog
	auto init = Sqz(
            SetNull(Var("RCUrecs"))
	);

	// init thread
	auto initthread = Sqz(
            Mllc("cur"),
            Loop(Sqz(
                    Assign(Var("tmp"), Var("RCUrecs")),
                    Assign(Next("cur"), Var("tmp")),
                    IfThen(
                            CasCond(CAS(Var("RCUrecs"), Var("tmp"), Var("cur"))),
                            Sqz(Brk())
                    ),
                    Kill("tmp")
            )),
            InitRec("cur"),
            SetRC(false),
            Kill("cur"),
            Kill("tmp")
	);

	// enterQ
	auto fun1 = Sqz(SetRC(true)


	);

	// leaveQ
	auto fun2 = Sqz(SetRC(false)
	);

	// retire
	auto retire = Sqz(
            AddArg(0),
            Assign(Var("cur"), Var("RCUrecs")),
            IfThenElse(RCCond("cur"),
                       Sqz(),
                       Sqz(Free(0),
                       Clear(0)))


	);


	std::string name = "TESTimpl";

	auto prog = Prog(
		name,
		{"RCUrecs"},
		{"cur", "tmp"},
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
