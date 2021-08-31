#include "post.hpp"

//#include "../helpers.hpp"
#include "post/helpers.hpp"
#include "post/eval.hpp"
using namespace tmr;

std::vector<Cfg> tmr::post(const Cfg& cfg, const SetReadCritical& stmt, unsigned short tid) {
    CHECK_STMT;
    auto result = mk_next_config_vec(cfg, new Shape(*cfg.shape), tid);
    result.back().inReadCritical[tid] = stmt.setTo();
    return result;
}

std::vector<Cfg> tmr::eval_rc_var(const Cfg& cfg, const ReadCriticalVarCondition& cond, const Statement* nY, const Statement* nN, unsigned short tid) {
    // checks: inReadCriticalSection == true
    std::vector<Cfg> result;
    result.push_back(cfg.copy());
    bool cres = cfg.inReadCritical[tid];
    result.back().pc[tid] = cres ? nY : nN;
    return result;
}


