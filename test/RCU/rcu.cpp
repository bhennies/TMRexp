//
// Created by benjamin on 17.08.21.
//

#include "run.hpp"

using namespace tmr;

static std::unique_ptr<Program> mk_program() {

int main(int argc, char *argv[]) {
    // make program and observer
    std::unique_ptr<Program> program = mk_program();
    return run_ebr_with_inv(*program);
}

