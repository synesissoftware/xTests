# xTests - Revamp Catalogue <!-- omit in toc -->

Updated: 11th October 2026

Status: planning baseline (operator-approved decisions recorded)

This document is the **full in-scope catalogue** for the **xTests** path to a
**1.x** line. Headline staging and programme tracking live in the freelibs
umbrella: [**`.management/strategy/xTests/`**](../../.management/strategy/xTests/).
Short checklist items live in [**TODO.md**](../TODO.md) and point here by item
id.


## Table of Contents <!-- omit in toc -->

- [Purpose](#purpose)
- [Sources absorbed](#sources-absorbed)
- [Product identity](#product-identity)
- [Standing principles](#standing-principles)
- [Decision log](#decision-log)
- [Compatibility policy](#compatibility-policy)
- [Explicit non-goals](#explicit-non-goals)
- [Item catalogue](#item-catalogue)
  - [R0 — Near-term absorption](#r0--near-term-absorption)
  - [R1 — Correctness defects](#r1--correctness-defects)
  - [R2 — Default reporter and streams](#r2--default-reporter-and-streams)
  - [R3 — Failure messages and assertion DX](#r3--failure-messages-and-assertion-dx)
  - [R4 — Runner architecture](#r4--runner-architecture)
  - [R5 — Header and API shape](#r5--header-and-api-shape)
  - [R6 — Implementation language and dependencies](#r6--implementation-language-and-dependencies)
  - [R7 — CLI, verbosity, discovery, and output](#r7--cli-verbosity-discovery-and-output)
  - [R8 — Colour and woad](#r8--colour-and-woad)
  - [R9 — Fixtures and execution context](#r9--fixtures-and-execution-context)
  - [R10 — Self-testing](#r10--self-testing)
  - [R11 — Util / xTras](#r11--util--xtras)
  - [R12 — Documentation and attractiveness](#r12--documentation-and-attractiveness)
  - [R13 — Packaging, CI, and hygiene](#r13--packaging-ci-and-hygiene)
  - [R14 — Flexibility and type enforcement](#r14--flexibility-and-type-enforcement)
  - [R15 — Competitive feature review](#r15--competitive-feature-review)
  - [RX — Parallel / external initiatives](#rx--parallel--external-initiatives)
- [Branch absorption](#branch-absorption)
- [Blast radius](#blast-radius)
- [How to use this document](#how-to-use-this-document)


## Purpose

Record **every** in-scope revamp item with enough detail that implementation
agents need not re-derive intent from chat history. This file is the product
catalogue; the umbrella programme document owns sequencing, effort/impact, and
progress status.


## Sources absorbed

| Source | Kind |
| --- | --- |
| Operator aims (session 11 Oct 2026) | Wishlist / constraints |
| Review 1 — “XTESTS REVAMP: REVIEW FOR COMPARING NOTES” | Bona fide code review |
| Review 2 — “xTests wholesale-revamp review” | Bona fide design review |
| Review 3 — “XTESTS REVAMP PLAN — ADDENDUM” | Prior-review synthesis |
| Review 4 — transcript-derived modernisation summary | Multi-chat distillate |
| Review 5 — machine transfer brief (StringsN / 0.27) | Active branch + boilerplate |
| Operator decision answers (incl. verbosity, path-classify, STLSoft preference) | Locked decisions |
| Existing [**TODO.md**](../TODO.md) / [**KNOWN_ISSUES.md**](../KNOWN_ISSUES.md) | Pre-existing backlog |


## Product identity

**xTests** owns the niche: a portable **dual C and C++** test harness with
**explicit** registration, typed **expected-then-actual** assertions, and
Synesis-grade portability.

It is not Catch2. It is not BDUT. Positioning relative to those tiers:

| Tier | Role |
| --- | --- |
| **BDUT** | Bundle-friendly, header-only, minimal deps; may temporarily unit-test **xTests** |
| **xTests** | Full runner for Synesis libraries; C + C++; explicit registration |
| **Catch2** | FAQ advice for greenfield C++-only work; not a substitute for improving **xTests** |

Retire apologetic README voice. FAQ Catch2 advice remains guidance, not a stall.


## Standing principles

1. **Prefer STLSoft over internal chunks.** New implementation capability
   belongs in **STLSoft** (or another appropriate SIS library) when it is
   generally useful; **xTests** consumes it rather than growing private
   copies. Record this principle in **xTests** strategy docs and in umbrella
   freelibs / C/C++ programme notes where relevant.
2. **src/ may embrace STLSoft.** Implementation TUs may use STLSoft freely,
   including string facilities that supersede custom **xTests** `src/` string
   handling.
3. **C clients may opt out of STLSoft in public headers.** Pure-C consumers
   must be able to use the C API without including STLSoft headers.
4. **C++ clients accept STLSoft** in public headers where the C++ API needs it.
5. **No process-global mutable state in the core library** (see **R4**).
6. **Explicit registration remains the identity.** No Schwarz counters, no
   static-constructor auto-registration.
7. **Colour is private to the default reporter** — never public API, never
   forced on custom reporters.


## Decision log

| Id | Topic | Decision |
| --- | --- | --- |
| D1 | 1.x vs 0.x API | **1.x preserves backwards compatibility with 0.x.** Breaks only for a VERY-GOOD-REASON; the SIS consumer corpus (~750 TUs / ~18 trees) is the guide to acceptable change. |
| D2 | STLSoft coupling | Embrace STLSoft in **src/**; C header opt-out; C++ clients accept STLSoft inclusion. |
| D3 | Self-test / BDUT | Prefer **xTests** testing itself via custom runner(s). **BDUT** is acceptable short-term until runners are elegantly separable. |
| D4 | Machine-readable / timings | JSON and TSV (and similar) **in scope**. Simple timings **in scope**. Sophisticated benchmarking **out of scope for 1.x**. `--list` and `--filter` **required**. |
| D5 | SAS / two-phase lookup | **Parallel track** — separate SIS initiative; not a gate for the revamp programme. |
| D6 | util / temp_* | Direction: **“xTests xTras”** — preferably separately installable; ideally not dependent on **xtests.h** / **stlsoft.h** if feasible. |
| D7 | Parametrised / data-driven cases | **No strong preference yet.** Unique-name-only `std::map` is not the long-term contract. Exact API TBD after runner-handle design; catalogue item **R4.7**. |
| D8 | Concurrency | **1.x:** multiple concurrent runners in **different threads** are supported; **stock runners do not** support concurrent use **within** the same runner. Intra-runner threading is a possible **2.x** topic. |
| D9 | Verbosity | Detailed review (and possible modification) of what command-line verbosities imply; programs also observe **environment variables**. |
| D10 | Path classification | Use **STLSoft** path-classify C functions (once fixed/extended). |
| D11 | C command-line parsing | If the implementation moves to C, prefer a **STLSoft** C string-slice flag/option/value layer over a private parser in **xTests**. |


## Compatibility policy

Preserve the consumer call-shape via macros and a compatibility layer:

```text
PARSE_VERBOSITY → START_RUNNER → RUN_CASE* → PRINT_RESULTS → END_RUNNER_UPDATE_EXITCODE
```

Stable / high-traffic surfaces (non-exhaustive): `TEST_INT_EQ`,
`XTESTS_RUN_CASE`, `XTESTS_START_RUNNER*`, `XTESTS_END_RUNNER_UPDATE_EXITCODE`,
`XTESTS_TEST_*`, terse-api aliases.

New handle-based C APIs may be introduced; 0.x macros expand to them so
STLSoft / Pantheios / b64 / etc. migrate mechanically or not at all.


## Explicit non-goals

* Auto-registration / static constructors / Schwarz counters;
* Full Catch2-style section nesting / BDD;
* Dropping C support;
* Big-bang rewrite of all consumer suites without a dual-API window;
* Making **woad** optional via a permanent dual local/woad colour implementation;
* Colour (or **woad**) on the public header surface or on every custom reporter;
* Sophisticated benchmarking in 1.x;
* Intra-runner multi-threaded assertion (1.x; see D8);
* Treating the SAS / MinGW two-phase string-access-shim problem as a revamp gate
  (see **RX.1**).


## Item catalogue

Each item has an id (`R…`). Effort / impact in the umbrella plan use gears
(⚙️–⚙️⚙️⚙️) and diamonds (🔹 / 🔶 / 💎).


### R0 — Near-term absorption


#### R0.1 — StringsN / slice work (`fix-TEST_MS_EQ_N`)

* Absorb / complete the **0.27.0-beta1** line from `remotes/ss/fix-TEST_MS_EQ_N`
  (and any uncommitted release-prep on that line).
* **Contracts (do not regress):**
  * Family A — `_N` macros: `n > 0` exact length; `n < 0` maximum limit;
    `n == 0` vacuous equality; lengths bounded to `|n|` (safe non-NUL buffers);
    wide C API uses `ptrdiff_t n`.
  * Family B — SLICE macros: exact length via expectedLen vs actual.len;
    NOT_EQUAL / APPROX variants for MB + WS.
* Examples: `example.c.string_comparisons_n`, `example.cpp.string_comparisons_n`.
* Optional follow-ons (not blocking 0.27): NULL/`nullptr` `_N` edges;
  historical empty-slice stub.


#### R0.2 — Null-pointer helpers (`mwsis/null-ptr`)

* Absorb `remotes/mwsis/null-ptr`:
  `XTESTS_TEST_POINTER_NULL` / `NOT_NULL` (and terse twins) with dedicated
  failure wording (not forever thin wrappers of EQUAL to NULL).
* Document in **COMPONENTS.md**.


#### R0.3 — Runner name from `__FILE__` (`mwsis/start-runner-__FILE__`)

* Absorb `remotes/mwsis/start-runner-__FILE__`: infer test / runner name fully
  from `__FILE__` in a runner-start macro.
* Ensure interaction with handle-based runner and `--list` / `--filter` is
  defined when those land.


#### R0.4 — Boilerplate / modernisation leftovers

* Re-verify against tip (much of the Aug 2026 handoff is already on master via
  0.26.x):
  * CI push branches exactly the freelibs seven
    (`master`, `dev`, `boilerplate`, `idiomatic`, `rc1`, `rc2`, `rc3`);
  * `run_all_unit_tests.cmd` exit-code parity with `.sh`;
  * presence/quality of `run_all_component_tests` / automated runners after
    0.26.6 gold helpers;
  * `prepare_cmake.sh` `-m` vs corpus `-M` (ask before breaking);
  * example hygiene for `temp_directory` None artefacts;
  * **KNOWN_ISSUES** scaffolding; Doxygen `--verbose`; etc.


### R1 — Correctness defects

Fix early; largely independent of redesign. Where known, cites review-1 loci.


#### R1.1 — Setup failure yields green SUCCESS

* Setup non-zero → case erased → summary `0 / 0 / 0` / SUCCESS.
* Confirmed via `test.scratch.setup.fail` (review 1).
* Impact: 💎. Must fail the run.


#### R1.2 — Stuck runner after teardown failure / setup exception

* Paths return before resetting current case; next `BeginCase` throws
  “already in progress”.
* Impact: 🔶.


#### R1.3 — `XTESTS_END_RUNNER()` discards failure

* Only `_UPDATE_EXITCODE` propagates; `test.scratch.fail_all.1` can exit 0.
* Compatibility: changing bare `END_RUNNER` behaviour needs VERY-GOOD-REASON
  care (D1); at minimum document and provide safe defaults for new APIs;
  consider making discard impossible to misuse.


#### R1.4 — Messages treated as printf formats

* `fprintf(stm, message, "")` → UB if message contains `%`.
* Fix: pass message as data (`%s`), never as format.


#### R1.5 — Summary swaps expected vs unexpected exception counts

* Latent (unused results slot); still fix.


#### R1.6 — Mislabelled `…_ANY_NOT_IN_RANGE` message

* Reports itself as `…_ANY_IN_RANGE`.


#### R1.7 — Floating-point comparison contract

* Ratio-style close; weak at `expected == 0`; `TEST_FP_EQ` silently
  approximate; tolerance is a mutable global.
* Redesign contract; document; avoid surprising globals on the public path.


#### R1.8 — Library calls `exit()` in abend and `--help`

* Skips teardown / destructors. Prefer return codes / runner shutdown.


#### R1.9 — Case invoke catches `std::exception` but not `...`

* Close the exception gap for C++ case invocation.


#### R1.10 — Case-name uniqueness via `std::map`

* Blocks same function over several datasets (see **R4.7** / D7).
* Short-term: document uniquify requirement; long-term: replace model.


### R2 — Default reporter and streams


#### R2.1 — Remove function-local static default reporter

* `s_reporter` in `get_reporter_()` permanently binds first `FILE*` / tty flags
  and breaks subsequent `XTESTS_START_RUNNER_WITH_STREAM` (e.g. capture then
  stdout).
* Prerequisite for honest message-capture tests and multi-stream use.


#### R2.2 — Extract default reporter into its own TU

* Already on **TODO.md**; prerequisite for colour / **woad** work (**R8**).
* Nested anonymous class in `xtests.core.cpp` becomes a named implementation.


#### R2.3 — C-implementable reporter

* Today `xTests_Reporter_t` is a C++ abstract class with pure virtuals.
* 1.x: C vtable / function-pointer struct so C callers can implement reporters.


#### R2.4 — Visitor / custom outputs

* Pre-existing TODO: apply Visitor-style custom outputs; align with **R2.3**.


### R3 — Failure messages and assertion DX


#### R3.1 — C expected+actual parity (BDUT-like)

* Integer (and related) equals must log both expected and actual in C.


#### R3.2 — Expression text in failures

* Integer macros currently pass empty `expr`; failures omit `f(x)` text.
* Improve without breaking message stability relied on by golden tests once
  those exist.


#### R3.3 — Wording and narrow/wide consistency

* Inconsistent phrases (“should be not equal to”); character formatting
  drift; narrow vs wide length-limited failures disagree on truncated display.


#### R3.4 — Paths in failure output

* Prefer relative / classified paths via **STLSoft** path-classify C APIs
  (**D10**), once those APIs are fixed/extended — not ad-hoc string hacks.


#### R3.5 — Wide / `%C` / Windows parity

* Multibyte coverage ≫ wide today; plan parity including Windows and
  compiler-specific `"%C"`.


#### R3.6 — Soften integral literal vs `ss_uint32_t` comparisons

* Allow `TEST_INT_EQ(0, stlsoft::ss_uint32_t(1))` without forced `u` suffix.


#### R3.7 — Broader `_Generic` selection

* Expand C `_Generic` use in API macros where it improves type selection
  (building on 0.24.0).


#### R3.8 — Internal `%zu` translation

* Transparent translation for older standard libraries lacking `%zu`.


#### R3.9 — `uint32_t` / fixed-width type policy

* Pre-existing TODO (“change `uint32_t` type(s)??”); resolve with STLSoft /
  portability policy rather than a silent drive-by.


#### R3.10 — Terse-api dead alias

* `TEST_MS_EQUAL` → undefined plural macro drift; fix in header layout so
  dead aliases are hard to reintroduce.


#### R3.11 — Pantheios char-type-generic string assertion gap

* Pantheios re-defines `XTESTS_TEST_STRING_EQUAL` per TU as wide or narrow;
  consider a first-class char-type-generic assertion family.


### R4 — Runner architecture


#### R4.1 — No core global runner state

* Remove process-global `s_runner` (and equivalent).
* Core library must not rely on process-global mutable state (**standing
  principle 5**).


#### R4.2 — Explicit runner handle

* Opaque C handle; optional thin C++ wrapper.
* TLS or equivalent **current-runner** binding so macros stay ergonomic
  without globals in the library sense of shared process singleton.


#### R4.3 — Multiple concurrent runners (inter-runner)

* **D8:** supported across different threads (one stock runner instance per
  thread of use, or otherwise non-overlapping use of each instance).
* Provide constructs that assist **client libraries** to run parallel suites
  (multiple runners / processes), without requiring intra-runner locking.


#### R4.4 — Intra-runner concurrency out of scope for 1.x

* Stock runners do **not** support concurrent use **within** the same runner.
* Document clearly; possible **2.x** topic.


#### R4.5 — Config struct replaces combinatorial start macros

* Replace `XTESTS_START_RUNNER_WITH_*` explosion with a config struct
  (C-compatible); keep macro wrappers for 0.x compatibility (D1).


#### R4.6 — Source-location struct

* Refactor `{file, line, function}` into a structure (TODO seam).


#### R4.7 — Data-driven / parametrised cases (API TBD)

* **D7:** no strong preference yet.
* Requirement: running one function over several datasets must be first-class
  eventually; unique bare names must not be the only model.
* Design after **R4.2**; interact with `--list` / `--filter` (base name vs
  instance).


#### R4.8 — Parallel-run assists for client libraries

* Documented patterns and/or small helpers so libraries can orchestrate
  multi-runner or multi-process parallel test runs safely.


### R5 — Header and API shape


#### R5.1 — Segregate `include/xtests/xtests.h`

* Split the giant header into a clearer, more discoverable, extensible layout
  (public macros, C API, C++ templates, shims, internal seams).
* Preserve include compatibility: `#include <xtests/xtests.h>` remains valid.


#### R5.2 — Naming normalisation

* Normalise `xTests` / `xtests` / `XTESTS_` / `xTests_*` soup in 1.x with
  **aliases for 0.x** (D1).


#### R5.3 — Dual spellings

* e.g. `XTESTS_COMMANDLINE_PARSEVERBOSITY` vs `…_PARSE_VERBOSITY`;
  `xTests_*` vs `xtests_*` — pick canonical forms; alias the rest.


#### R5.4 — Install vs internal headers

* `xtests/internal/*` (`checked_main`, `safestr`, `implicit_link`) used by
  tests but not installed — install or stop relying from public/test patterns.


### R6 — Implementation language and dependencies


#### R6.1 — Move implementation toward C

* C-compatible API and progressive C implementation of the core runner /
  assertions path; C++ layered for UDT / exceptions / shims.


#### R6.2 — C client STLSoft opt-out

* Public C headers usable without STLSoft inclusion (**D2**).


#### R6.3 — Prefer STLSoft string facilities in src/

* Elide/remove custom **xTests** `src/` string handling in favour of STLSoft
  improvements of the last ~20 years (**standing principle 1–2**).


#### R6.4 — STLSoft C command-line parsing layer

* **D11:** if C core needs argv parsing, prefer STLSoft C string-slice
  flag/option/value APIs (existing or new) over private **xTests** parsers.


#### R6.5 — Use STLSoft path-classify C functions

* **D10:** for path display, filtering, and related logic once APIs are ready.


#### R6.6 — Enhance C logic with modern language facilities

* Where available (C11 `_Generic`, later standards as CI matrix allows),
  increase flexibility and expressiveness without abandoning older compilers
  in the supported matrix.


#### R6.7 — shwild auto-enable

* Auto-enable `XTESTS_HAS_SHWILD` / MATCHES when `find_package(shwild)`
  succeeds; keep shwild optional.


#### R6.8 — Avoid `-Werror` on exported library target

* Do not force `-Werror` on consumers who `add_subdirectory` **xTests**;
  gate pedantic warnings appropriately.


### R7 — CLI, verbosity, discovery, and output


#### R7.1 — `--list`

* List registered cases (and groups when grouping exists).


#### R7.2 — `--filter` / named case selection

* Select over the **registered** set; registration stays explicit.


#### R7.3 — Grouping and selection features

* Broader grouping/selection beyond bare name filter (design with **R4.7**).


#### R7.4 — Simple `--timings`

* Per-case or per-suite simple timings; not a benchmark harness (D4).


#### R7.5 — `--leaks` (as feasible)

* Pre-existing TODO; scope to what is portable and honest.


#### R7.6 — Verbosity semantics review

* **D9:** detailed review and possible modification of what each verbosity
  level implies (today levels 4–7 behave identically; level 6 “show passes”
  unimplemented).
* Document the contract; implement; validate range (not assert-only).


#### R7.7 — Environment variables for verbosity (and related)

* Programs observe environment variables themselves (not only argv), aligned
  with the verbosity review — exact names TBD (avoid inventing a parallel
  colour env; colour follows **woad**, **R8**).


#### R7.8 — Deduplicate `--help`

* Help text currently copy-pasted in multiple functions.


#### R7.9 — Machine-readable output

* **D4:** JSON and TSV (at minimum) as selectable reporter / output modes.
* Optional further formats (TAP / JUnit) may be added if cheap after JSON/TSV;
  not required to block 1.x if JSON/TSV ship.


#### R7.10 — ForceColour / NoColour runner flags

* Overrides of **woad** policy only; do not invent a parallel colour env var
  in **xTests**.


### R8 — Colour and woad


#### R8.1 — Colour private to default reporter

* Never public API; never forced on custom reporters / reporter vtable.


#### R8.2 — Phase 0 (before woad dependency)

* Extract default reporter TU (**R2.2**);
* Introduce internal colour façade (stream + enabled + role sequences)
  matching **woad** currencies; collapse emission to pre/post `%s`;
* Gate colour on the **reporter stream**, not `isatty(stdout)`;
* Fix Windows VT enablement (today wrongly uses `STD_INPUT_HANDLE`; must be
  stdout/stderr, with a “do not mutate console” escape like **woad**);
* Fix `onTestFailed_` TTY path (prints braces, not SGR);
* Unify `colorise_` / partial-string / wide-character failure colour paths;
* Keep bold+colour role sequences as **xTests** literals; pass through
  `woad_seq_for` later (do not drop bold by mapping to stock colour macros
  unless a deliberate visual change);
* Drop unused `XTESTS_ANSI_FG_*/BG_*` number macros; talk in sequences.


#### R8.3 — Phase 1 (link woad PRIVATE)

* `find_package(woad)` + `target_link_libraries(… PRIVATE …)`;
* **Never** PUBLIC/INTERFACE on exported `xTests::core`;
* Document final-link need in **INSTALL.md**;
* Add **woad** to **install-sis-deps** for CI;
* Inherit **woad** `NO_COLOR` / `CLICOLOR` / `TERM=dumb` / VT policy;
* Do not vendor-copy `woad.h`;
* Do not keep a long-lived `#ifdef` local-gating fallback that will diverge.


#### R8.4 — Later colour work

* Strip ANSI for `OutputDebugString` dual-sink;
* Colour tests (component or injected unit).


#### R8.5 — Do not block colour on the full C rewrite

* Colour work may proceed once reporter extraction exists.


### R9 — Fixtures and execution context


#### R9.1 — Execution context object

* Richer than runner-level setup/teardown function pointers only.
* Per-case / per-fixture context; not a full xUnit class hierarchy.


#### R9.2 — Fail-only case `FILE*` buffer

* Per-case stream like stderr; contents printed only when the case fails.


### R10 — Self-testing


#### R10.1 — Invert quality ownership

* Assertion and reporting behaviour locked in **xTests** itself, not only via
  consumer suites.


#### R10.2 — Automated failure-path proof

* A failing assertion yields non-zero exit, correct counts; setup failure
  fails the run; etc.
* Today mostly human-eyeball scratch programs.


#### R10.3 — Golden / captured failure-output suites

* Cover assertion families; stabilise after message work (**R3**).


#### R10.4 — Custom runners for self-test

* **D3:** prefer self-hosting via custom runner(s) once handles exist.


#### R10.5 — Short-term BDUT

* Acceptable to bundle/apply **BDUT** to unit-test **xTests** until runners
  are separable.


#### R10.6 — Self-test hygiene

* Fix wrong runner names, stale “component-tests” banners, Pantheios-named
  cases inside **xTests** unit tests.


### R11 — Util / xTras


#### R11.1 — xTests xTras packaging

* **D6:** `temp_file` / `temp_directory` (and kin) as a “set of xTests xTras”,
  preferably separately installable component.


#### R11.2 — Header independence goal

* Ideally usable without depending on **xtests.h** or **stlsoft.h**; record
  if infeasible and document the minimum deps.


#### R11.3 — Install as first-class public surface

* Prefer `PUBLIC_HEADER` (or equivalent package export), not directory-dump
  leftovers.


#### R11.4 — Example hygiene

* `temp_file` / `temp_directory` None examples must not pollute the tree
  (capture-then-remove pattern).


### R12 — Documentation and attractiveness


#### R12.1 — EXAMPLES.md

* Add top-level **EXAMPLES.md**; expand examples significantly.


#### R12.2 — README voice

* Retire apologetic / self-deprecating tagline tone; own the niche.


#### R12.3 — COMPONENTS.md + terse map

* Keep README short map → **COMPONENTS.md**; terse-api mapping first-class;
* FAQ/README link terse section.


#### R12.4 — NEWS interdependency policy

* Tier A: interleave notable **STLSoft** floor/releases into **xTests** NEWS
  (do not copy full chronology);
* Do not fan **xTests** releases into every consumer NEWS;
* Do not put afferent consumers into upstream **STLSoft** NEWS.


#### R12.5 — Doxygen / online API

* Param-level depth via Doxygen when available online; sync
  `PROJECT_NUMBER` with releases.


### R13 — Packaging, CI, and hygiene


#### R13.1 — Language-standard CI matrix

* Automated matrix for combinations of C and C++ language standards.


#### R13.2 — CI push-branch set

* Exactly freelibs canonical seven; never `main`.


#### R13.3 — STLSoft bootstrap semantics

* Documented product behaviour: configure/install STLSoft with testing OFF →
  build **xTests** → reconfigure STLSoft with testing ON when needed.
* Keep `xTests::core` PUBLIC→STLSoft correct while public headers need it;
  C opt-out (**R6.2**) must remain consistent with export rules.


#### R13.4 — Version / CHANGES / header drift

* Keep `_XTESTS_VER` / `_ALPHABETA`, **CHANGES.md**, **NEWS.md**, **Doxyfile**
  aligned per release.


#### R13.5 — Retire stale CMake aliases

* e.g. old `xTests::xTests.core` consumer aliases where practical.


#### R13.6 — install-sis-deps gold

* Remain the reference composite action; extend for **woad** when **R8.3**
  lands.


### R14 — Flexibility and type enforcement


#### R14.1 — Compile-time `bool` enforcement (C++)

* Mechanism so Boolean assertion expressions are genuinely `bool` (no silent
  collapse from `int`, etc.).


#### R14.2 — Flexibility extension mechanism (investigation)

* Investigate ways to fix or obviate string-access-shim issues **and/or**
  devise a new or co-working flexibility extension mechanism.
* If devised, invaluable for **Pantheios** and **FastFormat**.
* Tracked as investigation inside the catalogue; heavy lifting of SAS/MinGW
  two-phase lore is **RX.1** (separate initiative).


### R15 — Competitive feature review


#### R15.1 — Survey popular C unit-test libraries

* Ensure **xTests** provides their good features and more — without abandoning
  explicit-registration identity.
* Feed gaps back into this catalogue as new `R*` items.


### RX — Parallel / external initiatives


#### RX.1 — SAS / MinGW two-phase lookup (separate SIS initiative)

* **D5:** not a revamp gate.
* Multibyte equality / `sas_to_string_m` GCC/MinGW two-phase lookup;
  unblocks Pantheios `test.unit.bec.COMErrorObject` on MinGW.
* Remains on **KNOWN_ISSUES.md** / **TODO.md** until the separate initiative
  lands; cross-link only.


#### RX.2 — STLSoft path-classify readiness

* **xTests** **R3.4** / **R6.5** depend on STLSoft path-classify C API fixes
  and extensions — track as an STLSoft deliverable with an **xTests**
  consumption item.


#### RX.3 — STLSoft C cmdline slice parser

* **R6.4** may require new STLSoft work; track as STLSoft deliverable +
  **xTests** consumption.


## Branch absorption

| Remote branch | Catalogue |
| --- | --- |
| `remotes/ss/fix-TEST_MS_EQ_N` | **R0.1** |
| `remotes/mwsis/null-ptr` | **R0.2** |
| `remotes/mwsis/start-runner-__FILE__` | **R0.3** |


## Blast radius

Approximately **750** source files in **~18** trees include `xtests/xtests.h`
or `xtests/terse-api.h` (order-of-magnitude from review 1: STLSoft, Pantheios,
FastFormat, CLASP, collect, cstring, recls, Diagnosticism, libpath, UNIXem,
…). Any redesign must be additive or shimmed at the macro level (D1).


## How to use this document

* Add or split items here when scope grows; give each a stable `R*` id.
* Mirror short checklist lines in [**TODO.md**](../TODO.md).
* Update stage status only in the umbrella programme document unless an item
  is completed and struck in **TODO.md**.
* Do not treat chat transcripts as superseding this file after the Updated
  date; amend this file instead.


<!-- ########################### end of file ########################### -->
