# xTests - Known Issues <!-- omit in toc -->


## xTests 0.x Known Issues


* Multibyte string-equality helpers (`XTESTS_TEST_MULTIBYTE_STRING_EQUAL` / `sas_to_string_m`) may fail to find string-access shims (e.g. `c_str_data_a`) declared **after** **xtests.h** is included, under GCC/MinGW two-phase lookup; this blocks some **Pantheios** MinGW tests (e.g. **test.unit.bec.COMErrorObject**);
* Wide-character comparison / reporting coverage is incomplete relative to the multibyte path (including compiler-specific handling of `"%C"`, and fuller Windows coverage);


<!-- ########################### end of file ########################### -->
