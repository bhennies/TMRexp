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

    auto fun3 = Sqz(SetNull(Var("RCUrecs")));

	// retire
	auto retire = Sqz(
            AddArg(0),
            Assign(Var("cur"), Var("RCUrecs")),
            Loop(Sqz(
            IfThenElse(EqCond(Var("cur"), Null()), Sqz(
                       Free(0),
                       Clear(0)),
                       Sqz(
                           IfThen(GracePeriodCond("cur"),
                                      Sqz(Brk())
                                      ),
                       Assign(Var("tmp"), Next("cur")),
                       Assign(Var("cur"), Var("tmp")),
                       Kill("tmp")
                       )

            ))));


	std::string name = "TESTimpl";

	auto prog = Prog(
		name,
		{"RCUrecs"},
		{"cur", "tmp"},
		std::move(init),
		std::move(initthread),
		Fun("readBegin", std::move(fun1), false),
		Fun("readEnd", std::move(fun2), false),
		Fun("retire", std::move(retire), true)
        //, Fun("fun3", std::move(fun3), false)
	);

	return prog;
}


int main(int argc, char *argv[]) {
	// make program and observer
	std::unique_ptr<Program> program = mk_program();
	return run_rcu_with_inv(*program);
}
