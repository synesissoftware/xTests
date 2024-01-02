# xTests - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/xTests/issues)
it will be used to create one.

- [Q1: "How do I build xTests?"](#q1-how-do-i-build-xtests)
- [Q2: "Does xTests have its own unit-tests?"](#q2-does-xtests-have-its-own-unit-tests)
- [Q3: "Why are the macros so verbose?"](#q3-why-are-the-macros-so-verbose)


# FAQs: <!-- omit in toc -->

## Q1: "How do I build xTests?"

See instructions in [INSTALL.md](./INSTALL.md).

## Q2: "Does xTests have its own unit-tests?"

Yes, but because it is a unit-test library itself, those tests failed deliberately in order to illustrate the outputs given when you use **xTests** in your own work.

## Q3: "Why are the macros so verbose?"

Because **xTests** is deliberately targeted at both C and C++. When the library was created there weren't that many unit-test libraries available for C++, and there were many fewer available that supported C.

If you are starting a new project that is entirely C++, we recommend that you instead use a more sophisticated and full-featured library, such as [**Catch2**](https://github.com/catchorg/Catch2).


<!-- ########################### end of file ########################### -->

