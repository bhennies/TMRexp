#include "post.hpp"

//#include "../helpers.hpp"
#include "post/helpers.hpp"
#include "post/eval.hpp"
using namespace tmr;

std::vector<Cfg> tmr::post(const Cfg& cfg, const SetReadCritical& stmt, unsigned short tid) {
    CHECK_STMT;
    auto result = mk_next_config_vec(cfg, new Shape(*cfg.shape), tid);
    result.back().inReadCritical[tid] = stmt.setTo();
    // record is only stored for offending thread (Or should this be splitted in two statements?)
    if (cfg.offender[tid]) {
        result.back().readCriticalSelector = stmt.setTo();
    }
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

std::vector<Cfg> tmr::eval_rc_sel(const Cfg &cfg, const ReadCriticalSelCondition &cond, const Statement *nY,
                                  const Statement *nN, unsigned short tid) {
    // checks: readCriticalSelector == true
    std::size_t var = mk_var_index(*cfg.shape, cond.var(), tid);
    std::vector<Cfg> result;
    result.reserve(3);

    Shape* eqsplit = isolate_partial_concretisation(*cfg.shape, var, cfg.shape->index_REC(), EQ_);
    Shape* neqsplit = isolate_partial_concretisation(*cfg.shape, var, cfg.shape->index_REC(), MT_GT_MF_GF_BT);

    if (eqsplit) {
        // check cond
        result.push_back(Cfg(cfg, eqsplit));
        bool cres = cfg.readCriticalSelector;
        result.back().pc[tid] = cres ? nY : nN;
    }

    if (neqsplit) {
        // result unknown
        result.push_back(Cfg(cfg, new Shape(*neqsplit)));
        result.back().pc[tid] = nY;
        result.push_back(Cfg(cfg, neqsplit));
        result.back().pc[tid] = nN;
    }

    return result;
}


