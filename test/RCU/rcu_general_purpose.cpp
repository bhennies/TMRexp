//
// Created by benjamin on 17.08.21.
//

#include "run.hpp"

using namespace tmr;

static std::unique_ptr<Program> mk_program() {

    std::string name = "RCUimpl_general";

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
                            GetEpoch(),
                            SetEpoch(),
                            Kill("cur"),
                            Kill("tmp")
                            );

    auto readBegin = Sqz(AtomicSqz(
            Assign(Next("readSet"), Var("__rec__")),
            Assign(Var("readSet"), Var("__rec__") )
            ));

    auto readEnd = Sqz();

    auto writeBegin = Sqz();

    auto writeEnd = Sqz();

    auto retire = Sqz(
            AddArg(2),
            Free(2)
            );

    auto prog = Prog(
            name,
            {"RCUrecs", "lock"},
            {"cur"},
            std::move(init),
            std::move(initthread),
            Fun("readBegin", std::move(readBegin), false),
            Fun("readEnd", std::move(readEnd), false),
            Fun("writeBegin", std::move(writeBegin), false),
            Fun("writeEnd", std::move(writeEnd), false),
            Fun("retire", std::move(retire), true)
        );

    return prog;
}

int main(int argc, char *argv[]) {
    // make program and observer
    std::unique_ptr<Program> program = mk_program();
    return run_rcu(*program);
}

