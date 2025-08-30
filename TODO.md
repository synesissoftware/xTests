# xTests - TODO list <!-- omit in toc -->


* [ ] support for `“--list”` flag;
* [ ] support for named test case(s);
* [ ] support for `“—-timings”` flag;
* [ ] support for `“—-leaks”` flag;
* [ ] verbosity level 6 is to show all cases as they are executed, including successful results;
* [ ] `_Generic` to select type(s) in API macros;
* [ ] wide-character testing and compiler-specific handling of `“%C”`;
* [ ] each case should have access to a FILE* variable that is like stderr, but contents only printed when case fails;
* [ ] allow `TEST_INT_EQ(0, stlsoft::ss_uint32_t(1))` such that the comparison works without needing to specify u suffix;;
* [ ] refactor internally params { file+line+function } into a structure;
* [ ] internal printf translates `%zu` transparently for those (older) standard libraries that do not support;
* [x] summary should list #cases that failed/succeeded - CHECK THIS - ❔;
* [ ] C: integer equal etc should produce message that logs both exp and act, like **BDUT**;
* [ ] refactor out default reporter into separate implementation file;
* [ ] remove most/all static_cast in implementation files;
* [ ] wide-character impl/tests on **Windows** (and maybe elide when on **UNIX**, or at least without full C++20 support);
* [ ] change `uint32_t` type(s)??;
* [ ] execution context;
* [ ] apply Visitor and have custom outputs;
* [x] coloured console output, for `"SUCCESS"` and `"FAILURE"` reports - ✅;
* [x] enhance C-form of macros using `_Generic` - this provided as of version 0.24.0 - ✅;
* [x] simplified (shorter) macros, via opt-in header(s) - ✅;
* [x] ensuring different verbosity levels handled appropriately, in summary and expanded form(s) - ✅;
* [x] **CMake** build setup should be able to infer **STLSoft** if available via a **CMake** find mechanism  (e.g. `find_package()`) - this provided as of version 0.20.5 - ✅;


<!-- ########################### end of file ########################### -->


