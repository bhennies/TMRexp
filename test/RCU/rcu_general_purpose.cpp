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
                            //SetRC(false),
                            Kill("cur"),
                            Kill("tmp")
                            );

    auto readBegin = Sqz(AtomicSqz(
                SetRC(true),
                StoreGlobalGPToRec()
    ));

    auto readEnd = Sqz(
            SetRC(false)
            );

    auto retire = Sqz(AtomicSqz(
            AddArg(0),
            // update counter and wait
            mutex_lock(),
            ToggleGlobalGP(),
            Assign(Var("cur"), Var("RCUrecs")),
            Loop(Sqz(
                    IfThenElse(EqCond(Var("cur"), Null()),
                               Sqz(
                               Brk()),
                               Sqz(
                                       Loop(Sqz(
                                               IfThenElse(GracePeriodCond("cur"),
                                                          Sqz(),
                                                          Sqz(
                                                                  Brk()
                                                                  ))
                                               )),
                                       Assign(Var("tmp"), Next("cur")),
                                       Assign(Var("cur"), Var("tmp")),
                                       Kill("tmp")
                                       ))
                 )
            ),
            // update counter and wait
            ToggleGlobalGP(),
            Assign(Var("cur"), Var("RCUrecs")),
            Loop(Sqz(
                         IfThenElse(EqCond(Var("cur"), Null()),
                                    Sqz(
                                            Brk()),
                                    Sqz(
                                            Loop(Sqz(
                                                    IfThenElse(GracePeriodCond("cur"),
                                                               Sqz(),
                                                               Sqz(
                                                                       Brk()
                                                               ))
                                            )),
                                            Assign(Var("tmp"), Next("cur")),
                                            Assign(Var("cur"), Var("tmp")),
                                            Kill("tmp")
                                    ))
                 )
            ),
            Kill("cur"),
            Free(0),
            Clear(0),
            mutex_unlock()
    ));

    auto prog = Prog(
            name,
            {"RCUrecs"},
            {"cur", "tmp"},
            std::move(init),
            std::move(initthread),
            Fun("readBegin", std::move(readBegin), false),
            Fun("readEnd", std::move(readEnd), false),
            Fun("retire", std::move(retire), true)
        );

    return prog;
}

int main(int argc, char *argv[]) {
    // make program and observer
    std::unique_ptr<Program> program = mk_program();
    return run_rcu(*program);
}

