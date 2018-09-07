/*++
Copyright (c) 2017 Microsoft Corporation

Module Name:

    <name>

Abstract:

    <abstract>

Author:
    Nikolaj Bjorner (nbjorner)
    Lev Nachmanson (levnach)

Revision History:


--*/
#pragma once
#include "util/vector.h"
#include "util/lp/lp_settings.h"
#include "util/rlimit.h"
#include "util/params.h"
#include "nlsat/nlsat_solver.h"
#include "util/lp/lar_solver.h"
#include "util/lp/int_solver.h"
namespace niil {
typedef lp::lemma lemma;
// nonlinear integer incremental linear solver
class solver {
    struct imp;
    imp* m_imp;
public:
    void add_monomial(lp::var_index v, unsigned sz, lp::var_index const* vs);
    solver(lp::lar_solver& s, reslimit& lim, params_ref const& p);
    ~solver();
    void push();
    void pop(unsigned scopes);
    bool need_check();
    lbool check(lp::explanation&, lemma&);
};
}