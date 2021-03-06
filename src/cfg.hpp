#pragma once

#include <array>
#include <memory>
#include <assert.h>
#include <iostream>
#include "prog.hpp"
#include "shape.hpp"
#include "observer.hpp"
#include "config.hpp"

#include <set>

namespace tmr {

	enum class DataSet { WITH_DATA, WITHOUT_DATA };
	std::ostream& operator<<(std::ostream& os, const DataSet& val);

	enum class Epoch { ZERO, ONE, TWO };
	std::ostream& operator<<(std::ostream& os, const Epoch& epoch);


	template<typename T, std::size_t N>
	class MultiStore {
		private:
			typedef std::array<T, N> __store__;
			__store__ _vals;

		public:
			MultiStore() {}
			MultiStore(__store__ inout) : _vals(inout) {}
			MultiStore(T fill) { _vals.fill(fill); }
			std::size_t size() const { return _vals.size(); }
			bool operator==(const MultiStore& other) const { return _vals == other._vals; }
			bool operator!=(const MultiStore& other) const { return !(*this == other); }
			typename __store__::reference operator[](typename __store__::size_type index) { assert(index < _vals.size()); return _vals[index]; }
			typename __store__::const_reference operator[](typename __store__::size_type index) const { assert(index < _vals.size()); return _vals[index]; }
			bool operator<(const MultiStore& other) const {
				for (std::size_t i = 0; i < _vals.size(); i++)
					if (_vals[i] < other._vals[i]) return true;
					else if (other._vals[i] < _vals[i]) return false;
				return false;
			}
	};

	typedef MultiStore<const Statement*, 2> MultiPc;
	typedef MultiStore<DataValue, 2> MultiInOut;
	typedef MultiStore<DataSet, 2> MultiSet;
	typedef MultiStore<bool, 2> MultiBool;
	typedef MultiStore<MultiState, 2> MultiMultiState;
	typedef MultiStore<Epoch, 2> MultiEpoch;

	static const DataValue DEFAULT_DATA_VALUE = DataValue::OTHER;
	static const DataSet DEFAULT_DATA_SET = DataSet::WITHOUT_DATA;
	static const Epoch DEFAULT_EPOCH = Epoch::ZERO;


	struct Cfg {
		MultiPc pc;
		MultiState smrstate; // observer state; observed thread is offender
		MultiMultiState threadstate; // observer state; observed thread is self (tid)
		MultiInOut arg; // argument (value) of current function
		MultiBool offender;
		std::unique_ptr<Shape> shape;
        bool globalRCULock;
        bool globalGracePeriodPhase;
        bool gracePeriodPhaseSelector;
        bool readCriticalSelector;
        //MultiBool inReadCritical;
		MultiSet dataset0;
		MultiSet dataset1;
		MultiSet dataset2;
		mutable MultiBool owned; // ownership of first thread-local pointer

		Cfg(std::array<const Statement*, 2> pc, MultiState smrstate, MultiMultiState threadstate, Shape* shape)
		    : pc(pc), smrstate(smrstate), threadstate(threadstate), arg(DEFAULT_DATA_VALUE), offender(false), shape(shape),
		      globalRCULock(false), globalGracePeriodPhase(false), gracePeriodPhaseSelector(false), readCriticalSelector(false),
		      dataset0(DEFAULT_DATA_SET), dataset1(DEFAULT_DATA_SET), dataset2(DEFAULT_DATA_SET), owned(false)
		{}
		Cfg(const Cfg& cfg, Shape* shape)
		    : pc(cfg.pc), smrstate(cfg.smrstate), threadstate(cfg.threadstate), arg(cfg.arg), offender(cfg.offender), shape(shape),
              globalRCULock(cfg.globalRCULock), globalGracePeriodPhase(cfg.globalGracePeriodPhase), gracePeriodPhaseSelector(cfg.gracePeriodPhaseSelector), readCriticalSelector(cfg.readCriticalSelector),
              dataset0(cfg.dataset0), dataset1(cfg.dataset1), dataset2(cfg.dataset2), owned(cfg.owned)
		{}
		Cfg copy() const;
	};

	std::ostream& operator<<(std::ostream& os, const Cfg& cfg);

}
