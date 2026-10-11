# xTests - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Revamp programme](#revamp-programme)
- [Functional improvements](#functional-improvements)
  - [Near-term absorption (R0)](#near-term-absorption-r0)
  - [Correctness (R1)](#correctness-r1)
  - [Reporter (R2)](#reporter-r2)
  - [Failure messages and assertion DX (R3)](#failure-messages-and-assertion-dx-r3)
  - [Runner architecture (R4)](#runner-architecture-r4)
  - [Headers and API shape (R5)](#headers-and-api-shape-r5)
  - [Implementation and dependencies (R6)](#implementation-and-dependencies-r6)
  - [CLI, verbosity, discovery, output (R7)](#cli-verbosity-discovery-output-r7)
  - [Colour and woad (R8)](#colour-and-woad-r8)
  - [Fixtures and context (R9)](#fixtures-and-context-r9)
  - [Self-testing (R10)](#self-testing-r10)
  - [Util / xTras (R11)](#util--xtras-r11)
  - [Documentation (R12)](#documentation-r12)
  - [Flexibility (R14)](#flexibility-r14)
  - [Competitive review (R15)](#competitive-review-r15)
  - [Parallel / external (RX)](#parallel--external-rx)
  - [Completed (retained)](#completed-retained)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)


## Revamp programme

Full catalogue: [**strategy/REVAMP.md**](./strategy/REVAMP.md) (`R*` ids).

Umbrella staged plan: [**`.management/strategy/xTests/REVAMP-PROGRAMME.md`**](../.management/strategy/xTests/REVAMP-PROGRAMME.md).

Standing principle: prefer **STLSoft** (or other SIS libraries) over private
**xTests** implementation chunks when the capability is generally useful.


## Functional improvements


### Near-term absorption (R0)

* [ ] Absorb **StringsN** / slice work and **0.27.0-beta1** prep from `ss/fix-TEST_MS_EQ_N` without regressing `_N` / SLICE contracts (**R0.1**);
* [ ] Absorb `mwsis/null-ptr` pointer NULL / NOT_NULL helpers with dedicated failure wording (**R0.2**);
* [ ] Absorb `mwsis/start-runner-__FILE__` runner-name-from-`__FILE__` (**R0.3**);
* [ ] Re-verify boilerplate / modernisation leftovers against tip (**R0.4**);


### Correctness (R1)

* [ ] Setup failure must fail the run (not green `0/0/0` SUCCESS) (**R1.1**);
* [ ] Reset runner state after teardown failure / setup exception (**R1.2**);
* [ ] Make failure propagation from end-runner safe / hard to misuse (**R1.3**);
* [ ] Stop treating diagnostic messages as `printf` formats (**R1.4**);
* [ ] Fix swapped expected vs unexpected exception counts in summary (**R1.5**);
* [ ] Fix `XTESTS_TEST_INTEGER_EQUAL_ANY_NOT_IN_RANGE` mislabelled message (**R1.6**);
* [ ] Redesign floating-point close / `TEST_FP_EQ` / tolerance contract (**R1.7**);
* [ ] Avoid `exit()` in abend / `--help` paths (**R1.8**);
* [ ] Catch `...` as well as `std::exception` in C++ case invoke (**R1.9**);
* [ ] Replace unique-name-only case map as long-term contract; data-driven API TBD (**R1.10**, **R4.7**);


### Reporter (R2)

* [ ] Remove function-local static default reporter (`s_reporter`) (**R2.1**);
* [ ] Refactor out default reporter into separate implementation file (**R2.2**);
* [ ] Make reporter C-implementable (not C++ ABC only) (**R2.3**);
* [ ] Apply Visitor and have custom outputs (**R2.4**);


### Failure messages and assertion DX (R3)

* [ ] C: integer equal etc should produce message that logs both exp and act, like **BDUT** (**R3.1**);
* [ ] Include expression text in integer (and related) failure messages (**R3.2**);
* [ ] Unify failure wording and narrow vs wide length-limited display (**R3.3**);
* [ ] Use **STLSoft** path-classify C functions for paths in failure output (**R3.4**, **R6.5**);
* [ ] wide-character testing and compiler-specific handling of `"%C"` (**R3.5**);
* [ ] wide-character impl/tests on **Windows** (and maybe elide when on **UNIX**, or at least without full C++20 support) (**R3.5**);
* [ ] allow `TEST_INT_EQ(0, stlsoft::ss_uint32_t(1))` such that the comparison works without needing to specify `u` suffix (**R3.6**);
* [ ] `_Generic` to select type(s) in API macros (**R3.7**);
* [ ] internal printf translates `%zu` transparently for those (older) standard libraries that do not support (**R3.8**);
* [ ] change `uint32_t` type(s)?? (**R3.9**);
* [ ] Fix terse-api dead alias `TEST_MS_EQUAL` / plural drift (**R3.10**);
* [ ] Consider char-type-generic string assertion family (Pantheios per-TU redefine) (**R3.11**);


### Runner architecture (R4)

* [ ] Remove process-global runner state from the core library (**R4.1**);
* [ ] Explicit runner handle (opaque C; thin C++ wrapper; TLS/current binding for macros) (**R4.2**);
* [ ] Support multiple concurrent runners in different threads; document no intra-runner concurrency for stock runners (**R4.3**, **R4.4**);
* [ ] Replace combinatorial `XTESTS_START_RUNNER_WITH_*` with config struct (**R4.5**);
* [ ] refactor internally params { file+line+function } into a structure (**R4.6**);
* [ ] Design data-driven / parametrised cases after handles (no strong preference yet) (**R4.7**);
* [ ] Constructs assisting client libraries for parallel multi-runner runs (**R4.8**);


### Headers and API shape (R5)

* [ ] Segregate **include/xtests/xtests.h** into clearer, extensible headers (keep `#include <xtests/xtests.h>`) (**R5.1**);
* [ ] Normalise naming soup in 1.x with 0.x aliases (**R5.2**, **R5.3**);
* [ ] Install or stop relying on **xtests/internal/**\* from tests (**R5.4**);


### Implementation and dependencies (R6)

* [ ] Move implementation toward C with C-compatible API; C++ façade for UDT/exceptions/shims (**R6.1**);
* [ ] Allow C clients to opt out of STLSoft inclusion in public headers (**R6.2**);
* [ ] Elide custom **src/** string handling in favour of **STLSoft** facilities (**R6.3**);
* [ ] Prefer **STLSoft** C string-slice cmdline parsing over private parsers (**R6.4**);
* [ ] Enhance C logic with modern language facilities where available (**R6.6**);
* [ ] Auto-enable **shwild** / `XTESTS_HAS_SHWILD` when `find_package(shwild)` succeeds (**R6.7**);
* [ ] Avoid `-Werror` on the library target for `add_subdirectory` consumers (**R6.8**);
* [ ] remove most/all static_cast in implementation files;


### CLI, verbosity, discovery, output (R7)

* [ ] support for `"--list"` flag (**R7.1**);
* [ ] support for `"--filter"` / named test case(s) (**R7.2**);
* [ ] grouping and selection features over the registered set (**R7.3**);
* [ ] support for `"--timings"` flag (simple timings only; not benchmarking) (**R7.4**);
* [ ] support for `"--leaks"` flag (**R7.5**);
* [ ] Review and possibly modify what command-line verbosities imply (**R7.6**);
* [ ] verbosity level 6 is to show all cases as they are executed, including successful results (**R7.6**);
* [ ] Programs observe environment variables for verbosity (and related) (**R7.7**);
* [ ] Validate verbosity range; deduplicate `--help` (**R7.6**, **R7.8**);
* [ ] Machine-readable output (JSON, TSV) (**R7.9**);
* [ ] ForceColour / NoColour as overrides of **woad** policy only (**R7.10**);


### Colour and woad (R8)

* [ ] Colour private to default reporter only (**R8.1**);
* [ ] Colour Phase 0: internal façade, stream-gated TTY, fix Windows VT and failure colour paths (**R8.2**);
* [ ] Colour Phase 1: link **woad** PRIVATE; INSTALL + **install-sis-deps**; inherit **woad** env/VT policy (**R8.3**);
* [ ] Later: strip ANSI for `OutputDebugString` dual-sink; colour tests (**R8.4**);


### Fixtures and context (R9)

* [ ] each case should have access to a FILE* variable that is like stderr, but contents only printed when case fails (**R9.2**);
* [ ] execution context (**R9.1**);


### Self-testing (R10)

* [ ] Invert quality ownership: assertion + reporting locked in **xTests** itself (**R10.1**);
* [ ] Automate failure-path proof (failure fails; non-zero exit; correct counts) (**R10.2**);
* [ ] Golden / captured failure-output suites covering assertion families (**R10.3**);
* [ ] Self-test via custom runner(s); interim **BDUT** acceptable until runners separable (**R10.4**, **R10.5**);
* [ ] Clean self-test hygiene (banners, runner names, misplaced case names) (**R10.6**);


### Util / xTras (R11)

* [ ] Package **temp_file** / **temp_directory** as **xTests xTras** (prefer separately installable) (**R11.1**);
* [ ] Aim for independence from **xtests.h** / **stlsoft.h** where feasible (**R11.2**);
* [ ] Install util headers as first-class public surface (**R11.3**);
* [ ] Example hygiene for `temp_*` None artefacts (**R11.4**);


### Documentation (R12)

* [ ] Add **EXAMPLES.md**; significantly extend examples (**R12.1**);
* [ ] Retire apologetic README voice; own the dual C/C++ niche (**R12.2**);
* [ ] Keep **COMPONENTS.md** + terse-api map first-class; FAQ/README links (**R12.3**);
* [ ] NEWS tier-A: interleave notable **STLSoft** floors; do not fan into every consumer (**R12.4**);


### Flexibility (R14)

* [ ] C++ compile-time enforcement that Boolean expressions are genuinely `bool` (**R14.1**);
* [ ] Investigate new/co-working flexibility extension mechanism (SAS-adjacent; cross-link **RX.1**) (**R14.2**);


### Competitive review (R15)

* [ ] Review popular C unit-test libraries; ensure **xTests** provides their good features and more (**R15.1**);


### Parallel / external (RX)

* [ ] Fix multibyte string-equality helpers (`XTESTS_TEST_MULTIBYTE_STRING_EQUAL` / `sas_to_string_m`) so string-access shims (e.g. `c_str_data_a`) declared after **xtests.h** is included are found under GCC/MinGW two-phase lookup; unblocks **Pantheios** **test.unit.bec.COMErrorObject** on MinGW — **separate SIS initiative**, not a revamp gate (**RX.1**);
* [ ] Consume **STLSoft** path-classify C API once fixed/extended (**RX.2** → **R3.4**, **R6.5**);
* [ ] Consume **STLSoft** C cmdline string-slice layer once available (**RX.3** → **R6.4**);


### Completed (retained)

* [x] ~~~summary should list #cases that failed/succeeded~~~ - ✅;
* [x] ~~~coloured console output, for `"SUCCESS"` and `"FAILURE"` reports~~~ - ✅;
* [x] ~~~enhance C-form of macros using `_Generic` - this provided as of version 0.24.0~~~ - ✅;
* [x] ~~~simplified (shorter) macros, via opt-in header(s)~~~ - ✅;
* [x] ~~~ensuring different verbosity levels handled appropriately, in summary and expanded form(s)~~~ - ✅;


## Performance improvements

* \<none>


## Packaging improvements

* [ ] Automated CI matrix for checking combinations of C and C++ language standards (**R13.1**);
* [ ] Align CI `on.push.branches` with freelibs canonical seven (**R13.2**);
* [ ] Document STLSoft ↔ **xTests** bootstrap sequence as product behaviour (**R13.3**);
* [ ] Keep version / **CHANGES** / **NEWS** / **Doxyfile** / header `_ALPHABETA` aligned (**R13.4**);
* [ ] Retire stale CMake aliases (e.g. `xTests::xTests.core`) where practical (**R13.5**);
* [ ] Extend **install-sis-deps** for **woad** when colour Phase 1 lands (**R13.6**);
* [x] ~~~GitHub Actions~~~ - ✅:
  * [x] ~~~Build~~~ - ✅;
  * [x] ~~~Unit-tests~~~ - ✅;
* [x] ~~~**CMake** build setup should be able to infer **STLSoft** if available via a **CMake** find mechanism (e.g. `find_package()`) - this provided as of version 0.20.5~~~ - ✅;


<!-- ########################### end of file ########################### -->
